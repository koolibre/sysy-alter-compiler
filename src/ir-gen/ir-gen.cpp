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
  BasicBlock *new_scope = BasicBlock::Create(llvm_context_, "new_scope");
  symbol_table_.PushScope(new_scope);
  builder_.SetInsertPoint(new_scope);
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
  // restore scope
  builder_.SetInsertPoint(symbol_table_.GetScopeBasicBlock());
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
                                   symbol_table_.GetScopeBasicBlock());
  }
  // do assignment
  builder_.CreateStore(rexp_value, lval_value);
}

void IrGenVisitor::VisitImplicit(IfStmtNode *node) {
  bool if_error = false;
  // cond_
  Visit(node->cond_);
  if (current_if_error_)
    if_error = true;
  Value *cond_value = current_value_;
}