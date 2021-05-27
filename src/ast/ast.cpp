#include "ast/ast.hpp"

#include <cassert>      // use assert()

#include <iostream>     // use std::cout
#iuclude <string>       // use std::string
#include <list>         // use std::list
#include <vector>       // use std::vector

using cout = std::cout;
using list = std::list
using string = std::string;
using endl = std::endl;

// all nodes' Print()
#ifdef DEBUG
// the increase in indentation of each recursion
constexpr int kIndentationIncrease = 1;

// print indetation
auto PrintIndentation = [](int indentation) {
  for (int i = 0; i < indentation; i++)
    cout << " ";
};

// print basic type
auto PrintBasicType = [](BasicType basic_type) {
  switch(basic_type) {
    case BasicType::CHAR : {
      cout << "char" << endl;
      break;
    }
    case BasicType::INT : {
      cout << "int" << endl;
      break; 
    }
    case BasicType::FLOAT : {
      cout << "float" << endl;
    }
    case BasicType::VOID : {
      cout << "VOID" << endl;
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
      cout << "+" << endl;
      break;
    }
    case BinaryOpType::SUB : {
      cout << "-" << endl;
      break;
    }
    case BinaryOpType::MUL : {
      cout << "*" << endl;
      break;
    }
    case BinaryOpType::DIV : {
      cout << "/" << endl;
      break;
    }
    case BinaryOpType::MOD : {
      cout << "%" << endl;
      break;
    }
    case BinaryOpType::LE : {
      cout << "<" << endl;
      break;
    }
    case BinaryOpType::GE : {
      cout << ">" << endl;
      break;
    }
    case BinaryOpType::LEEQ : {
      cout << "<=" << endl;
      break;
    }
    case BinaryOpType::GEEQ : {
      cout << ">=" << endl;
      break;
    }
    case BinaryOpType::EQ : {
      cout << "==" << endl;
      break;
    }
    case BinaryOpType::UNEQ : {
      cout << "!=" << endl;
      break;
    }
    case BinaryOpType::AND : {
      cout << "&&" << endl;
      break;
    }
    case BinaryOpType::OR : {
      cout << "||" << endl;
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
      cout << "+" << endl;
      break;
    }
    case UnaryOpType::NEGATIVE : {
      cout << "-" << endl;
      break;
    }
    case UnaryOpType::NOT : {
      cout << "!" << endl;
      break;
    }
    default : {
      assert(0);
    }
  }
};

void RootNode::Print(int indentation) const {
  PrintIndentation(indentation);
  cout << "[RootNode]:" << endl;
  for (auto itr : decl_funcdef_list_) {
    assert(itr != nullptr);
    itr->Print(indentation + kIndentationIncrease);
  }
}

void DeclNode::Print(int indentation) const {
  // print node name
  PrintIndentation(indentation);
  cout << "[DeclNode]:" << endl;
  // print basic_type
  PrintIndentation(indentation+1);
  cout << "-basic_type_:";
  PrintBasicType(basic_type_);
  // print identifier, dimension and initialization value
  auto itr1 = array_dimension_list_list_.begin();
  auto itr2 = ident_list_.begin();
  auto itr3 = init_val_list_.begin();
  for (int count = 0; itr2 != ident_list_.end(); count++, itr1++, itr2++, itr3++) {
    // print array_dimension_list_list_
    PrintIndentation(indentation+1);
    cout << "-array_dimension_list_list_" << "[" << count << "]:" << endl;
    for (auto itr : **itr1) {
      assert(itr != nullptr);
      itr->Print(indentation+2);
    }
    // print ident_list_
    PrintIndentation(indentation+1);
    cout << "-indent_list_" << "[" << count << "]: " 
              << *itr2 << endl;
    // print init_val_list_
    PrintIndentation(indentation+1);
    cout << "-init_val_list_" << "[" << count << "]:" << endl;
    assert(*itr3 != nullptr);
    (*itr3)->Print(indentation+2);
  }
}

void IdentNode::Print(int indentation) const {
  PrintIndentation(indentation);
  cout << "[IdentNode]: " << ident_ << endl; 
}

void FuncDefNode::Print(int indentation) const {
  // print node name
  PrintIndentation(indentation);
  cout << "[FuncDefNode]:" << endl;
  // print func_type
  PrintIndentation(indentation+1);
  cout << "-func_type_: ";
  PrintBasicType(func_type_);
  // print list
  auto itr1 = fparam_basic_type_array_.begin();
  auto itr2 = fparam_index_list_array_.begin();
  auto itr3 = fparam_ident_array_.begin();
  for (int count = 0; itr3 != fparam_ident_array_.end(); count++, itr1++, itr2++, itr3++) {
    // print fparam_basic_type_array_
    PrintIndentation(indentation+1);
    cout << "-fparam_basic_type_array_" << "[" << count << "]: ";
    PrintBasicType(*itr1);
    // print fparam_ident_array_
    PrintIndentation(indentation+1);
    cout << "-fparam_ident_array_" << "[" << count << "]: " 
              << *itr3 << endl;
    // print fparam_basic_type_array_
    PrintIndentation(indentation+1);
    cout << "-fparam_index_list_array_" << "[" << count << "]:" << endl;
    for (auto itr : **itr2) {
      assert(itr != nullptr);
      itr->Print(indentation+2);
    }
  }
  // print block
  PrintIndentation(indentation+1);
  cout << "-block_:" << endl;
  assert(block_ != nullptr);
  block_->Print(indentation+2);
}

void BlockNode::Print(int indentation) const {
  // print node name
  PrintIndentation(indentation);
  cout << "[BlockNode]:" << endl;
  // print all component
  for (auto itr : decl_stmt_list_) {
    assert(itr != nullptr);
    itr->Print(indentation+1);
  }
}

void InitValNode::Print(int indentation) const {
  // print node name
  PrintIndentation(indentation);
  cout << "[InitValNode]:" << endl;
  // print all component
  for (auto itr : init_val_list_) {
    assert(itr != nullptr);
    itr->Print(indentation+1);
  }
}

void AssignStmtNode::Print(int indentation) const {
  // print node name
  PrintIndentation(indentation);
  cout << "[AssignStmtNode]:" << endl;
  // lval
  PrintIndentation(indentation+1);
  cout << "-lval_:" << endl;
  assert(lval_ != nullptr);
  lval_->Print(indentation+2);
  // rexp
  PrintIndentation(indentation+1);
  cout << "-rexp_:" << endl;
  assert(rexp_ != nullptr);
  rexp_->Print(indentation+2);
}

void IfStmtNode::Print(int indentation) const {
  // print node name
  PrintIndentation(indentation);
  cout << "[IfStmtNode]:" << endl;
  // cond
  PrintIndentation(indentation+1);
  cout << "-cond_:" << endl;
  cond_->Print(indentation+2);
  assert(cond_ != nullptr);
  // if_stmt_
  PrintIndentation(indentation+1);
  cout << "-if_stmt_:" << endl;
  assert(if_stmt_ != nullptr);
  if_stmt_->Print(indentation+2);
  // else_stmt_
  if (else_stmt_ != nullptr) {
    PrintIndentation(indentation+1);
    cout << "-else_stmt_:" << endl;
    else_stmt_->Print(indentation+2);
  }
}

void WhileStmtNode::Print(int indentation) const {
  // print node name
  PrintIndentation(indentation);
  cout << "[WhileStmtNode]:" << endl;
  // cond
  PrintIndentation(indentation+1);
  cout << "-cond_:" << endl;
  cond_->Print(indentation+2);
  assert(cond_ != nullptr);
  // stmt
  PrintIndentation(indentation+1);
  cout << "-stmt_:" << endl;
  assert(stmt_ != nullptr);
  stmt_->Print(indentation+2);
}

void WhileStmtNode::Print(int indentation) const {
  // print node name
  PrintIndentation(indentation);
  cout << "[WhileStmtNode]:" << endl;
  // cond
  PrintIndentation(indentation+1);
  cout << "-cond_:" << endl;
  cond_->Print(indentation+2);
  assert(cond_ != nullptr);
  // stmt
  PrintIndentation(indentation+1);
  cout << "-stmt_:" << endl;
  assert(stmt_ != nullptr);
  stmt_->Print(indentation+2);
}

void BreakStmtNode::Print(int indentation) const {
  // prin node name
  PrintIndentation(indentation);
  cout << "[BreakStmtNode]" << endl;
}

void ContinueStmtNode::Print(int indentation) const {
  // print node name
  PrintIndentation(indentation);
  cout << "[ContinueStmtNode]" << endl;
}

void ReturnStmtNode::Print(int indentation) const {
  // print node name
  PrintIndentation(indentation);
  cout << "[ReturnStmtNode]" << endl;
}

void FuncCallExpNode::Print(int indentation) const {
  // print node name
  PrintIndentation(indentation);
  cout << "[FuncCallExpNode]" << endl;
  // print ident_
  PrintIndentation(indentation+1);
  cout << "-ident_: " << ident_ << endl;
  // print rparam_array_
  int count = 0;
  for (auto itr : rparam_array_) {
    assert(itr != nullptr);
    PrintIndentation(indentation+1);
    cout << "-rparam_array[" << ++count << "]:" << endl;
    itr->Print(indentation+2);
  }
}

void BinaryExpNode::Print(int indentation) const {
  // print node name
  PrintIndentation(indentation);
  cout << "[BinaryExpNode]" << endl;
  // print op
  PrintIndentation(indentation+1);
  cout << "-binary_op_type_: ";
  PrintBinaryOp(binary_op_type_);
  // print lexp_
  PrintIndentation(indentation+1);
  cout << "-lexp_:" << endl;
  lexp_->Print(indentation+2);
  // print rexp_
  PrintIndentation(indentation+1);
  cout << "-rexp_:" << endl;
  rexp_->Print(indentation+2);
}

void UnaryExpNode::Print(int indentation) const {
  // print node name
  PrintIndentation(indentation);
  cout << "[UnaryExpNode]" << endl;
  // print op
  PrintIndentation(indentation+1);
  cout << "-unary_op_type_: ";
  PrintUnaryOp(unary_op_type_);
  // print exp_
  PrintIndentation(indentation+1);
  cout << "-exp_:" << endl;
  exp_->Print(indentation+2);
}

void LValPrimaryExpNode::Print(int indentation) const {
  // print node name
  PrintIndentation(indentation);
  cout << "[LvalPrimaryExpNode]" << endl;
  // print ident_
  PrintIndentation(indentation+1);
  cout << "-ident_: " << ident_ << endl;
  // print index_list
  int count = 0;
  for (auto itr : index_list_) {
    assert(itr != nullptr);
    PrintIndentation(indentation+1);
    cout << "-index_list_[" << ++count << "]:" << endl;
    itr->Print(indentation+2);
  }
}

template <typename T>
void ValuePrimaryExpNode<T>::Print(int indentation) const {
  // print node name
  PrintIndentation(indentation);
  cout << "[ValuePrimaryExpNode]" << endl;
  // print value
  PrintIndentation(indentation+1);
  cout << "-value_: " << value_ << endl;
}
#endif

// DeclNode
// other function
void DeclNode::AddDecl() {
  list<Node*> *new_list = new list<Node*>;
  assert(new_list != nullptr);
  array_dimension_list_list_.push_back(new_list); // the new list is empty by default
  auto itr = array_dimension_list_list_.rbegin(); // the new list<Node*>
  for (auto itr1 : tmp_array_dimension_array_) {
    assert(*itr != nullptr);
    assert(itr1 != nullptr);
    (*itr)->push_back(itr1); // use tmp_array_dimension_array_ to fill the new list<Node*>
  }
  ident_list_.push_back(tmp_ident_);
  assert(tmp_init_val_ != nullptr);
  init_val_list_.push_back(tmp_init_val_);
}
// static member
vector<Node*> DeclNode::tmp_array_dimension_array_; // empty by default
string DeclNode::tmp_ident_; // empty string
Node *DeclNode::tmp_init_val_(nullptr);
BasicType DeclNode::tmp_basic_type_(BasicType::VOID);

// FuncDefNode
// other function
void FuncDefNode::AddParam(IdentNode *ident) {
  // TODO(kolibre) : error check
  assert(ident != nullptr);
  fparam_ident_array_.push_back(ident->GetIdent());
  list<Node*> *new_list = new list<Node*>;
  assert(new_list != nullptr);
  fparam_index_list_array_.push_back(new_list);
  auto itr = fparam_index_list_array_.rbegin();
  for (auto itr1 : tmp_fparam_index_list_) {
    assert(*itr != nullptr);
    assert(itr1 != nullptr);
    (*itr)->push_back(itr1);
  }
  fparam_basic_type_array_.push_back(tmp_fparam_basic_type_);
}
// static member
BasicType tmp_fparam_basic_type_(BasicType::VOID);
vector<Node*> tmp_fparam_index_list_; // empty by default
FuncDefNode* tmp_func_def_node_(nullptr);

// LvalPrimaryExpNode
// other function
void LValPrimaryExpNode::AddLVal() {
  for (auto itr : tmp_index_array_)
    index_list_.push_back(itr);
}
// static member
vector<Node*> tmp_index_array_; // empty by default