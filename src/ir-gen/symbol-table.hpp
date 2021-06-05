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
  // ctor
  Scope(llvm::BasicBlock* block, llvm::Value *ret = nullptr) :
      block_(block) {}
  // member
  llvm::BasicBlock *block_;
  std::map<std::string, llvm::Value*> local_variable_instance_;
  std::map<std::string, TypeCheckType> local_variable_type_;
};

class SymbolTable{
 public:
  // ctor
  SymbolTable(llvm::LLVMContext &llvm_context);
  // default dtor
  // other
  void PushScope(llvm::BasicBlock *block);
  void PopScope();
  void SetScopeBlock(llvm::BasicBlock *block);
  llvm::BasicBlock *GetScopeBasicBlock() const;
  void AddLocalVariable(std::string &name, llvm::Value *instance, TypeCheckType &type);
  bool IfExistLocal(std::string &name) const;
  llvm::Value* GetLocalVariableInstance(std::string &name) const;
  void GetLocalVariableType(std::string &name, TypeCheckType &type) const;
  bool IfExistFunction(std::string &name) const;
  void AddFunction(std::string &name, llvm::Function *function);
  llvm::Function* GetFunction(std::string &name) const;

 private:
  // member
  llvm::LLVMContext &llvm_context_;
  std::list<Scope> scope_stack_;
  std::map<std::string, llvm::Function*> function_;
  llvm::Function *fprintf_, *fscanf_, *main_;
};
#endif