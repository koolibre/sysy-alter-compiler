#ifndef SYSY_ALTER_COMPILER_IR_GEN_IR_GEN_HPP_
#define SYSY_ALTER_COMPILER_IR_GEN_IR_GEN_HPP_

#include "ast/ast.hpp"

// base class for visitor
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
};

// Check if the expression is a constant expression
// and if the expression's type is consistent 
class CheckVisitor : public NodeVisitor {
 public:
  // ctor
  CheckVisitor() :
      if_type_consistent_(true),
      if_const_exp_(true) {}
  // default dtor
  // other
  void VisitImplicit(RootNode *root_node) override;
  void VisitImplicit(DeclNode *decl_node) override;
  void VisitImplicit(IdentNode *ident_node) override;
  void VisitImplicit(FuncDefNode *root_node) override;
  void VisitImplicit(BlockNode *root_node) override;
  void VisitImplicit(InitValNode *init_val_node) override;
  void VisitImplicit(AssignStmtNode *assign_stmt_node) override;
  void VisitImplicit(IfStmtNode *if_stmt_node) override;
  void VisitImplicit(WhileStmtNode *while_stmt_node) override;
  void VisitImplicit(BreakStmtNode *break_stmt_node) override;
  void VisitImplicit(ContinueStmtNode *continue_stmt_node) override;
  void VisitImplicit(ReturnStmtNode *return_stmt_node) override;
  void VisitImplicit(FuncCallExpNode *func_call_exp_node) override;
  void VisitImplicit(BinaryExpNode *binary_exp_node) override;
  void VisitImplicit(UnaryExpNode *unary_exp_node) override;
  void VisitImplicit(LValPrimaryExpNode *lval_primary_exp_node) override;
  void VisitImplicit(ValuePrimaryExpNode *value_primary_exp_node) override;
  inline void SetIfConstExp(bool if_const_exp) {
    if_const_exp_ = if_const_exp;
  }
  inline bool GetIfConstExp() const {
    return if_const_exp_;
  }
  inline void SetIfTypeConsistent(bool if_type_consistent) {
    if_type_consistent_ = if_type_consistent;
  }
  inline bool GetIfTypeConsistent() const {
    return if_type_consistent_;
  }

 private:
  // member
  bool if_type_consistent_, if_const_exp_;
};

class IrGenVisitor : public NodeVisitor {
 public:
  // ctor
  IrGenVisitor() {}
  // default dtor
  // other
  void VisitImplicit(RootNode *root_node) override;
  void VisitImplicit(DeclNode *decl_node) override;
  void VisitImplicit(IdentNode *ident_node) override;
  void VisitImplicit(FuncDefNode *root_node) override;
  void VisitImplicit(BlockNode *root_node) override;
  void VisitImplicit(InitValNode *init_val_node) override;
  void VisitImplicit(AssignStmtNode *assign_stmt_node) override;
  void VisitImplicit(IfStmtNode *if_stmt_node) override;
  void VisitImplicit(WhileStmtNode *while_stmt_node) override;
  void VisitImplicit(BreakStmtNode *break_stmt_node) override;
  void VisitImplicit(ContinueStmtNode *continue_stmt_node) override;
  void VisitImplicit(ReturnStmtNode *return_stmt_node) override;
  void VisitImplicit(FuncCallExpNode *func_call_exp_node) override;
  void VisitImplicit(BinaryExpNode *binary_exp_node) override;
  void VisitImplicit(UnaryExpNode *unary_exp_node) override;
  void VisitImplicit(LValPrimaryExpNode *lval_primary_exp_node) override;
  void VisitImplicit(ValuePrimaryExpNode *value_primary_exp_node) override;
};

#endif