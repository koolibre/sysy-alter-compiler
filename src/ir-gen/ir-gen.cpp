#include "ir-gen/ir-gen.hpp"

#include <llvm/IR/LegacyPassManager.h>
#include <llvm/IR/IRPrintingPasses.h>
#include <llvm/Support/raw_ostream.h>
#include <llvm/IR/Value.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/Module.h>
#include <regex>

#include "ast/ast.hpp"
#include "ir-gen/type-system.hpp"
#include "ir-gen/symbol-table.hpp"

using namespace llvm;
using namespace std;

llvm::Module *IrGenVisitor::GetModule()
{
  return module_;
}

// unfinished function
void IrGenVisitor::VisitImplicit(DeclNode *decl_node)
{
  cout << "[DeclNode]" << endl;
  // for (auto itr : decl_node->init_val_list_){
  //   Visit(itr);
  //   switch (decl_node->basic_type_) {
  //     case (BasicType::INT) : {
  //       TypeCheckType type(TypeCheckBasicType::INT);
  //       symbol_table_.AddLocalVariable(decl_node->ident_list_.front(), current_value_, type);
  //       break;
  //     }
  //     case (BasicType::FLOAT) : {
  //       TypeCheckType type(TypeCheckBasicType::FLOAT);
  //       symbol_table_.AddLocalVariable(decl_node->ident_list_.front(), current_value_, type);
  //       break;
  //     }
  //   }
  // }
  auto iter_dim = decl_node->array_dimension_list_list_.begin();
  auto iter_id = decl_node->ident_list_.begin();
  auto iter_init = decl_node->init_val_list_.begin();
  BasicType basic_type = decl_node->basic_type_;
  cout << "basic_type:" << int(basic_type) << endl;
  bool use_global = symbol_table_.IsInGlobalScope();
  for (; iter_id != decl_node->ident_list_.end(); iter_dim++, iter_id++, iter_init++)
  {
    std::string param_name = *iter_id; // name of this param
    if (symbol_table_.IfExistLocal(param_name))
    {
      // TODO: raise error: this var already exists
    }
    std::vector<int> param_dims;
    int param_full_dims = 1;
    bool is_array = false;
    std::list<Node *> param_dims_o = *(*iter_dim);
    for (auto iter_param_dims : param_dims_o)
    {
      is_array = true;
      // this block won't be executed if the decl isnot array, and thus the param_full_dims will be 1
      Visit(iter_param_dims);
      llvm::Value *v_param_dim = current_value_;
      cout << "b>-";
      // param_full_dims = 4;
      // param_dims.push_back(4);
      // if (llvm::ConstantInt *dim = llvm::dyn_cast<llvm::ConstantInt>(v_param_dim))
      if (current_if_const_)
      {
        cout << "a>-";
        // v_param_dim indeed is a ConstantInt, we can use dim here
        // if (dim->getBitWidth() <= 32)
        // {
        // int dim_value = dim->getSExtValue();
        int dim_value = int(current_const_value_);
        param_dims.push_back(dim_value);
        param_full_dims *= dim_value;
        cout << "-<" << dim_value << ">-";
        // }
      }
      else
      {
        // ! v_param_dim is not actually a ConstantInt
        // TODO: raise error
        // here, there's 2 kinds of error:
        //  1. the v_param_dim is a constant, but not int. eg. int a[3.1];
        //  2. the v_param_dim is not a constant. eg. int a[random()];
      }
    } //end of deciding dims

    // param_full_dims = 1 if not decl_is_array else size
    // ! array size may be 1
    llvm::Type *param_type = nullptr;
    switch (basic_type)
    {
    case BasicType::INT:
    {
      param_type = llvm::Type::getInt32Ty(llvm_context_);
      break;
    }
    case BasicType::FLOAT:
    {
      param_type = llvm::Type::getFloatTy(llvm_context_);
      break;
    }
    case BasicType::CHAR:
    {
      param_type = llvm::Type::getInt8Ty(llvm_context_);
      break;
    }
    default:
    {
      //TODO: raise error
    }
    }
    TypeCheckType *param_type_check_type = nullptr;
    llvm::Value *param_inst = nullptr;
    //llvm::Value* context.builder.CreateAlloca(type)
    if (is_array)
    {
      llvm::ArrayType *param_arr_type = llvm::ArrayType::get(param_type, param_full_dims);
      // llvm::Value *param_dim_Value = llvm::ConstantInt::get(Type::getInt32Ty(llvm_context_), param_full_dims, true);
      if (use_global)
      {
        llvm::GlobalVariable *global_var_value = new GlobalVariable(/*Module=*/*module_,
                                                                    /*Type=*/param_arr_type,
                                                                    /*isConstant=*/false,
                                                                    /*Linkage=*/GlobalValue::CommonLinkage,
                                                                    /*Initializer=*/nullptr,
                                                                    /*Name=*/"global_var");
        global_var_value->setAlignment(2);
        llvm::Constant *init_val = nullptr;
        switch (basic_type)
        {
        case BasicType::INT:
        {
          init_val = llvm::ConstantInt::get(llvm::Type::getInt32Ty(llvm_context_), 0);
          break;
        }
        case BasicType::FLOAT:
        {
          init_val = llvm::ConstantInt::get(llvm::Type::getFloatTy(llvm_context_), 0.0);
          break;
        }
        case BasicType::CHAR:
        {
          init_val = llvm::ConstantInt::get(llvm::Type::getInt8Ty(llvm_context_), 0);
          break;
        }
        }
        //Global Variable Definitions
        global_var_value->setInitializer(init_val);
        param_inst = global_var_value;
      }
      else
      {
        param_inst = builder_.CreateAlloca(param_arr_type, llvm::ConstantInt::get(Type::getInt32Ty(llvm_context_), 1, true), "decl_arr");
      }
      std::list<int> param_dims_list(param_dims.begin(), param_dims.end());
      switch (basic_type)
      {
      case BasicType::INT:
      {
        param_type_check_type = new TypeCheckType(TypeCheckBasicType::INT_ARRAY, param_dims_list);
        // cout << "basic type: int[]" << endl;
        break;
      }
      case BasicType::FLOAT:
      {
        param_type_check_type = new TypeCheckType(TypeCheckBasicType::FLOAT_ARRAY, param_dims_list);
        break;
      }
      case BasicType::CHAR:
      {
        param_type_check_type = new TypeCheckType(TypeCheckBasicType::CHAR_ARRAY, param_dims_list);
        break;
      }
      }
    }
    else
    {
      if (use_global)
      {
        llvm::GlobalVariable *global_var_value = new GlobalVariable(/*Module=*/*module_,
                                                                    /*Type=*/param_type,
                                                                    /*isConstant=*/false,
                                                                    /*Linkage=*/GlobalValue::CommonLinkage,
                                                                    /*Initializer=*/nullptr,
                                                                    /*Name=*/"global_var");
        global_var_value->setAlignment(2);

        // if (*iter_init != nullptr and not(*iter_init)->CheckNodeType(NodeType::INIT_VAL))
        // {
        //   Visit(*iter_init);
        //   if (current_if_const_)
        //   {
        //Constant Definitions
        // ConstantPointerNull* const_ptr_2 = ConstantPointerNull::get(PointerTy_0);
        llvm::Constant *init_val = nullptr;
        switch (basic_type)
        {
        case BasicType::INT:
        {
          init_val = llvm::ConstantInt::get(llvm::Type::getInt32Ty(llvm_context_), 0);
          break;
        }
        case BasicType::FLOAT:
        {
          init_val = llvm::ConstantInt::get(llvm::Type::getFloatTy(llvm_context_), 0.0);
          break;
        }
        case BasicType::CHAR:
        {
          init_val = llvm::ConstantInt::get(llvm::Type::getInt8Ty(llvm_context_), 0);
          break;
        }
        }
        //Global Variable Definitions
        global_var_value->setInitializer(init_val);
        //   }
        // }
        param_inst = global_var_value;
      }
      else
      {
        param_inst = builder_.CreateAlloca(param_type);
      }
      // VOID and ERROR type shall not appear as the type of a declared var
      // // ? what is the different from **STRING** and CHAR_ARRAY type?
      // the different between STRING and CHAR_ARRAY is that the STRING type means a string literal
      // So we'll not use the STRING type here
      switch (basic_type)
      {
      case BasicType::INT:
      {
        param_type_check_type = new TypeCheckType(TypeCheckBasicType::INT);
        // cout << "basic type: int" << endl;
        // cout << "int(param_type_check_type->basic_type_) = " << int(param_type_check_type->basic_type_) << endl;
        break;
      }
      case BasicType::FLOAT:
      {
        param_type_check_type = new TypeCheckType(TypeCheckBasicType::FLOAT);
        break;
      }
      case BasicType::CHAR:
      {
        param_type_check_type = new TypeCheckType(TypeCheckBasicType::CHAR);
        break;
      }
      }
      // cout << "int(param_type_check_type->basic_type_) = " << int(param_type_check_type->basic_type_) << endl;
    }
    // cout << "int(param_type_check_type->basic_type_) = " << int(param_type_check_type->basic_type_) << endl;
    // printf("%p", param_type_check_type);
    symbol_table_.AddLocalVariable(param_name, param_inst, *param_type_check_type); // add to symbol table
    if (*iter_init != nullptr and not(*iter_init)->CheckNodeType(NodeType::INIT_VAL))
    {
      // cout << "b " << int(param_type_check_type->basic_type_) << endl;
      Visit(*iter_init);
      Value *rexp_value = current_value_;
      bool if_error = false;
      if (current_if_error_)
      {
        if_error = true;
      }
      if (if_error)
      {
        return; // ?
        // TODO: raise error
      }
      // do type check
      // no such type conversion
      TypeCheckBasicType lval_type = param_type_check_type->basic_type_;
      if (type_system_.GetAssignTypeResult(lval_type, current_type_.basic_type_) == TypeCheckBasicType::ERROR)
      {
        cout << "no type conversion for "
             << TypeSystem::BasicTypeToString(lval_type)
             << " "
             << TypeSystem::BasicTypeToString(current_type_.basic_type_)
             << endl;
      }
      else
      {
        rexp_value = type_system_.Cast(rexp_value,
                                       param_inst->getType(),
                                       builder_.GetInsertBlock());
      }
      // do assignment
      auto load_value_ = builder_.CreateLoad(rexp_value);
      builder_.CreateStore(load_value_, param_inst);
      cout << "d" << endl;
    }

    cout << "decl of param " << param_name << " finished.";
    if (is_array)
    {
      cout << "<" << param_full_dims << ">";
      cout << "[";
      for (auto it : param_dims)
      {
        cout << it << ", ";
      }
      cout << "]";
    }
    cout << endl;
  }
}

void IrGenVisitor::VisitImplicit(FuncCallExpNode *func_call_exp_node)
{
  cout << "[FuncCallExpNode]" << func_call_exp_node->ident_ << endl;

  // call args
  std::vector<llvm::Value *> callArgs;
  for (auto itr : func_call_exp_node->rparam_array_)
  {
    Visit(itr);
    if ((int)current_type_.basic_type_ == (int)TypeCheckBasicType::STRING)
    {
      callArgs.push_back(current_value_);
    }
    else if ((int)current_type_.basic_type_ == (int)TypeCheckBasicType::FLOAT)
    {
      auto load_value_ = builder_.CreateLoad(current_value_);
      auto value_ = builder_.CreateFPExt(load_value_, llvm::Type::getDoubleTy(llvm_context_));
      callArgs.push_back(value_);
    }
    else if ((int)current_type_.basic_type_ == (int)TypeCheckBasicType::POINTER)
    {
      callArgs.push_back(current_value_);
    }
    else
    {
      auto load_value_ = builder_.CreateLoad(current_value_);
      callArgs.push_back(load_value_);
    }
  }

  if (func_call_exp_node->ident_.compare("printf") == 0 || func_call_exp_node->ident_.compare("scanf") == 0)
  {
    std::vector<llvm::Type *> args_of_func;
    args_of_func.push_back(llvm::Type::getInt8PtrTy(llvm_context_));

    // true arg means params can have ...
    llvm::FunctionType *runtimeFunctionType = llvm::FunctionType::get(
        llvm::Type::getInt32Ty(llvm_context_),
        args_of_func,
        true);
    llvm::Function *func_ = llvm::Function::Create(runtimeFunctionType,
                                                   llvm::GlobalValue::ExternalLinkage,
                                                   func_call_exp_node->ident_,
                                                   module_);
    func_->setCallingConv(llvm::CallingConv::C);
    builder_.CreateCall(module_->getFunction(func_call_exp_node->ident_), callArgs);
  }
  else
  {
    builder_.CreateCall(module_->getFunction(func_call_exp_node->ident_), callArgs);
  }
}

void IrGenVisitor::VisitImplicit(FuncDefNode *func_def_node)
{
  cout << "[FuncDefNode]" << func_def_node->func_ident_ << endl;

  std::vector<llvm::Type *> args_of_func;
  llvm::FunctionType *type_of_func = llvm::FunctionType::get(
      llvm::Type::getVoidTy(llvm_context_),
      llvm::makeArrayRef(args_of_func),
      false);

  llvm::Function *func_ = llvm::Function::Create(type_of_func,
                                                 llvm::GlobalValue::ExternalLinkage,
                                                 func_def_node->func_ident_,
                                                 module_);
  func_->setCallingConv(llvm::CallingConv::C);
  //symbol_table_.AddFunction(func_def_node->func_ident_, func_);
  auto funcBlock = llvm::BasicBlock::Create(llvm_context_, func_def_node->func_ident_, module_->getFunction(func_def_node->func_ident_));

  builder_.SetInsertPoint(funcBlock);
  symbol_table_.PushScope();
  Visit(func_def_node->block_);
  symbol_table_.PopScope();
}

void IrGenVisitor::VisitImplicit(BinaryExpNode *binary_exp_node)
{
  cout << "[BinaryExpNode]" << endl;
  // cout << "op:" << int(binary_exp_node->binary_op_type_) << endl;
  // if (binary_exp_node->lexp_ != nullptr and binary_exp_node->rexp_ != nullptr)
  //   cout << "left node:" << int(binary_exp_node->lexp_->node_type_) << " right node:" << int(binary_exp_node->rexp_->node_type_) << endl;

  Visit(binary_exp_node->lexp_);
  bool left_is_const = current_if_const_;
  double left_const_value = current_const_value_;
  TypeCheckBasicType rightVariableType = TypeCheckBasicType::VOID;
  TypeCheckBasicType leftVariableType = TypeCheckBasicType::VOID;
  Value *leftVariable;
  if (dynamic_cast<Node *>(binary_exp_node->lexp_)->CheckNodeType(NodeType::BINARY_EXP) ||
      dynamic_cast<Node *>(binary_exp_node->lexp_)->CheckNodeType(NodeType::UNARY_EXP))
  {
    leftVariable = current_value_;
    leftVariableType = current_type_.basic_type_;
    switch(leftVariableType){
      case (TypeCheckBasicType::INT_ARRAY) : {leftVariableType = TypeCheckBasicType::INT; break;}
      case (TypeCheckBasicType::FLOAT_ARRAY) : {leftVariableType = TypeCheckBasicType::FLOAT; break;}
      case (TypeCheckBasicType::CHAR_ARRAY) : {leftVariableType = TypeCheckBasicType::CHAR; break;}
    }
  }
  else if (((int)(current_type_.basic_type_) == (int)TypeCheckBasicType::INT_ARRAY or (int)(current_type_.basic_type_) == (int)TypeCheckBasicType::FLOAT_ARRAY or (int)(current_type_.basic_type_) == (int)TypeCheckBasicType::CHAR_ARRAY))
  {
    cout << "loading array ref for left" << endl;
    leftVariable = builder_.CreateAlignedLoad(current_value_, 2);
    switch (current_type_.basic_type_)
    {
    case TypeCheckBasicType::INT_ARRAY:
    {
      leftVariableType = TypeCheckBasicType::INT;
      break;
    }
    case TypeCheckBasicType::FLOAT_ARRAY:
    {
      leftVariableType = TypeCheckBasicType::FLOAT;
      break;
    }
    case TypeCheckBasicType::CHAR_ARRAY:
    {
      leftVariableType = TypeCheckBasicType::CHAR;
      break;
    }
    }
  }
  else
  {
    leftVariable = builder_.CreateLoad(current_value_);
    leftVariableType = current_type_.basic_type_;
  }

  Visit(binary_exp_node->rexp_);
  bool right_is_const = current_if_const_;
  double right_const_value = current_const_value_;
  Value *rightVariable;
  if (dynamic_cast<Node *>(binary_exp_node->rexp_)->CheckNodeType(NodeType::BINARY_EXP) ||
      dynamic_cast<Node *>(binary_exp_node->rexp_)->CheckNodeType(NodeType::UNARY_EXP))
  {
    rightVariable = current_value_;
    rightVariableType = current_type_.basic_type_;
    switch(rightVariableType){
      case (TypeCheckBasicType::INT_ARRAY) : {rightVariableType = TypeCheckBasicType::INT; break;}
      case (TypeCheckBasicType::FLOAT_ARRAY) : {rightVariableType = TypeCheckBasicType::FLOAT; break;}
      case (TypeCheckBasicType::CHAR_ARRAY) : {rightVariableType = TypeCheckBasicType::CHAR; break;}
    }
  }
  else if (((int)(current_type_.basic_type_) == (int)TypeCheckBasicType::INT_ARRAY or (int)(current_type_.basic_type_) == (int)TypeCheckBasicType::FLOAT_ARRAY or (int)(current_type_.basic_type_) == (int)TypeCheckBasicType::CHAR_ARRAY))
  {
    cout << "loading array ref for right" << endl;
    rightVariable = builder_.CreateAlignedLoad(current_value_, 2);
    switch (current_type_.basic_type_)
    {
    case TypeCheckBasicType::INT_ARRAY:
    {
      rightVariableType = TypeCheckBasicType::INT;
      break;
    }
    case TypeCheckBasicType::FLOAT_ARRAY:
    {
      rightVariableType = TypeCheckBasicType::FLOAT;
      break;
    }
    case TypeCheckBasicType::CHAR_ARRAY:
    {
      rightVariableType = TypeCheckBasicType::CHAR;
      break;
    }
    }
  }
  else
  {
    rightVariable = builder_.CreateLoad(current_value_);
    rightVariableType = current_type_.basic_type_;
  }

  bool isIntType = ((int)leftVariableType == (int)TypeCheckBasicType::INT and (int)rightVariableType == (int)TypeCheckBasicType::INT);

  if (!isIntType)
  {
    if ((int)leftVariableType == (int)TypeCheckBasicType::INT)
    {
      leftVariable = type_system_.Cast(leftVariable,
                                       rightVariable->getType(),
                                       builder_.GetInsertBlock());
    }
    if ((int)rightVariableType == (int)TypeCheckBasicType::INT)
    {
      rightVariable = type_system_.Cast(rightVariable,
                                        leftVariable->getType(),
                                        builder_.GetInsertBlock());
    }
  }
  cout << "the left and right type:" << int(rightVariable->getType()->getTypeID()) << " & " << int(leftVariable->getType()->getTypeID()) << endl;
  cout << "the binary operator: " << int(binary_exp_node->binary_op_type_) << endl;
  cout << "is int type: " << isIntType << ": " << (int)leftVariableType << " and " << (int)rightVariableType << "." << endl;
  current_if_const_ = left_is_const and right_is_const;
  switch (binary_exp_node->binary_op_type_)
  {
  case (BinaryOpType::MUL):
  {
    Value *mulVal = isIntType ? builder_.CreateMul(leftVariable, rightVariable) : builder_.CreateFMul(leftVariable, rightVariable);
    current_value_ = isIntType ? builder_.CreateFPExt(mulVal, llvm::Type::getInt32Ty(llvm_context_)) : builder_.CreateFPExt(mulVal, llvm::Type::getFloatTy(llvm_context_));
    if (current_if_const_)
    {
      current_const_value_ = right_const_value * left_const_value;
    }
    else
    {
      current_const_value_ = 0.0;
    }
    break;
  }
  case (BinaryOpType::DIV):
  {
    Value *divVal = isIntType ? builder_.CreateSDiv(leftVariable, rightVariable) : builder_.CreateFDiv(leftVariable, rightVariable);
    current_value_ = isIntType ? builder_.CreateFPExt(divVal, llvm::Type::getInt32Ty(llvm_context_)) : builder_.CreateFPExt(divVal, llvm::Type::getFloatTy(llvm_context_));
    if (current_if_const_)
    {
      current_const_value_ = left_const_value / right_const_value;
    }
    else
    {
      current_const_value_ = 0.0;
    }
    break;
  }
  case (BinaryOpType::MOD):
  {
    Value *divVal = isIntType ? builder_.CreateSDiv(leftVariable, rightVariable) : builder_.CreateFDiv(leftVariable, rightVariable);
    Value *mulVal = isIntType ? builder_.CreateMul(rightVariable, divVal) : builder_.CreateFMul(rightVariable, divVal);
    Value *modVal = isIntType ? builder_.CreateSub(leftVariable, mulVal) : builder_.CreateFSub(leftVariable, mulVal);
    current_value_ = isIntType ? builder_.CreateFPExt(modVal, llvm::Type::getInt32Ty(llvm_context_)) : builder_.CreateFPExt(modVal, llvm::Type::getFloatTy(llvm_context_));
    if (current_if_const_)
    {
      current_const_value_ = double(int(left_const_value) % int(right_const_value));
    }
    else
    {
      current_const_value_ = 0.0;
    }
    break;
  }
  case (BinaryOpType::ADD):
  {
    Value *addVal = isIntType ? builder_.CreateAdd(leftVariable, rightVariable) : builder_.CreateFAdd(leftVariable, rightVariable);
    current_value_ = isIntType ? builder_.CreateFPExt(addVal, llvm::Type::getInt32Ty(llvm_context_)) : builder_.CreateFPExt(addVal, llvm::Type::getFloatTy(llvm_context_));
    if (current_if_const_)
    {
      current_const_value_ = right_const_value + left_const_value;
    }
    else
    {
      current_const_value_ = 0.0;
    }
    break;
  }
  case (BinaryOpType::SUB):
  {
    Value *subVal = isIntType ? builder_.CreateSub(leftVariable, rightVariable) : builder_.CreateFSub(leftVariable, rightVariable);
    current_value_ = isIntType ? builder_.CreateFPExt(subVal, llvm::Type::getInt32Ty(llvm_context_)) : builder_.CreateFPExt(subVal, llvm::Type::getFloatTy(llvm_context_));
    if (current_if_const_)
    {
      current_const_value_ = left_const_value - right_const_value;
    }
    else
    {
      current_const_value_ = 0.0;
    }
    break;
  }
  case (BinaryOpType::AND):
  {
    Value *andVal = builder_.CreateAnd(leftVariable, rightVariable);
    current_value_ = builder_.CreateFPExt(andVal, llvm::Type::getInt32Ty(llvm_context_));
    if (current_if_const_)
    {
      current_const_value_ = (left_const_value != 0.0 and right_const_value != 0.0) ? 1.0 : 0.0;
    }
    else
    {
      current_const_value_ = 0.0;
    }
    break;
  }
  case (BinaryOpType::OR):
  {
    Value *orVal = builder_.CreateSub(leftVariable, rightVariable);
    current_value_ = builder_.CreateFPExt(orVal, llvm::Type::getInt32Ty(llvm_context_));
    if (current_if_const_)
    {
      current_const_value_ = (left_const_value != 0.0 or right_const_value != 0.0) ? 1.0 : 0.0;
    }
    else
    {
      current_const_value_ = 0.0;
    }
    break;
  }
  // >
  case (BinaryOpType::GE):
  {
    Value *geVal = isIntType ? builder_.CreateICmpSGT(leftVariable, rightVariable) : builder_.CreateFCmpOGT(leftVariable, rightVariable);
    current_value_ = builder_.CreateFPExt(geVal, llvm::Type::getInt1Ty(llvm_context_));
    if (current_if_const_)
    {
      current_const_value_ = (left_const_value > right_const_value) ? 1.0 : 0.0;
    }
    else
    {
      current_const_value_ = 0.0;
    }
    break;
  }
  // <
  case (BinaryOpType::LE):
  {
    Value *orVal = isIntType ? builder_.CreateICmpULT(leftVariable, rightVariable) : builder_.CreateFCmpOLT(leftVariable, rightVariable);
    current_value_ = builder_.CreateFPExt(orVal, llvm::Type::getInt1Ty(llvm_context_));
    if (current_if_const_)
    {
      current_const_value_ = (left_const_value < right_const_value) ? 1.0 : 0.0;
    }
    else
    {
      current_const_value_ = 0.0;
    }
    break;
  }
  // >=
  case (BinaryOpType::GEEQ):
  {
    Value *orVal = isIntType ? builder_.CreateICmpSGE(leftVariable, rightVariable) : builder_.CreateFCmpOGE(leftVariable, rightVariable);
    current_value_ = builder_.CreateFPExt(orVal, llvm::Type::getInt1Ty(llvm_context_));
    if (current_if_const_)
    {
      current_const_value_ = (left_const_value >= right_const_value) ? 1.0 : 0.0;
    }
    else
    {
      current_const_value_ = 0.0;
    }
    break;
  }
  // <=
  case (BinaryOpType::LEEQ):
  {
    Value *orVal = isIntType ? builder_.CreateICmpSLE(leftVariable, rightVariable) : builder_.CreateFCmpOLE(leftVariable, rightVariable);
    current_value_ = builder_.CreateFPExt(orVal, llvm::Type::getInt1Ty(llvm_context_));
    if (current_if_const_)
    {
      current_const_value_ = (left_const_value <= right_const_value) ? 1.0 : 0.0;
    }
    else
    {
      current_const_value_ = 0.0;
    }
    break;
  }
  // ==
  case (BinaryOpType::EQ):
  {
    Value *orVal = isIntType ? builder_.CreateICmpEQ(leftVariable, rightVariable) : builder_.CreateFCmpOEQ(leftVariable, rightVariable);
    current_value_ = builder_.CreateFPExt(orVal, llvm::Type::getInt1Ty(llvm_context_));
    // ! LahElr: 浮点误差可能性微存
    if (current_if_const_)
    {
      current_const_value_ = (left_const_value == right_const_value) ? 1.0 : 0.0;
    }
    else
    {
      current_const_value_ = 0.0;
    }
    break;
  }
  // !=
  case (BinaryOpType::UNEQ):
  {
    Value *orVal = isIntType ? builder_.CreateICmpNE(leftVariable, rightVariable) : builder_.CreateFCmpONE(leftVariable, rightVariable);
    current_value_ = builder_.CreateFPExt(orVal, llvm::Type::getInt1Ty(llvm_context_));
    if (current_if_const_)
    {
      current_const_value_ = (left_const_value != right_const_value) ? 1.0 : 0.0;
    }
    else
    {
      current_const_value_ = 0.0;
    }
    break;
  }
    //TypeCheckType type(current_type_.basic_type_);
    //symbol_table_.AddLocalVariable(binary_exp_node, current_value_, type);
  }
  //current_type_ = isIntType ? TypeCheckType(TypeCheckBasicType::INT) : TypeCheckType(TypeCheckBasicType::FLOAT);
}

void IrGenVisitor::VisitImplicit(UnaryExpNode *unary_exp_node)
{
  cout << "[UnaryExpNode]" << endl;
  Visit(unary_exp_node->exp_);
  //auto unaryVariable = builder_.CreateLoad(current_value_);
  Value *unaryVariable;
  TypeCheckBasicType unaryVariableType = TypeCheckBasicType::VOID;
  if (dynamic_cast<Node *>(unary_exp_node->exp_)->CheckNodeType(NodeType::BINARY_EXP) ||
      dynamic_cast<Node *>(unary_exp_node->exp_)->CheckNodeType(NodeType::UNARY_EXP))
  {
    unaryVariable = current_value_;
    unaryVariableType = current_type_.basic_type_;
    switch(unaryVariableType){
      case (TypeCheckBasicType::INT_ARRAY) : {unaryVariableType = TypeCheckBasicType::INT; break;}
      case (TypeCheckBasicType::FLOAT_ARRAY) : {unaryVariableType = TypeCheckBasicType::FLOAT; break;}
      case (TypeCheckBasicType::CHAR_ARRAY) : {unaryVariableType = TypeCheckBasicType::CHAR; break;}
    }
  }
  else if (((int)(current_type_.basic_type_) == (int)TypeCheckBasicType::INT_ARRAY or (int)(current_type_.basic_type_) == (int)TypeCheckBasicType::FLOAT_ARRAY or (int)(current_type_.basic_type_) == (int)TypeCheckBasicType::CHAR_ARRAY))
  {
    cout << "loading array ref for unary" << endl;
    unaryVariable = builder_.CreateAlignedLoad(current_value_, 2);
    switch (current_type_.basic_type_)
    {
    case TypeCheckBasicType::INT_ARRAY:
    {
      unaryVariableType = TypeCheckBasicType::INT;
      break;
    }
    case TypeCheckBasicType::FLOAT_ARRAY:
    {
      unaryVariableType = TypeCheckBasicType::FLOAT;
      break;
    }
    case TypeCheckBasicType::CHAR_ARRAY:
    {
      unaryVariableType = TypeCheckBasicType::CHAR;
      break;
    }
    }
  }
  else
  {
    unaryVariable = builder_.CreateLoad(current_value_);
    unaryVariableType = current_type_.basic_type_;
  }

  bool isIntType = (int)unaryVariableType == (int)TypeCheckBasicType::INT;

  current_type_.basic_type_ = isIntType ? TypeCheckBasicType::INT : TypeCheckBasicType::FLOAT;

  switch (unary_exp_node->unary_op_type_)
  {
  case (UnaryOpType::POSITIVE):
  {
    current_value_ = isIntType ? builder_.CreateFPExt(unaryVariable, llvm::Type::getInt32Ty(llvm_context_)) : builder_.CreateFPExt(unaryVariable, llvm::Type::getFloatTy(llvm_context_));
    if (not current_if_const_)
    {
      current_const_value_ = 0.0;
    }
    break;
  }
  case (UnaryOpType::NEGATIVE):
  {
    Value *negVal = builder_.CreateNeg(unaryVariable);
    current_value_ = isIntType ? builder_.CreateFPExt(negVal, llvm::Type::getInt32Ty(llvm_context_)) : builder_.CreateFPExt(negVal, llvm::Type::getFloatTy(llvm_context_));
    if (current_if_const_)
    {
      current_const_value_ = -current_const_value_;
    }
    else
    {
      current_const_value_ = 0.0;
    }
    break;
  }
  case (UnaryOpType::NOT):
  {
    Value *notVal = builder_.CreateNot(unaryVariable);
    current_value_ = isIntType ? builder_.CreateFPExt(notVal, llvm::Type::getInt32Ty(llvm_context_)) : builder_.CreateFPExt(notVal, llvm::Type::getFloatTy(llvm_context_));
    //! LahElr: 浮点误差可能性微存
    if (current_if_const_)
    {
      current_const_value_ = current_const_value_ == 0.0 ? 1.0 : 0.0;
    }
    else
    {
      current_const_value_ = 0.0;
    }
    break;
  }
  case (UnaryOpType::GETPTR):
  {
    // // LahElr:bookmark
    cout << "using get-pointer operator" << endl;
    // llvm::Value* ptr_to_the_ptr = builder_.CreateAlloca(llvm::Type::getInt32Ty(llvm_context_));
    // builder_.CreateStore(current_value_,ptr_to_the_ptr);
    // current_value_ = ptr_to_the_ptr;
    current_if_const_ = false;
    current_type_ = TypeCheckType(TypeCheckBasicType::POINTER);
    current_const_value_ = 0.0;
    // break;
    // llvm::Value *arr_start = symbol_table_.GetLocalVariableInstance(node->ident_);
    // std::vector<Value*> indices;
    // ArrayRef<Value *> arr_index({ConstantInt::get(Type::getInt32Ty(llvm_context_), 0), ConstantInt::get(Type::getInt32Ty(llvm_context_), 0)});
    // llvm:;Value* ptr = builder_.CreateInBoundsGEP(arr_start, arr_index, "arrayPtr");
    // current_value_ = builder_.CreateAlloca(llvm::Type::getInt32Ty(llvm_context_));
    // builder_.CreateStore(ptr,current_value_);
    // current_type_ = TypeCheckType(TypeCheckBasicType::INT_ARRAY);
    // break;
  }
  }
  //current_type_ = isIntType ? TypeCheckType(TypeCheckBasicType::INT) : TypeCheckType(TypeCheckBasicType::FLOAT);
}

void IrGenVisitor::VisitImplicit(InitValNode *init_val_node)
{
  cout << "[InitValNode]" << endl;
}

// generate IR for error node
// no code at all, just set error info
void IrGenVisitor::VisitImplicit(ErrorNode *node)
{
  cout << "[ErrorNode]" << endl;
  current_if_error_ = true;
}

// generate code for "leaves" of expression
// current_value_ as the address
void IrGenVisitor::VisitImplicit(ValuePrimaryExpNode *node)
{
  cout << "[ValuePrimaryExpNode]" << endl;
  bool use_global = symbol_table_.IsInGlobalScope();
  if (not use_global)
  {
    switch (node->node_type_)
    {
    case (NodeType::STRING_PRIMARY_EXP):
    {
      current_value_ = builder_.CreateGlobalStringPtr(node->string_value_);
      current_type_.basic_type_ = TypeCheckBasicType::STRING;
      current_const_value_ = 0.0;
      break;
    }
    case (NodeType::INT_PRIMARY_EXP):
    {
      current_value_ = builder_.CreateAlloca(llvm::Type::getInt32Ty(llvm_context_), llvm::ConstantInt::get(llvm::Type::getInt32Ty(llvm_context_), 1));
      builder_.CreateStore(llvm::ConstantInt::get(llvm::Type::getInt32Ty(llvm_context_), node->int_value_), current_value_);
      current_type_.basic_type_ = TypeCheckBasicType::INT;
      current_const_value_ = double(node->int_value_);
      break;
    }
    case (NodeType::FLOAT_PRIMARY_EXP):
    {
      current_value_ = builder_.CreateAlloca(llvm::Type::getFloatTy(llvm_context_), llvm::ConstantInt::get(llvm::Type::getInt32Ty(llvm_context_), 1));
      builder_.CreateStore(llvm::ConstantFP::get(llvm::Type::getFloatTy(llvm_context_), node->float_value_), current_value_);
      current_type_.basic_type_ = TypeCheckBasicType::FLOAT;
      current_const_value_ = double(node->float_value_);
      break;
    }
    case (NodeType::CHAR_PRIMARY_EXP):
    {
      current_value_ = builder_.CreateAlloca(llvm::Type::getInt8Ty(llvm_context_), llvm::ConstantInt::get(llvm::Type::getInt32Ty(llvm_context_), 1));
      builder_.CreateStore(llvm::ConstantInt::get(llvm::Type::getInt8Ty(llvm_context_), node->char_value_), current_value_);
      current_type_.basic_type_ = TypeCheckBasicType::CHAR;
      current_const_value_ = double(node->char_value_);
      break;
    }
    }
    current_if_const_ = true;
    current_if_error_ = false;
  }
  else
  {
    switch (node->node_type_)
    {
    case (NodeType::STRING_PRIMARY_EXP):
    {
      current_value_ = builder_.CreateGlobalStringPtr(node->string_value_);
      current_type_.basic_type_ = TypeCheckBasicType::STRING;
      current_const_value_ = 0.0;
      break;
    }
    case (NodeType::INT_PRIMARY_EXP):
    {
      current_value_ = llvm::ConstantInt::get(llvm::Type::getInt32Ty(llvm_context_), node->int_value_);
      current_type_.basic_type_ = TypeCheckBasicType::INT;
      current_const_value_ = double(node->int_value_);
      break;
    }
    case (NodeType::FLOAT_PRIMARY_EXP):
    {
      current_value_ = llvm::ConstantFP::get(llvm::Type::getFloatTy(llvm_context_), node->float_value_);
      current_type_.basic_type_ = TypeCheckBasicType::FLOAT;
      current_const_value_ = double(node->float_value_);
      break;
    }
    case (NodeType::CHAR_PRIMARY_EXP):
    {
      current_value_ = llvm::ConstantInt::get(llvm::Type::getInt8Ty(llvm_context_), node->char_value_);
      current_type_.basic_type_ = TypeCheckBasicType::CHAR;
      current_const_value_ = double(node->char_value_);
      break;
    }
    }
    current_if_const_ = true;
    current_if_error_ = false;
  }
  // cout << "[finished]" << endl;
}

// generate code for left value, such as a, b[1] ...
// current_value_ as an address
void IrGenVisitor::VisitImplicit(LValPrimaryExpNode *node)
{
  cout << "[LValPrimaryExpNode]" << endl;
  current_if_const_ = false;
  // find destination
  // if local does not exist
  if (!symbol_table_.IfExistLocal(node->ident_))
  {
    current_if_error_ = true;
    return;
  }
  // check type consistency
  TypeCheckType var_type;
  symbol_table_.GetLocalVariableType(node->ident_, var_type);
  int var_type_dimension_list_size = var_type.array_dimension_list_.size();
  int index_list_size = node->index_list_.size();
  if (var_type_dimension_list_size == index_list_size and index_list_size > 0)
  {
    llvm::Value *index_temp = builder_.CreateAlloca(llvm::Type::getInt32Ty(llvm_context_));
    builder_.CreateStore(llvm::ConstantInt::get(llvm::Type::getInt32Ty(llvm_context_), 0), index_temp);
    std::vector<int> dim_vec(var_type.array_dimension_list_.begin(), var_type.array_dimension_list_.end());
    int dim_cur = 0;
    for (auto iter_index : node->index_list_)
    {
      dim_cur++;
      int post_dims = 1;
      // if(dim_cur == dim_vec.size()-1){post_dims = 0;}else{
      for (int i = dim_cur; i < dim_vec.size(); i++)
      {
        post_dims *= dim_vec[dim_cur];
      }
      // }
      cout << "array index: " << dim_cur << " , " << post_dims << endl;
      Visit(iter_index);
      llvm::Value *arr_dim = builder_.CreateAlloca(llvm::Type::getInt32Ty(llvm_context_));
      builder_.CreateStore(llvm::ConstantInt::get(llvm::Type::getInt32Ty(llvm_context_), post_dims), arr_dim);
      llvm::Value *mulVal = builder_.CreateMul(builder_.CreateLoad(current_value_), builder_.CreateLoad(arr_dim));
      llvm::Value *index_temp_value = builder_.CreateLoad(index_temp);
      llvm::Value *addVal = builder_.CreateAdd(mulVal, index_temp_value);
      builder_.CreateStore(addVal, index_temp);
    }
    llvm::Value *index_temp_value = builder_.CreateLoad(index_temp);
    ArrayRef<Value *> arr_index({ConstantInt::get(Type::getInt32Ty(llvm_context_), 0), index_temp_value});
    // ArrayRef<Value *> arr_index({ ConstantInt::get(Type::getInt32Ty(llvm_context_), 0), ConstantInt::get(Type::getInt32Ty(llvm_context_), 0)});
    llvm::Value *arr_start = symbol_table_.GetLocalVariableInstance(node->ident_);
    llvm::Value *tgt_ele = builder_.CreateInBoundsGEP(arr_start, arr_index, "arr_ele_ref");
    llvm::Type *ele_type = nullptr;
    // TypeCheckBasicType ele_tcbt_type = TypeCheckBasicType::VOID;
    switch (var_type.basic_type_)
    {
    case TypeCheckBasicType::CHAR_ARRAY:
    {
      ele_type = llvm::Type::getInt8Ty(llvm_context_);
      // ele_tcbt_type = TypeCheckBasicType::CHAR;
      break;
    }
    case TypeCheckBasicType::INT_ARRAY:
    {
      ele_type = llvm::Type::getInt32Ty(llvm_context_);
      // ele_tcbt_type = TypeCheckBasicType::INT;
      break;
    }
    case TypeCheckBasicType::FLOAT_ARRAY:
    {
      ele_type = llvm::Type::getFloatTy(llvm_context_);
      // ele_tcbt_type = TypeCheckBasicType::FLOAT;
      break;
    }
    }
    llvm::Value *new_value_refs_tgt_ele = builder_.CreateAlloca(ele_type, nullptr, "arr_ele_ref_var");
    auto tgt_ele_value = builder_.CreateAlignedLoad(tgt_ele, 2);
    builder_.CreateStore(tgt_ele_value, new_value_refs_tgt_ele);
    current_value_ = new_value_refs_tgt_ele;
    current_type_ = var_type.basic_type_;
    current_arr_tgt_ = tgt_ele;
    // cout << "defined name: " << std::string(tgt_ele->getName()) << endl;
    // cout << "defined name2: " << std::string(new_value_refs_tgt_ele->getName()) << endl;
  }
  else if (var_type_dimension_list_size != index_list_size and index_list_size == 0 and var_type_dimension_list_size > 0)
  {
    // // TODO: give the start ptr to the array
    // llvm::Value *ptr = builder_.CreateAlloca(llvm::Type::getInt64Ty(llvm_context_)));
    // builder_.CreateStore(arr_start,ptr);
    // current_value_ = ptr;
    // current_type_ = TypeCheckType(TypeCheckBasicType::INT);
    // return;
    // indices.push_back(ConstantInt::get(llvm::Type::getInt32Ty(llvm_context_), 0, false));
    cout << "give the start ptr to the array" << endl;
    llvm::Value *arr_start = symbol_table_.GetLocalVariableInstance(node->ident_);
    std::vector<Value *> indices;
    ArrayRef<Value *> arr_index({ConstantInt::get(Type::getInt32Ty(llvm_context_), 0), ConstantInt::get(Type::getInt32Ty(llvm_context_), 0)});
  llvm:;
    Value *ptr = builder_.CreateInBoundsGEP(arr_start, arr_index, "arrayPtr");
    // current_value_ = builder_.CreateAlloca(llvm::Type::getInt32Ty(llvm_context_));
    // builder_.CreateStore(ptr,current_value_);
    current_value_ = ptr;
    current_type_ = TypeCheckType(TypeCheckBasicType::POINTER);
    return;
  }
  else if (var_type_dimension_list_size != index_list_size and index_list_size > 0 and var_type_dimension_list_size > 0)
  {
    // TODO: raise error
    cout << "array ref and decl not match: " << var_type_dimension_list_size << " and "
         << index_list_size << endl;
  }
  else
  {
    current_value_ = symbol_table_.GetLocalVariableInstance(node->ident_);
    current_type_ = var_type;
    return;
  }
}

// generate code for return statement
void IrGenVisitor::VisitImplicit(ReturnStmtNode *node)
{
  cout << "[ReturnStmtNode]" << endl;
  current_if_error_ = false;
  if (node->exp_ != nullptr)
  {
    Visit(node->exp_);
    builder_.CreateRet(current_value_);
  }
  else
  {
    current_value_ = nullptr;
    builder_.CreateRetVoid();
  }
}

// generate code for block "{}"
void IrGenVisitor::VisitImplicit(BlockNode *node)
{
  cout << "[BlockNode]" << endl;
  // create new scope
  symbol_table_.PushScope(); // virtual BasicBlock
  // visit child
  if (node->decl_stmt_list_.empty())
  { // empty block
    current_if_error_ = false;
  }
  else
  {
    bool if_error = false;
    for (auto itr : node->decl_stmt_list_)
    {
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
void IrGenVisitor::VisitImplicit(IdentNode *node)
{
  // something wrong with generating ast
  assert(0);
}

// root node
void IrGenVisitor::VisitImplicit(RootNode *node)
{
  cout << "[RootNode]" << endl;
  // generate IR of children
  bool if_error = false;
  for (auto itr : node->decl_funcdef_list_)
  {
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

void IrGenVisitor::VisitImplicit(AssignStmtNode *node)
{
  cout << "[AssignStmtNode]" << endl;
  // test error
  bool if_error = false;
  bool is_arr_ref = false;
  // left value
  Visit(node->lval_);
  Value *lval_value = current_value_;
  // cout << "name: " << std::string(lval_value->getName()) << endl;
  TypeCheckBasicType lval_type = current_type_.basic_type_;
  if (regex_match(std::string(lval_value->getName()), regex("arr_ele_ref_var.*")))
  {
    is_arr_ref = true;
    cout << "it's arr ref as assign left value!" << endl;
    llvm::Type *ele_type = nullptr;
    cout << int(current_type_.basic_type_) << endl;
    switch (current_type_.basic_type_)
    {
    case TypeCheckBasicType::CHAR_ARRAY:
    {
      ele_type = llvm::Type::getInt8Ty(llvm_context_);
      break;
    }
    case TypeCheckBasicType::INT_ARRAY:
    {
      ele_type = llvm::Type::getInt32Ty(llvm_context_);
      break;
    }
    case TypeCheckBasicType::FLOAT_ARRAY:
    {
      ele_type = llvm::Type::getFloatTy(llvm_context_);
      break;
    }
    }
    cout << "b";
    lval_value = builder_.CreateAlloca(ele_type);
    auto tgt_ele_value = builder_.CreateAlignedLoad(current_arr_tgt_, 2);
    builder_.CreateStore(tgt_ele_value, lval_value);
    cout << "c";
    switch (current_type_.basic_type_)
    {
    case TypeCheckBasicType::INT_ARRAY:
    {
      lval_type = TypeCheckBasicType::INT;
      break;
    }
    case TypeCheckBasicType::FLOAT_ARRAY:
    {
      lval_type = TypeCheckBasicType::FLOAT;
      break;
    }
    case TypeCheckBasicType::CHAR_ARRAY:
    {
      lval_type = TypeCheckBasicType::CHAR;
      break;
    }
    }
    cout << "d";
  }

  if (current_if_error_)
    if_error = true;
  // TODO : finish error check
  // if if_error == true, error has been reported
  // in Visit(node->lval_), so we do not need to
  // report error here
  if (current_if_const_ && !if_error)
    cout << "canot assign to const variable" << endl;
  // right exp_
  cout << "e";
  Visit(node->rexp_);
  Value *rexp_value = current_value_;
  if (current_if_error_)
    if_error = true;
  if (if_error)
    return;
  // do type check
  // no such type conversion
  cout << "f";
  TypeCheckBasicType ele_check_tcbt_type = TypeCheckBasicType::VOID;
  switch (current_type_.basic_type_)
  {
  case TypeCheckBasicType::INT:
  {
    ele_check_tcbt_type = TypeCheckBasicType::INT;
    break;
  }
  case TypeCheckBasicType::CHAR:
  {
    ele_check_tcbt_type = TypeCheckBasicType::CHAR;
    break;
  }
  case TypeCheckBasicType::FLOAT:
  {
    ele_check_tcbt_type = TypeCheckBasicType::FLOAT;
    break;
  }
  case TypeCheckBasicType::INT_ARRAY:
  {
    ele_check_tcbt_type = TypeCheckBasicType::INT;
    break;
  }
  case TypeCheckBasicType::CHAR_ARRAY:
  {
    ele_check_tcbt_type = TypeCheckBasicType::CHAR;
    break;
  }
  case TypeCheckBasicType::FLOAT_ARRAY:
  {
    ele_check_tcbt_type = TypeCheckBasicType::FLOAT;
    break;
  }
  }
  if (type_system_.GetAssignTypeResult(lval_type, ele_check_tcbt_type) == TypeCheckBasicType::ERROR)
  {
    cout << "no type conversion for "
         << TypeSystem::BasicTypeToString(lval_type)
         << " "
         << TypeSystem::BasicTypeToString(ele_check_tcbt_type)
         << endl;
    //TODO: raise error
  }
  else
  {
    cout << "rexp type:" << int(node->rexp_->node_type_) << endl;
    if (not(node->rexp_->node_type_ == NodeType::BINARY_EXP or node->rexp_->node_type_ == NodeType::UNARY_EXP))
    {
      cout << "rexp returns pointer." << endl;
      rexp_value = builder_.CreateLoad(rexp_value);
    }
    rexp_value = type_system_.Cast(rexp_value,
                                   lval_value->getType(),
                                   builder_.GetInsertBlock());
  }
  // do assignment
  if (is_arr_ref)
  {
    cout << "<" << std::string(rexp_value->getName()) << "> stored to <" << std::string(current_arr_tgt_->getName()) << "> aligned" << endl;
    builder_.CreateAlignedStore(rexp_value, current_arr_tgt_, 2);
  }
  else
  {
    cout << "<" << std::string(rexp_value->getName()) << "> stored to <" << std::string(lval_value->getName()) << "> without aligned" << endl;
    builder_.CreateStore(rexp_value, lval_value);
  }
}

void IrGenVisitor::VisitImplicit(IfStmtNode *node)
{
  cout << "[IfStmtNode]" << endl;
  bool if_error = false;
  // cond_
  Visit(node->cond_);
  if (current_if_error_)
  {
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
  if (cond_value->getType() != Type::getInt1Ty(llvm_context_))
  {
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
  if (node->else_stmt_ != nullptr)
  {
    builder_.CreateCondBr(cond_value, true_block, false_block);
  }
  else
  {
    builder_.CreateCondBr(cond_value, true_block, cont_block);
  }
  // deal with true block
  builder_.SetInsertPoint(true_block);
  symbol_table_.PushScope();
  Visit(node->if_stmt_);
  symbol_table_.PopScope();
  builder_.CreateBr(cont_block);
  // deal with false block
  if (node->else_stmt_ != nullptr)
  {
    function_belong->getBasicBlockList().push_back(false_block);
    builder_.SetInsertPoint(false_block);
    symbol_table_.PushScope();
    Visit(node->else_stmt_);
    symbol_table_.PopScope();
    builder_.CreateBr(cont_block);
  }
  // merge

  builder_.SetInsertPoint(cont_block);
}

void IrGenVisitor::VisitImplicit(WhileStmtNode *node)
{
  cout << "[WhileStmtNode]" << endl;
  // TODO : error check
  Function *function_belog = builder_.GetInsertBlock()->getParent();
  BasicBlock *cond_block = BasicBlock::Create(llvm_context_, "cond", function_belog),
             *body_block = BasicBlock::Create(llvm_context_, "body", function_belog),
             *cont_block = BasicBlock::Create(llvm_context_, "cont", function_belog);
  // connect origin block to cond_block
  builder_.CreateBr(cond_block);
  // get cond value
  builder_.SetInsertPoint(cond_block);
  symbol_table_.PushScope();
  Visit(node->cond_);
  symbol_table_.PopScope();
  Value *cond_value = current_value_;
  builder_.CreateCondBr(cond_value, body_block, cont_block);
  // build body_block, connect to cond_block
  current_cond_block_list_.push_back(cond_block);
  current_cont_block_list_.push_back(cont_block);
  builder_.SetInsertPoint(body_block);
  symbol_table_.PushScope();
  Visit(node->stmt_);
  symbol_table_.PopScope();
  builder_.CreateBr(cond_block);
  builder_.SetInsertPoint(cont_block);
  current_cond_block_list_.pop_back();
  current_cont_block_list_.pop_back();
}

void IrGenVisitor::VisitImplicit(ContinueStmtNode *node)
{
  cout << "[ContinueStmtNode]" << endl;
  // TODO : error check
  builder_.CreateBr(current_cond_block_list_.back());
}

void IrGenVisitor::VisitImplicit(BreakStmtNode *node)
{
  cout << "[BreakStmtNode]" << endl;
  // TODO : error check
  builder_.CreateBr(current_cont_block_list_.back());
}
