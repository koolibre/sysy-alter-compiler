#ifndef SYSY_ALTER_COMPILER_IR_GEN_IR_GEN_HPP_
#define SYSY_ALTER_COMPILER_IR_GEN_IR_GEN_HPP_

#include <memory>

#include <llvm/IR/Value.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/Module.h>

#include "ast/ast.hpp"
#include "ir-gen/type-system.hpp"
#include "ir-gen/symbol-table.hpp"

// base class for visitor>
class NodeVisitor {
 public:
  // default ctor
  // virtual dtor
  virtual ~NodeVisitor() {}
  // other
  void Visit(Node *node) {
    node->Accept(this);
  }
  virtual void VisitImplicit(RootNode *root_node) = 0;
  virtual void VisitImplicit(DeclNode *decl_node) = 0;
  virtual void VisitImplicit(IdentNode *ident_node) = 0;
  virtual void VisitImplicit(FuncDefNode *root_node) = 0;
  virtual void VisitImplicit(BlockNode *root_node) = 0;
  virtual void VisitImplicit(InitValNode *init_val_node) = 0;
  virtual void VisitImplicit(AssignStmtNode *assign_stmt_node) = 0;
  virtual void VisitImplicit(IfStmtNode *if_stmt_node) = 0;
  virtual void VisitImplicit(WhileStmtNode *while_stmt_node) = 0;
  virtual void VisitImplicit(BreakStmtNode *break_stmt_node) = 0;
  virtual void VisitImplicit(ContinueStmtNode *continue_stmt_node) = 0;
  virtual void VisitImplicit(ReturnStmtNode *return_stmt_node) = 0;
  virtual void VisitImplicit(FuncCallExpNode *func_call_exp_node) = 0;
  virtual void VisitImplicit(BinaryExpNode *binary_exp_node) = 0;
  virtual void VisitImplicit(UnaryExpNode *unary_exp_node) = 0;
  virtual void VisitImplicit(LValPrimaryExpNode *lval_primary_exp_node) = 0;
  virtual void VisitImplicit(ValuePrimaryExpNode *value_primary_exp_node) = 0;
  virtual void VisitImplicit(ErrorNode* error_node_) = 0;
};

class IrGenVisitor : public NodeVisitor {
 public:
  // ctor
  IrGenVisitor(llvm::LLVMContext &llvm_context) :
    llvm_context_(llvm_context),
    builder_(llvm_context_),
    type_system_(llvm_context_),
    current_type_(TypeCheckBasicType::VOID),
    symbol_table_(llvm_context_) {}
  // default dtor
  // other
  void VisitImplicit(RootNode *root_node) override;                         // finish
  void VisitImplicit(DeclNode *decl_node) override;
  void VisitImplicit(IdentNode *ident_node) override;                       // finish
  void VisitImplicit(FuncDefNode *root_node) override;                      // finish
  void VisitImplicit(BlockNode *root_node) override;                        // finish
  void VisitImplicit(InitValNode *init_val_node) override;
  void VisitImplicit(AssignStmtNode *assign_stmt_node) override;            // finish
  void VisitImplicit(IfStmtNode *if_stmt_node) override;                    // finish
  void VisitImplicit(WhileStmtNode *while_stmt_node) override;              // finish
  void VisitImplicit(BreakStmtNode *break_stmt_node) override;              // finish
  void VisitImplicit(ContinueStmtNode *continue_stmt_node) override;        // finish
  void VisitImplicit(ReturnStmtNode *return_stmt_node) override;            // finish
  void VisitImplicit(FuncCallExpNode *func_call_exp_node) override;
  void VisitImplicit(BinaryExpNode *binary_exp_node) override;
  void VisitImplicit(UnaryExpNode *unary_exp_node) override;
  void VisitImplicit(LValPrimaryExpNode *lval_primary_exp_node) override;
  void VisitImplicit(ErrorNode *error_node) override;                       // finish
  void VisitImplicit(ValuePrimaryExpNode *value_primary_exp_node) override; // finish
 
 private:
  // member
  // info-component for ir generation
  llvm::LLVMContext &llvm_context_;
  llvm::IRBuilder<> builder_;
  std::unique_ptr<llvm::Module> module_;
  SymbolTable symbol_table_;
  TypeSystem type_system_;
  // retern value
  bool current_if_const_;
  TypeCheckType current_type_;
  llvm::Value *current_value_;
  bool current_if_error_;
  // record for "break" and "continue"
  std::list<llvm::BasicBlock*> current_cond_block_list_;
  std::list<llvm::BasicBlock*> current_cont_block_list_;
};

#endif