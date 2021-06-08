#include "ir-gen/ir-gen.hpp"

#include <llvm/IR/LegacyPassManager.h>
#include <llvm/IR/IRPrintingPasses.h>
#include <llvm/Support/raw_ostream.h>
#include <llvm/IR/Value.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/Module.h>

#include "ast/ast.hpp"
#include "ir-gen/type-system.hpp"
#include "ir-gen/symbol-table.hpp"

using namespace llvm;
using namespace std;


llvm::Module * IrGenVisitor::GetModule(){
  return module_;
}

// unfinished function
void IrGenVisitor::VisitImplicit(DeclNode *decl_node) {
  cout << "[DeclNode]" << endl;
}

void IrGenVisitor::VisitImplicit(FuncCallExpNode *func_call_exp_node) {
  cout << "[FuncCallExpNode]" << endl; 
  cout << func_call_exp_node->ident_ << endl;
  //auto formatVal = builder_.CreateGlobalStringPtr("hello, world", "string");
  vector<Value*> callArgs;
  //callArgs.push_back(formatVal);
  builder_.CreateCall(symbol_table_.GetPreDefinedFunction(func_call_exp_node->ident_), callArgs);
}

void IrGenVisitor::VisitImplicit(FuncDefNode *func_def_node) {
  cout << "[FuncDefNode]" << endl;
  cout << func_def_node->func_ident_ << endl;
  if (func_def_node->func_ident_.compare("main") == 0){
    auto mainBlock = llvm::BasicBlock::Create(llvm_context_, "entry", symbol_table_.GetPreDefinedFunction(func_def_node->func_ident_));
    builder_.SetInsertPoint(mainBlock);
  }

  Visit(func_def_node->block_);
  /*
  if (func_call_exp_node->func_ident_.compare("printf") == 0 ||
      func_call_exp_node->func_ident_.compare("scanf") == 0  ||
      func_call_exp_node->func_ident_.compare("main") == 0 ) {
    
    std::vector<llvm::Type*> args_of_printf;
    args_of_printf.push_back(llvm::Type::getInt8PtrTy(llvm_context_));
    llvm::FunctionType *type_of_printf = llvm::FunctionType::get(
        llvm::Type::getInt32Ty(llvm_context_),
        args_of_printf,
        true);
    llvm:Function *printf_ = llvm::Function::Create(type_of_printf,
                              llvm::GlobalValue::ExternalLinkage,
                              func_call_,
                              module_);
    printf_->setCallingConv(llvm::CallingConv::C);

    //auto formatVal = builder_.CreateGlobalStringPtr("hello, world");
    //vector<Value*> callArgs;
    //callArgs.push_back(formatVal);
    //builder_.CreateCall(printf_, callArgs);
  }
  */
}
void IrGenVisitor::VisitImplicit(BinaryExpNode *binary_exp_node) {
  cout << "[BinaryExpNode]" << endl;
}
void IrGenVisitor::VisitImplicit(UnaryExpNode *unary_exp_node) {
  cout << "[UnaryExpNode]" << endl;
}
void IrGenVisitor::VisitImplicit(InitValNode *lval_primary_exp_node) {
  cout << "[InitValNode]" << endl;
}


// generate IR for error node
// no code at all, just set error info
void IrGenVisitor::VisitImplicit(ErrorNode *node) {
  current_if_error_ = true;
}

// generate code for "leaves" of expression
void IrGenVisitor::VisitImplicit(ValuePrimaryExpNode *node) {
  switch (node->node_type_) {
    case (NodeType::STRING_PRIMARY_EXP) : {
      current_value_ = builder_.CreateGlobalString(node->string_value_, 
                                                   "string");
      current_type_.basic_type_ = TypeCheckBasicType::STRING;
      break;
    }
    case (NodeType::INT_PRIMARY_EXP) : {
      current_value_ = ConstantInt::get(Type::getInt32Ty(llvm_context_),
                                        node->int_value_,
                                        true);
      current_type_.basic_type_ = TypeCheckBasicType::INT;
      break;
    }
    case (NodeType::FLOAT_PRIMARY_EXP) : {
      current_value_ = ConstantFP::get(Type::getFloatTy(llvm_context_),
                                       node->float_value_);
      current_type_.basic_type_ = TypeCheckBasicType::FLOAT;
      break;
    }
    case (NodeType::CHAR_PRIMARY_EXP) : {
      current_value_ = ConstantInt::get(Type::getInt8Ty(llvm_context_),
                                        node->char_value_,
                                        false);
      current_type_.basic_type_ = TypeCheckBasicType::CHAR;
      break;
    }
  }
  current_if_const_ = true;
  current_if_error_ = false;  
}

// generate code for left value, such as a, b[1] ...
void IrGenVisitor::VisitImplicit(LValPrimaryExpNode *node) {
  current_if_const_ = false;
  // find destination
  // if local does not exist
  if (!symbol_table_.IfExistLocal(node->ident_)) {
    current_if_error_ = true;
    return;
  }
  // check type consistency
  TypeCheckType var_type;
  symbol_table_.GetLocalVariableType(node->ident_, var_type);
  int var_type_dimension_list_size = var_type.array_dimension_list_.size(),
      index_list_size = node->index_list_.size();
  if (var_type_dimension_list_size == index_list_size) {
  // TODO : finish it
  }
}

// generate code for return statement
void IrGenVisitor::VisitImplicit(ReturnStmtNode *node) {
  current_if_error_ = false;
  if (node->exp_ != nullptr) {
    Visit(node->exp_);
  }
  else
    current_value_ = nullptr;
  // set current block's return value
  builder_.CreateRet(current_value_);
}

// generate code for block "{}"
void IrGenVisitor::VisitImplicit(BlockNode *node) {
  // create new scope
  symbol_table_.PushScope(); // virtual BasicBlock
  // visit child
  if (node->decl_stmt_list_.empty()) { // empty block
    current_if_error_ = false;
  } else {
    bool if_error = false;
    for (auto itr : node->decl_stmt_list_) {
      Visit(itr);
      if (current_if_error_)
        if_error = true;
    }
    current_if_error_ = if_error; // if one error, then return error
  }
  // pop current scope
  symbol_table_.PopScope();
}

// ident nodes are temporary node generated in scanning
// a correct ast will not contain it
void IrGenVisitor::VisitImplicit(IdentNode *node) {
  // something wrong with generating ast
  assert(0);
}

// root node
void IrGenVisitor::VisitImplicit(RootNode *node) {
  // generate IR of children
  bool if_error = false;
  for (auto itr : node->decl_funcdef_list_) {
    Visit(itr);
    if (current_if_error_)
      if_error = true;
  }
  if (if_error)
    return;
  // call passmanager
  legacy::PassManager pass_manager;
  pass_manager.add(createPrintModulePass(outs()));
  pass_manager.run(*module_);
  // TODO : optimization pass
}

void IrGenVisitor::VisitImplicit(AssignStmtNode *node) {
  // test error
  bool if_error = false;
  // left value
  Visit(node->lval_);
  Value *lval_value = current_value_;
  TypeCheckBasicType lval_type = current_type_.basic_type_;
  if (current_if_error_)
    if_error = true;
  // TODO : finish error check
  // if if_error == true, error has been reported
  // in Visit(node->lval_), so we do not need to 
  // report error here
  if (current_if_const_ && !if_error)
    cout << "cant assign to const variable" << endl;
  // right exp_
  Visit(node->rexp_);
  Value *rexp_value = current_value_;
  if (current_if_error_)
    if_error = true;
  if (if_error)
    return;
  // do type check
  // no such type conversion
  if (type_system_.GetAssignTypeResult(lval_type, current_type_.basic_type_) == TypeCheckBasicType::ERROR) {
    cout << "no type conversion for "
         << TypeSystem::BasicTypeToString(lval_type)
         << " "
         << TypeSystem::BasicTypeToString(current_type_.basic_type_)
         << endl;
  } else {
    rexp_value = type_system_.Cast(rexp_value,
                                   lval_value->getType(),
                                   builder_.GetInsertBlock());
  }
  // do assignment
  builder_.CreateStore(rexp_value, lval_value);
}

void IrGenVisitor::VisitImplicit(IfStmtNode *node) {
  bool if_error = false;
  // cond_
  Visit(node->cond_);
  if (current_if_error_) {
    if_error = true;
    // check error of the if_stmt_ and else_stmt_
    Visit(node->if_stmt_);
    if (node->else_stmt_ != nullptr)
      Visit(node->else_stmt_);
    current_if_error_ = true;
    return;
  }
  // if no error for cond_, check cond_value's type
  Value *cond_value = current_value_;
  if (cond_value->getType() != Type::getInt1Ty(llvm_context_)) {
    cout << "condition error!" << endl;
    // check error of the if_stmt_ and else_stmt_
    Visit(node->if_stmt_);
    if (node->else_stmt_ != nullptr)
      Visit(node->else_stmt_);
    current_if_error_ = true;
    return;
  }
  // if no error for cond_'s type
  Function *function_belong = builder_.GetInsertBlock()->getParent();
  BasicBlock *true_block = BasicBlock::Create(llvm_context_, "true", function_belong),
             *false_block = BasicBlock::Create(llvm_context_, "false"),
             *cont_block = BasicBlock::Create(llvm_context_, "cont", function_belong);
  // connect blocks
  // TODO : error check
  if (node->else_stmt_ != nullptr) {
    builder_.CreateCondBr(cond_value, true_block, false_block);
  } else {
    builder_.CreateCondBr(cond_value, true_block, cont_block);
  }
  // deal with true block
  builder_.SetInsertPoint(true_block);
  symbol_table_.PushScope();
  Visit(node->if_stmt_);
  symbol_table_.PopScope();
  // deal with false block
  if (node->else_stmt_ != nullptr) {
    function_belong->getBasicBlockList().push_back(false_block);
    builder_.SetInsertPoint(false_block);
    symbol_table_.PushScope();
    Visit(node->else_stmt_);
    symbol_table_.PopScope();
  }
  // merge
  builder_.CreateBr(cont_block);
  builder_.SetInsertPoint(cont_block);
}

void IrGenVisitor::VisitImplicit(WhileStmtNode *node) {
  // TODO : error check
  Function *function_belog = builder_.GetInsertBlock()->getParent();
  BasicBlock *cond_block = BasicBlock::Create(llvm_context_, "cond", function_belog),
             *body_block = BasicBlock::Create(llvm_context_, "body", function_belog),
             *cont_block = BasicBlock::Create(llvm_context_, "cont", function_belog);
  current_cond_block_list_.push_back(cond_block);
  current_cont_block_list_.push_back(cont_block);
  // get cond value
  symbol_table_.PushScope();
  Visit(node->cond_);
  symbol_table_.PopScope();
  Value *cond_value = current_value_;
  // connect origin block to cond_block
  builder_.CreateBr(cond_block);
  // connect cond_block to body_block and cont_block
  builder_.SetInsertPoint(cond_block);
  builder_.CreateCondBr(cond_value, body_block, cont_block);
  // build body_block, connect to cond_block
  builder_.SetInsertPoint(body_block);
  symbol_table_.PushScope();
  Visit(node->stmt_);
  symbol_table_.PopScope();
  builder_.CreateBr(cond_block);
  builder_.SetInsertPoint(cont_block);
  current_cond_block_list_.pop_back();
  current_cont_block_list_.pop_back();
}

void IrGenVisitor::VisitImplicit(ContinueStmtNode *node) {
  // TODO : error check
  builder_.CreateBr(current_cond_block_list_.back());
}

void IrGenVisitor::VisitImplicit(BreakStmtNode *node) {
  // TODO : error check
  builder_.CreateBr(current_cont_block_list_.back());
}

