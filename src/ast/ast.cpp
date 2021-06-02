#include "ast/ast.hpp"

#include <cassert>        // use assert()

#include <iostream>       // use std::cout
#include <string>         // use std::string
#include <list>           // use std::list
#include <vector>         // use std::vector

// global variable definition
// DeclNode
std::vector<Node*> declnode_tmp_array_dimension_array;
std::string declnode_tmp_ident;
Node* declnode_tmp_init_val = nullptr;
BasicType declnode_tmp_basic_type = BasicType::VOID;
// FuncDefNode;
BasicType funcdefnode_tmp_fparam_basic_type = BasicType::VOID;
std::vector<Node*> funcdefnode_tmp_fparam_index_list;
FuncDefNode* funcdefnode_tmp_func_def_node = nullptr;
// LValPrimaryExpNode
std::vector<Node*> lvalprimaryexpnode_tmp_index_array; // empty by default
// RootNode
RootNode *root = new RootNode;

// all nodes' Print()
#ifdef DEBUG
#ifdef AST_DEBUG
// the increase in indentation of each recursion
constexpr int kIndentationIncrease = 1;

// print indetation
auto PrintIndentation = [](int indentation) {
  for (int i = 0; i < indentation; i++)
    std::cout << " ";
};

// print basic type
auto PrintBasicType = [](BasicType basic_type) {
  switch(basic_type) {
    case BasicType::CHAR : {
      std::cout << "char" << std::endl;
      break;
    }
    case BasicType::INT : {
      std::cout << "int" << std::endl;
      break; 
    }
    case BasicType::FLOAT : {
      std::cout << "float" << std::endl;
      break;
    }
    case BasicType::VOID : {
      std::cout << "void" << std::endl;
      break;
    }
    default : {
      assert(0);
    }
  }
};

// print binary operation
auto PrintBinaryOp = [](BinaryOpType binary_op_type) {
  switch(binary_op_type) {
    case BinaryOpType::ADD : {
      std::cout << "+" << std::endl;
      break;
    }
    case BinaryOpType::SUB : {
      std::cout << "-" << std::endl;
      break;
    }
    case BinaryOpType::MUL : {
      std::cout << "*" << std::endl;
      break;
    }
    case BinaryOpType::DIV : {
      std::cout << "/" << std::endl;
      break;
    }
    case BinaryOpType::MOD : {
      std::cout << "%" << std::endl;
      break;
    }
    case BinaryOpType::LE : {
      std::cout << "<" << std::endl;
      break;
    }
    case BinaryOpType::GE : {
      std::cout << ">" << std::endl;
      break;
    }
    case BinaryOpType::LEEQ : {
      std::cout << "<=" << std::endl;
      break;
    }
    case BinaryOpType::GEEQ : {
      std::cout << ">=" << std::endl;
      break;
    }
    case BinaryOpType::EQ : {
      std::cout << "==" << std::endl;
      break;
    }
    case BinaryOpType::UNEQ : {
      std::cout << "!=" << std::endl;
      break;
    }
    case BinaryOpType::AND : {
      std::cout << "&&" << std::endl;
      break;
    }
    case BinaryOpType::OR : {
      std::cout << "||" << std::endl;
      break;
    }
    default : {
      assert(0);
    }
  }
};

auto PrintUnaryOp = [](UnaryOpType unary_op_type) {
  switch(unary_op_type) {
    case UnaryOpType::POSITIVE : {
      std::cout << "+" << std::endl;
      break;
    }
    case UnaryOpType::NEGATIVE : {
      std::cout << "-" << std::endl;
      break;
    }
    case UnaryOpType::NOT : {
      std::cout << "!" << std::endl;
      break;
    }
    default : {
      assert(0);
    }
  }
};

void RootNode::Print(int indentation) const {
  PrintIndentation(indentation);
  std::cout << "[RootNode]" << std::endl;
  for (auto itr : decl_funcdef_list_) {
    assert(itr != nullptr);
    itr->Print(indentation + kIndentationIncrease);
  }
}

void DeclNode::Print(int indentation) const {
  // print node name
  PrintIndentation(indentation);
  std::cout << "[DeclNode]" << std::endl;
  // print basic_type
  PrintIndentation(indentation+1);
  std::cout << "-basic_type_:";
  PrintBasicType(basic_type_);
  // print identifier, dimension and initialization value
  auto itr1 = array_dimension_list_list_.begin();
  auto itr2 = ident_list_.begin();
  auto itr3 = init_val_list_.begin();
  for (int count = 0; itr2 != ident_list_.end(); count++, itr1++, itr2++, itr3++) {
    // print array_dimension_list_list_
    PrintIndentation(indentation+1);
    std::cout << "-array_dimension_list_list_" << "[" << count << "]:" << std::endl;
    for (auto itr : **itr1) {
      assert(itr != nullptr);
      itr->Print(indentation+2);
    }
    // print ident_list_
    PrintIndentation(indentation+1);
    std::cout << "-indent_list_" << "[" << count << "]: " 
              << *itr2 << std::endl;
    // print init_val_list_
    PrintIndentation(indentation+1);
    std::cout << "-init_val_list_" << "[" << count << "]:" << std::endl;
    if (*itr3 != nullptr)
      (*itr3)->Print(indentation+2);
  }
}

void IdentNode::Print(int indentation) const {
  PrintIndentation(indentation);
  std::cout << "[IdentNode]: " << ident_ << std::endl; 
}

void FuncDefNode::Print(int indentation) const {
  // print node name
  PrintIndentation(indentation);
  std::cout << "[FuncDefNode]" << std::endl;
  // print func_type
  PrintIndentation(indentation+1);
  std::cout << "-func_type_: ";
  PrintBasicType(func_type_);
  // print func_ident
  PrintIndentation(indentation+1);
  std::cout << "-func_ident_: " << func_ident_ << std::endl;
  // print list
  auto itr1 = fparam_basic_type_array_.begin();
  auto itr2 = fparam_index_list_array_.begin();
  auto itr3 = fparam_ident_array_.begin();
  for (int count = 0; itr3 != fparam_ident_array_.end(); count++, itr1++, itr2++, itr3++) {
    // print fparam_basic_type_array_
    PrintIndentation(indentation+1);
    std::cout << "-fparam_basic_type_array_" << "[" << count << "]: ";
    PrintBasicType(*itr1);
    // print fparam_ident_array_
    PrintIndentation(indentation+1);
    std::cout << "-fparam_ident_array_" << "[" << count << "]: " 
              << *itr3 << std::endl;
    // print fparam_basic_type_array_
    PrintIndentation(indentation+1);
    std::cout << "-fparam_index_list_array_" << "[" << count << "]:" << std::endl;
    for (auto itr : **itr2) {
      if (itr != nullptr)
        itr->Print(indentation+2);
    }
  }
  // print block
  PrintIndentation(indentation+1);
  std::cout << "-block_:" << std::endl;
  assert(block_ != nullptr);
  block_->Print(indentation+2);
  std::cout << std::endl;
}

void BlockNode::Print(int indentation) const {
  // print node name
  PrintIndentation(indentation);
  std::cout << "[BlockNode]" << std::endl;
  // print all component
  for (auto itr : decl_stmt_list_) {
    assert(itr != nullptr);
    itr->Print(indentation+1);
  }
}

void InitValNode::Print(int indentation) const {
  // print node name
  PrintIndentation(indentation);
  std::cout << "[InitValNode]" << std::endl;
  // print all component
  for (auto itr : init_val_list_) {
    assert(itr != nullptr);
    itr->Print(indentation+1);
  }
}

void AssignStmtNode::Print(int indentation) const {
  // print node name
  PrintIndentation(indentation);
  std::cout << "[AssignStmtNode]" << std::endl;
  // lval
  PrintIndentation(indentation+1);
  std::cout << "-lval_:" << std::endl;
  assert(lval_ != nullptr);
  lval_->Print(indentation+2);
  // rexp
  PrintIndentation(indentation+1);
  std::cout << "-rexp_:" << std::endl;
  assert(rexp_ != nullptr);
  rexp_->Print(indentation+2);
}

void IfStmtNode::Print(int indentation) const {
  // print node name
  PrintIndentation(indentation);
  std::cout << "[IfStmtNode]" << std::endl;
  // cond
  PrintIndentation(indentation+1);
  std::cout << "-cond_:" << std::endl;
  cond_->Print(indentation+2);
  assert(cond_ != nullptr);
  // if_stmt_
  PrintIndentation(indentation+1);
  std::cout << "-if_stmt_:" << std::endl;
  assert(if_stmt_ != nullptr);
  if_stmt_->Print(indentation+2);
  // else_stmt_
  if (else_stmt_ != nullptr) {
    PrintIndentation(indentation+1);
    std::cout << "-else_stmt_:" << std::endl;
    else_stmt_->Print(indentation+2);
  }
}

void WhileStmtNode::Print(int indentation) const {
  // print node name
  PrintIndentation(indentation);
  std::cout << "[WhileStmtNode]" << std::endl;
  // cond
  PrintIndentation(indentation+1);
  std::cout << "-cond_:" << std::endl;
  cond_->Print(indentation+2);
  assert(cond_ != nullptr);
  // stmt
  PrintIndentation(indentation+1);
  std::cout << "-stmt_:" << std::endl;
  assert(stmt_ != nullptr);
  stmt_->Print(indentation+2);
}

void BreakStmtNode::Print(int indentation) const {
  // prin node name
  PrintIndentation(indentation);
  std::cout << "[BreakStmtNode]" << std::endl;
}

void ContinueStmtNode::Print(int indentation) const {
  // print node name
  PrintIndentation(indentation);
  std::cout << "[ContinueStmtNode]" << std::endl;
}

void ReturnStmtNode::Print(int indentation) const {
  // print node name
  PrintIndentation(indentation);
  std::cout << "[ReturnStmtNode]" << std::endl;
  // print exp_
  if (exp_ != nullptr)
    exp_->Print(indentation+1);
}

void FuncCallExpNode::Print(int indentation) const {
  // print node name
  PrintIndentation(indentation);
  std::cout << "[FuncCallExpNode]" << std::endl;
  // print ident_
  PrintIndentation(indentation+1);
  std::cout << "-ident_: " << ident_ << std::endl;
  // print rparam_array_
  int count = 0;
  for (auto itr : rparam_array_) {
    assert(itr != nullptr);
    PrintIndentation(indentation+1);
    std::cout << "-rparam_array[" << ++count << "]:" << std::endl;
    itr->Print(indentation+2);
  }
}

void BinaryExpNode::Print(int indentation) const {
  // print node name
  PrintIndentation(indentation);
  std::cout << "[BinaryExpNode]" << std::endl;
  // print op
  PrintIndentation(indentation+1);
  std::cout << "-binary_op_type_: ";
  PrintBinaryOp(binary_op_type_);
  // print lexp_
  PrintIndentation(indentation+1);
  std::cout << "-lexp_:" << std::endl;
  lexp_->Print(indentation+2);
  // print rexp_
  PrintIndentation(indentation+1);
  std::cout << "-rexp_:" << std::endl;
  rexp_->Print(indentation+2);
}

void UnaryExpNode::Print(int indentation) const {
  // print node name
  PrintIndentation(indentation);
  std::cout << "[UnaryExpNode]" << std::endl;
  // print op
  PrintIndentation(indentation+1);
  std::cout << "-unary_op_type_: ";
  PrintUnaryOp(unary_op_type_);
  // print exp_
  PrintIndentation(indentation+1);
  std::cout << "-exp_:" << std::endl;
  exp_->Print(indentation+2);
}

void LValPrimaryExpNode::Print(int indentation) const {
  // print node name
  PrintIndentation(indentation);
  std::cout << "[LvalPrimaryExpNode]" << std::endl;
  // print ident_
  PrintIndentation(indentation+1);
  std::cout << "-ident_: " << ident_ << std::endl;
  // print index_list
  int count = 0;
  for (auto itr : index_list_) {
    assert(itr != nullptr);
    PrintIndentation(indentation+1);
    std::cout << "-index_list_[" << ++count << "]:" << std::endl;
    itr->Print(indentation+2);
  }
}
#endif
#endif

// DeclNode
// other function
void DeclNode::AddDecl() {
  std::list<Node*> *new_list = new std::list<Node*>;
  assert(new_list != nullptr);
  array_dimension_list_list_.push_back(new_list); // the new list is empty by default
  auto itr = array_dimension_list_list_.rbegin(); // the new list<Node*>
  for (auto itr1 : declnode_tmp_array_dimension_array) {
    assert(*itr != nullptr);
    assert(itr1 != nullptr);
    (*itr)->push_back(itr1); // use tmp_array_dimension_array_ to fill the new list<Node*>
  }
  ident_list_.push_back(declnode_tmp_ident);
  init_val_list_.push_back(declnode_tmp_init_val);
}

// FuncDefNode
// other function
void FuncDefNode::AddParam(IdentNode *ident) {
  // TODO(kolibre) : error check
  assert(ident != nullptr);
  fparam_ident_array_.push_back(ident->GetIdent());
  std::list<Node*> *new_list = new std::list<Node*>;
  assert(new_list != nullptr);
  fparam_index_list_array_.push_back(new_list);
  auto itr = fparam_index_list_array_.rbegin();
  for (auto itr1 : funcdefnode_tmp_fparam_index_list) {
    assert(*itr != nullptr);
    (*itr)->push_back(itr1);
  }
  fparam_basic_type_array_.push_back(funcdefnode_tmp_fparam_basic_type);
}

// LvalPrimaryExpNode
// other function
void LValPrimaryExpNode::AddLVal() {
  for (auto itr : lvalprimaryexpnode_tmp_index_array)
    index_list_.push_back(itr);
}
