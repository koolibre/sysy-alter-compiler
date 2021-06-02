#ifndef SYSY_ALTER_COMPILER_AST_AST_DATA_HPP_
#define SYSY_ALTER_COMPILER_AST_AST_DATA_HPP_

#ifndef DEBUG
  #define NDEBUG
#else
  #undef NDEBUG
#endif

#include <cassert>        // use assert()

#include <iostream>       // use std::cout
#include <string>         // use std::string
#include <list>           // use std::list
#include <vector>         // use std::vector

// node type
enum class NodeType {
    // root node
    ROOT,
    // declaration and definition node
    VAR_DECL, CONST_DECL, FUNC_DEF,
    // block node
    BLOCK,
    // statement node
    ASSIGN_STMT, IF_STMT, WHILE_STMT, BREAK_STMT,
    CONTINUE_STMT, RETURN_STMT,
    // expression node
    FUNC_CALL_EXP, BINARY_EXP, UNARY_EXP,
    LVAL_PRIMARY_EXP, INT_PRIMARY_EXP, FLOAT_PRIMARY_EXP,
    CHAR_PRIMARY_EXP, STRING_PRIMARY_EXP,
    // initialization value node
    INIT_VAL,
    // identifier node
    IDENT
};

// unary operation type
enum class UnaryOpType {
    // + - !
    POSITIVE, NEGATIVE, NOT
};

// binary operation type
enum class BinaryOpType {
    // multiplication
    MUL, DIV, MOD,
    // addition
    ADD, SUB,
    // relation
    LE, GE, LEEQ, GEEQ,
    // equation
    EQ, UNEQ,
    // logic
    AND, OR
};

// basic type
enum class BasicType {
  INT, FLOAT, CHAR, VOID
};

// all the nodes below are use as pure data storage,
// so we use struct instead of class,
// and there is no need to use smart pointer...

// Node
// base struct type 
struct Node {
 public:
  // ctor
  Node(NodeType node_type) : node_type_(node_type) {}
  // dtor
  virtual ~Node() {}
  // other
  inline bool CheckNodeType(NodeType node_type) const {
    return node_type_ == node_type;
  }
#ifdef DEBUG
#ifdef AST_DEBUG
  virtual void Print(int indentation) const = 0;
#endif
#endif

 private:
  // member
  NodeType node_type_;
};

// RootNode
// the ast root
struct RootNode : public Node {
 public:
  // ctor
  RootNode() :
      Node(NodeType::ROOT) {}
      // default ctor: decl_funcdef_list_(0)
  // dtor
  ~RootNode() {
    for (auto itr : decl_funcdef_list_)
      delete itr;
  }
  // other
  inline void AddNode(Node *new_node) {
    // TODO(kolibre) : error check
    assert(new_node != nullptr);
    decl_funcdef_list_.push_back(new_node);
  }
#ifdef DEBUG
#ifdef AST_DEBUG
  void Print(int indentation) const override;
#endif
#endif

 private:
  // member
  std::list<Node*> decl_funcdef_list_;
};
// global RootNode
extern RootNode *root;

// global variable for DeclNode
extern std::vector<Node*> declnode_tmp_array_dimension_array;
extern std::string declnode_tmp_ident;
extern Node* declnode_tmp_init_val;
extern BasicType declnode_tmp_basic_type;
// DeclNode
// variable declaration and const value declaration
struct DeclNode : public Node {
 public:
  // ctor
  DeclNode(NodeType node_type) :
      Node(node_type),
      basic_type_(BasicType::VOID) {}
      // create empty list
  // dtor
  ~DeclNode() {
    for (auto itr1 : array_dimension_list_list_)
      for (auto itr2 : *itr1)
        delete itr2;
  }
  // other
  inline void SetBasicType() {
    // TODO(kolibre) : error check
    basic_type_ = declnode_tmp_basic_type;
  }
  void AddDecl();
  inline void SetTmpIdent(std::string &tmp_ident) {
    declnode_tmp_ident = tmp_ident;
  }
#ifdef DEBUG
#ifdef AST_DEBUG
  void Print(int indentation) const override;
#endif
#endif

 private:
  // member
  BasicType basic_type_;
  std::list<std::list<Node*>*> array_dimension_list_list_;
  std::list<std::string> ident_list_;
  std::list<Node*> init_val_list_;
};

// IdentNode
// store identifier
struct IdentNode : public Node {
 public:
  // ctor
  IdentNode(const std::string &ident) :
      Node(NodeType::IDENT),
      ident_(ident) {}
  // dtor : default
  // other
  inline void SetIdent(const std::string &ident) {
  	ident_ = ident;
  }
  std::string GetIdent() const {
    return ident_;
  }
#ifdef DEBUG
#ifdef AST_DEBUG
  void Print(int indentation) const override;
#endif
#endif

 private:
  // member
  std::string ident_;
};

// global variable for FuncDefNode
extern BasicType funcdefnode_tmp_fparam_basic_type;
extern std::vector<Node*> funcdefnode_tmp_fparam_index_list;
// FuncDefNode
// function definition
struct FuncDefNode : public Node {
 public:
  // ctor
  FuncDefNode(BasicType func_type) :
      Node(NodeType::FUNC_DEF),
      func_type_(func_type),
      block_(nullptr) {}
  // dtor
  ~FuncDefNode() {
    for (auto itr1 : fparam_index_list_array_)
      for (auto itr2 : *itr1)
        delete itr2;
  }
  // other
  inline void SetIdent(IdentNode *ident) {
    // TODO(kolibre) : error check
    assert(ident != nullptr);
    func_ident_ = ident->GetIdent();
  }
  inline void SetBlock(Node *block) {
    // TODO(kolibre) : error check
    assert(block != nullptr);
    block_ = block;
  }
  void AddParam(IdentNode *ident);
#ifdef DEBUG
#ifdef AST_DEBUG
  void Print(int indentation) const override;
#endif
#endif

 private:
	// member
  BasicType func_type_;
  std::string func_ident_;
  std::vector<BasicType> fparam_basic_type_array_;
  std::vector<std::list<Node*>*> fparam_index_list_array_;
  std::vector<std::string> fparam_ident_array_;
  Node *block_;
};
extern FuncDefNode* funcdefnode_tmp_func_def_node;

// BlockNode
// block := {}
struct BlockNode : public Node {
 public:
  // ctor
  BlockNode() :
      Node(NodeType::BLOCK) {}
  // dtor
  ~BlockNode() {
    for (auto itr : decl_stmt_list_)
      delete itr;
  }
  // other
  inline void AddNode(Node *new_node) {
    // TODO(kolibre) : error check
    assert(new_node != nullptr);
	  decl_stmt_list_.push_back(new_node);
  }
#ifdef DEBUG
#ifdef AST_DEBUG
  void Print(int indentation) const override;
#endif
#endif

 private:
  // member
  std::list<Node*> decl_stmt_list_;

};

// InitValNode
// initialization value for declaration
// pure expression or initialization list "{ }"
struct InitValNode : public Node {
 public:
  // ctor
  InitValNode() :
      Node(NodeType::INIT_VAL) {}
  // dtor
  ~InitValNode() {
    for (auto itr : init_val_list_)
      delete itr;
  }
  // other
  inline void AddInitVal(Node *init_val) {
 	  // TODO(kolibre) : error check
    assert(init_val != nullptr);
    init_val_list_.push_back(init_val);
  }
#ifdef DEBUG
#ifdef AST_DEBUG
  void Print(int indentation) const override;
#endif
#endif

 private:
  // member
  std::list<Node*> init_val_list_;
};

// AssignStmtNode
struct AssignStmtNode : public Node {
 public:
  // ctor
  AssignStmtNode(Node *lval, Node *rexp) :
      Node(NodeType::ASSIGN_STMT),
      lval_(lval),
      rexp_(rexp) {}
  // dtor
  ~AssignStmtNode() {
    delete lval_;
    delete rexp_;
  }
  // other
#ifdef DEBUG
#ifdef AST_DEBUG
  void Print(int indentation) const override;
#endif
#endif

 private:
 // member
  Node *lval_, *rexp_;
};

// IfStmtNode
struct IfStmtNode : public Node {
 public:
  // ctor
  IfStmtNode(
      Node *cond,
      Node *if_stmt,
      Node *else_stmt) :
      Node(NodeType::IF_STMT),
      cond_(cond),
      if_stmt_(if_stmt),
      else_stmt_(else_stmt) {}  
  // dtor
  ~IfStmtNode() {
    delete cond_;
    delete if_stmt_;
    delete else_stmt_;
  }
  // other
#ifdef DEBUG
#ifdef AST_DEBUG
  void Print(int indentation) const override;
#endif
#endif

 private:
  // member	
  Node *cond_, *if_stmt_, *else_stmt_;
};

// WhileStmtNode
struct WhileStmtNode : public Node {
 public:
  // ctor
  WhileStmtNode(Node *cond, Node *stmt) :
      Node(NodeType::WHILE_STMT),
      cond_(cond),
      stmt_(stmt) {}
  // dtor
  ~WhileStmtNode() {
    delete cond_;
    delete stmt_;
  }
  // other
#ifdef DEBUG
#ifdef AST_DEBUG
  void Print(int indentation) const override;
#endif
#endif

 private:
  // member
  Node *cond_, *stmt_;
};

// BreakStmtNode
struct BreakStmtNode : public Node {
 public:
  // ctor
  BreakStmtNode() :
      Node(NodeType::BREAK_STMT) {}
  // default dtor
  // other
#ifdef DEBUG
#ifdef AST_DEBUG
  void Print(int indentation) const override;
#endif
#endif
};

// ContunueStmtNode
struct ContinueStmtNode : public Node {
 public:
  // ctor
  ContinueStmtNode() :
      Node(NodeType::CONTINUE_STMT) {}
  // default dtor
  // other
#ifdef DEBUG
#ifdef AST_DEBUG
  void Print(int indentation) const override;
#endif
#endif
};

// ReturnStmtNode
struct ReturnStmtNode : public Node {
 public:
  // ctor
  ReturnStmtNode(Node *exp) :
      Node(NodeType::RETURN_STMT),
      exp_(exp) {}
  // default dtor
  // other
#ifdef DEBUG
#ifdef AST_DEBUG
  void Print(int indentation) const override;
#endif
#endif

  private:
    // member
    Node* exp_;
};

// FuncCallExpNode
struct FuncCallExpNode : public Node {
 public:
  // ctor
  FuncCallExpNode() :
      Node(NodeType::FUNC_CALL_EXP) {}
  // dtor
  ~FuncCallExpNode() {
    for (auto itr : rparam_array_)
      delete itr;
  }
  // other
  inline void SetIdent(IdentNode *ident) {
    // TODO(kolibre) : error check
    assert(ident != nullptr);
    ident_ = ident->GetIdent();
  }
  inline void AddParam(Node *rparam) {
    // TODO(kolibre) : error check
    assert(rparam != nullptr);
    rparam_array_.push_back(rparam);
  }
#ifdef DEBUG
#ifdef AST_DEBUG
  void Print(int indentation) const override;
#endif
#endif

 private:
  // member
  std::string ident_;
  std::vector<Node*> rparam_array_;
};

// BinaryExpNode
// + - * / % && || < > <= >= == !=
struct BinaryExpNode : public Node {
 public:
  // ctor
  BinaryExpNode(BinaryOpType binary_op_type) :
      Node(NodeType::BINARY_EXP),
      binary_op_type_(binary_op_type),
      lexp_(nullptr),
      rexp_(nullptr) {}
  // dtor
  ~BinaryExpNode() {
    delete lexp_;
    delete rexp_;
  }
  // other
  inline void SetLeftExp(Node *lexp) {
    // TODO(kolibre) : error check
    assert(lexp != nullptr);
    lexp_ = lexp;
  }
  inline void SetRightExp(Node *rexp) {
    // TODO(kolibre) : error check
    assert(rexp != nullptr);
    rexp_ = rexp;
  }
#ifdef DEBUG
#ifdef AST_DEBUG
  void Print(int indentation) const override;
#endif
#endif

 private:
  // member
  BinaryOpType binary_op_type_;
  Node *lexp_, *rexp_;
};

// UnaryExpNode
// ! +(positive) -(negative)
class UnaryExpNode : public Node {
 public:
  // ctor
  UnaryExpNode(UnaryOpType unary_op_type) :
      Node(NodeType::UNARY_EXP),
      exp_(nullptr),
      unary_op_type_(unary_op_type) {}
  // dtor
  ~UnaryExpNode() {
    delete exp_;
  }
  // other
  inline void SetExp(Node *exp) {
    // TODO(kolibre) : error check
    assert(exp != nullptr);
    exp_ = exp;
  }
#ifdef DEBUG
#ifdef AST_DEBUG
  void Print(int indentation) const override;
#endif
#endif

 private:
  // member
  UnaryOpType unary_op_type_;
  Node *exp_;
};

// global variable for LValPrimaryExpNode
extern std::vector<Node*> lvalprimaryexpnode_tmp_index_array;
// LvalPrimaryExpNode
// left value, ident[a][b] .. or identifier
class LValPrimaryExpNode : public Node {
 public:
  // ctor
  LValPrimaryExpNode(IdentNode *ident) :
      Node(NodeType::LVAL_PRIMARY_EXP),
      ident_(ident->GetIdent()) {}
  // dtor
  ~LValPrimaryExpNode() {
    for (auto itr : index_list_)
      delete itr;
  }
  // other
  // inline void AddIndex(Node *index_exp) {
    // // TODO(kolibre) : error check
    // assert(index_exp != nullptr);
    // index_list_.push_back(index_exp);
  // }
  void AddLVal();
#ifdef DEBUG
#ifdef AST_DEBUG
  void Print(int indentation) const override;
#endif
#endif
  // member
  static std::vector<Node*> tmp_index_array_;

 private:
  // member
  std::string ident_;
  std::list<Node*> index_list_;
};

// ValuePrimaryExpNode
// T can be: int char float and std::string
// fetch value from lex
template <typename T>
struct ValuePrimaryExpNode : public Node {
 public:
  // ctor
  ValuePrimaryExpNode(NodeType node_type, T value) :
      Node(node_type),
      value_(value) {}
  // default dtor
  // other
  inline void SetValue(T value) {
    value_ = value;
  }
  inline T GetValue() const {
    return value_;
  }
#ifdef DEBUG
#ifdef AST_DEBUG
  void Print(int indentation) const override {
    // print node name
    for (int i = 0; i < indentation; i++)
      std::cout << " ";
    std::cout << "[ValuePrimaryExpNode]" << std::endl;
    // print value
    for (int i = 0; i < indentation+1; i++)
      std::cout << " ";
    std::cout << "-value_: " << value_ << std::endl;
  }
#endif
#endif

 private:
  // member
  T value_;
};
#endif