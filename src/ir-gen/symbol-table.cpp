#include "ir-gen/symbol-table.hpp"

#include <llvm/IR/Type.h>
#include <llvm/IR/Value.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/Module.h>

#include <ir-gen/type-system.hpp>

void SymbolTable::PushScope() {
  // assert(block != nullptr);
  scope_stack_.push_back(Scope());
}

bool SymbolTable::IsInGlobalScope() {
  return scope_stack_.size() == 1;
}

void SymbolTable::PopScope() {
  scope_stack_.pop_back();
}

void SymbolTable::AddLocalVariable(std::string &name, llvm::Value *instance, TypeCheckType &type) {
  auto itr = scope_stack_.rbegin();
  assert(itr != scope_stack_.rend()); // empty stack
  itr->local_variable_instance_[name] = instance;
  itr->local_variable_type_[name] = type;
}

bool SymbolTable::IfExistLocal(std::string &name) const {
  for (auto itr1 = scope_stack_.rbegin(); itr1 != scope_stack_.rend(); itr1++) {
    auto itr2 = itr1->local_variable_instance_.find(name);
    if (itr2 != itr1->local_variable_instance_.end())
      return true;
  }
  return false;
}

llvm::Value* SymbolTable::GetLocalVariableInstance(std::string &name) const {
  for (auto itr1 = scope_stack_.rbegin(); itr1 != scope_stack_.rend(); itr1++) {
    auto itr2 = itr1->local_variable_instance_.find(name);
    if (itr2 != itr1->local_variable_instance_.end())
      return itr2->second;
  }
  return nullptr;
}

void SymbolTable::GetLocalVariableType(std::string &name, TypeCheckType &type) const {
  for (auto itr1 = scope_stack_.rbegin(); itr1 != scope_stack_.rend(); itr1++) {
    auto itr2 = itr1->local_variable_type_.find(name);
    if (itr2 != itr1->local_variable_type_.end()) {
      type = itr2->second;
      return;
    }
  }
}

bool SymbolTable::IfExistFunction(std::string &name) const {
  return (function_.find(name) != function_.end());
}

void SymbolTable::AddFunction(std::string &name, llvm::Function *function) {
  assert(function != nullptr);
  function_.at(name) = function;
}

llvm::Function* SymbolTable::GetFunction(std::string &name) const {
  auto itr = function_.find(name);
  if (itr != function_.end())
    return itr->second;
  else
    return nullptr;
}

llvm::Function* SymbolTable::GetPreDefinedFunction(std::string &name) const {
  if (name.compare("printf") == 0) {
    return printf_;
  }
  else if (name.compare("scanf") == 0) {
    return scanf_;
  }
  else if (name.compare("main") == 0) {
    return main_;
  }
  else
    return nullptr;
}

SymbolTable::SymbolTable(llvm::LLVMContext &llvm_context) :
    llvm_context_(llvm_context) {
  // declare main
  std::vector<llvm::Type*> args_of_main;
  llvm::FunctionType *type_of_main = llvm::FunctionType::get(
      llvm::Type::getVoidTy(llvm_context_),
      llvm::makeArrayRef(args_of_main),
      false);
  main_ = llvm::Function::Create(type_of_main,
                           llvm::GlobalVariable::ExternalLinkage,
                           "main");

  // declare printf
  std::vector<llvm::Type*> args_of_printf;
  args_of_printf.push_back(llvm::Type::getInt8PtrTy(llvm_context_));
  llvm::FunctionType *type_of_printf = llvm::FunctionType::get(
      llvm::Type::getInt32Ty(llvm_context_),
      llvm::makeArrayRef(args_of_printf),
      true);
  printf_ = llvm::Function::Create(type_of_printf,
                             llvm::GlobalValue::ExternalLinkage,
                             "printf");
  printf_->setCallingConv(llvm::CallingConv::C);

  // declare scanf
  std::vector<llvm::Type*> args_of_scanf;
  args_of_scanf.push_back(llvm::Type::getInt8PtrTy(llvm_context_));
  llvm::FunctionType *type_of_scanf = llvm::FunctionType::get(
      llvm::Type::getInt32Ty(llvm_context_),
      llvm::makeArrayRef(args_of_scanf),
      true);
  scanf_ = llvm::Function::Create(type_of_scanf,
                             llvm::GlobalValue::ExternalLinkage,
                             "scanf");
  scanf_->setCallingConv(llvm::CallingConv::C);

  PushScope();
}