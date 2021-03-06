#ifndef SYSY_ALTER_COMPILER_IR_GEN_SYMBOL_TABLE_HPP_
#define SYSY_ALTER_COMPILER_IR_GEN_SYMBOL_TABLE_HPP_

#include "ir-gen/type-system.hpp"

#include <memory>
#include <list>
#include <map>

#include <llvm/IR/Type.h>
#include <llvm/IR/Value.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/Module.h>

struct Scope {
 public:
  // default ctor
  // member
  std::map<std::string, llvm::Value*> local_variable_instance_;
  std::map<std::string, TypeCheckType> local_variable_type_;
};

class SymbolTable{
 public:
  // ctor
  SymbolTable(llvm::LLVMContext &llvm_context);
  // default dtor
  // other
  void PushScope();
  void PopScope();
  void AddLocalVariable(std::string &name, llvm::Value *instance, TypeCheckType &type);
  bool IfExistLocal(std::string &name) const;
  llvm::Value* GetLocalVariableInstance(std::string &name) const;
  void GetLocalVariableType(std::string &name, TypeCheckType &type) const;
  bool IfExistFunction(std::string &name) const;
  void AddFunction(std::string &name, llvm::Function *function);
  llvm::Function* GetFunction(std::string &name) const;
  llvm::Function* GetPreDefinedFunction(std::string &name) const;
  bool IsInGlobalScope();

 private:
  // member
  llvm::LLVMContext &llvm_context_;
  std::list<Scope> scope_stack_;
  std::map<std::string, llvm::Function*> function_;
  llvm::Function *printf_, *scanf_, *main_;
};
#endif