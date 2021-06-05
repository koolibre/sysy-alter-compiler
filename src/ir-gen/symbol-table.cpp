#include "ir-gen/symbol-table.hpp"

#include <llvm/IR/Type.h>
#include <llvm/IR/Value.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/Module.h>

#include <ir-gen/type-system.hpp>

void SymbolTable::PushScope() {
  assert(block != nullptr);
  scope_stack_.push_back(Scope());
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
  // TODO : Declare printf and scanf
}