## Description & Design

#### 说明

- [...]表示可重复0或1次的可选项
- {...}表示可重复0次或多次的项
- // 表示从SysY文法修改的部分
- 增加了对float, char的支持

#### 文法

​	编译单元 CompUnit → [ CompUnit ] ( Decl | FuncDef ) 
​	声明 Decl → ConstDecl | VarDecl
​	常量声明 ConstDecl → '**const**' BType ConstDef { '**,**' ConstDef } '**;**' 
​	// 基本类型 BType → '**int**' | '**float**' | '**char**'
​	常数定义 ConstDef → **Ident** { '**[**' ConstExp '**]**' } '**=**' ConstInitVal
​	常量初值 ConstInitVal → ConstExp | '**{**' [ ConstInitVal { '**,**' ConstInitVal } ] '**}**'
​	变量声明 VarDecl → BType VarDef { '**,**' VarDef } '**;**'
​	变量定义 VarDef → **Ident** { '**[**' ConstExp '**]**' } | **Ident** { '**[**' ConstExp '**]**' } '**=**' InitVal
​	变量初值 InitVal → Exp | '**{**' [ InitVal { '**,**' InitVal } ] '**}**'
​	函数定义 FuncDef → FuncType **Ident** '**(**' [FuncFParams] '**)**' Block
   // 函数类型 FuncType → '**void**' | '**int**' | '**float**' | '**char**'
​	函数形参表 FuncFParams → FuncFParam { '**,**' FuncFParam } 
​	函数形参 FuncFParam → BType **Ident** ['**[**' '**]**' { '**[**' Exp '**]**' }] 
​	语句块 Block → '**{**' { BlockItem } '**}**'
​	语句块项 BlockItem → Decl | Stmt 
​	语句 Stmt → LVal '**=**' Exp '**;**' | [Exp] '**;**' | Block | '**if**' '**(**' Cond '**)**' Stmt [ '**else**' Stmt ] 	| '**while**' '**(**' Cond '**)**' Stmt | '**break**' '**;**' | '**continue**' '**;**' | '**return**' [Exp] '**;**'
​	表达式 Exp → AddExp
​	条件表达式 Cond → LOrExp
​	左值表达式 LVal → **Ident** {'**[**' Exp '**]**'}
​	基本表达式 PrimaryExp → '**(**' Exp '**)**' | LVal | IntNumber | FloatNumber | 		  Character | String
​	// 整数数值 IntNumber → **IntConst** 
​	// 浮点数数值 FloatNumber → **FloatConst**
​	// 字符 Character → **CharConst**
​	// 字符串 String → **StringConst**
​	一元表达式 UnaryExp → PrimaryExp | **Ident** '**(**' [FuncRParams] '**)**' | UnaryOp 	UnaryExp
​	单目运算符 UnaryOp → '**+**' | '**−**' | '**!**' 注：'!'仅出现在条件表达式中
​	函数实参表 FuncRParams → Exp { '**,**' Exp } 
​	乘除模表达式 MulExp → UnaryExp | MulExp ('*****' | '**/**' | '**%**') UnaryExp
​	加减表达式 AddExp → MulExp | AddExp ('**+**' | '**−**') MulExp
​	关系表达式 RelExp → AddExp | RelExp ('**<**' | '**>**' | '**<=**' | '**>=**') AddExp
​	相等性表达式 EqExp → RelExp | EqExp ('**==**' | '**!=**') RelExp
​	逻辑与表达式 LAndExp → EqExp | LAndExp '**&&**' EqExp
​	逻辑或表达式 LOrExp → LAndExp | LOrExp '**||**' LAndExp
​	常量表达式 ConstExp → AddExp

#### 终结符

- keyword: const, int, float, char, void, if, else, while, break, continue, return
- identifier: Ident
- literal: IntConst, FloatConst, CharConst, StringConst
- symbols: , ; [ ] { } + - ! * / % < > <= >= == != && || =
- error: Error

```lex
character := [a-zA-Z]
digit := [0-9]
Ident := {character} ({character} | "_" | {digit})*
IntConst := [+-]?{digit}+
floatConst := [+-]?({digit}+\.{digit}* | {digit}*\.{digit}+)
CharConst := '{character}'
StringConst := \"[^\"]*\"
comment_typeone := //
comment_typetwo := "/*"([^\*]|(\*)*[^\*/])*(\*)*"*/"
symbols := [,;[]{}+\-!\*/%<>"<="">=""==""!=""&&""||"]
keyword := "const" | "int" | "float" | "char" | "void" | "if" | "else" | "while" | "break" | "continue" | "return"
```

#### naive AST design

##### class relation

```txt
virtual design:
Node
   |-DeclNode
	 |-FucDefNode
	 |-BlockNode
	 |-(StmtNode)
	 | |-AssignStmtNode
	 | |-IfStmtNode
	 | |-WhileStmtNode
	 | |-BreakStmtNode
	 | |-ContinueStmtNode
	 | |-ReturnStmtNode
	 |-InitValNode
	 |-IdentNode
	 |-(ExpNode)
	   |-FuncCallExpNode
	   |-BinaryExpNode
	   |-UnaryExpNode
     |-(PrimaryExpNode)
			 |-LvalPrimaryExpNode (represent all LVal)
       |-IntPrimaryExpNode
			 |-FloatPrimaryExpNode
			 |-CharPrimaryExpNode
			 |-StringPrimaryExpNode
implementation design:
	all inherit from class Node, "( )" means that class will not be implemented.
```

##### BasicNode

```c++
enum NodeType {
		VAR_DECL_NODE, CONST_DECL_NODE, FUNC_DEF_NODE, BLOCK_DEF_NODE,
    ASSIGN_STMT_NODE, IF_STMT_NODE, WHILE_STMT_NODE,
    BREAK_STMT_NODE, CONTINUE_STMT_NODE, RETURN_STMT_NODE,
    FUNC_CALL_EXP_NODE, BINARY_EXP_NODE, UNARY_EXP_NODE,
    LVAL_PRIMARY_EXP_NODE, INT_PRIMARY_EXP_NODE, FLOAT_PRIMARY_EXP_NODE,
    CHAR_PRIMARY_EXP_NODE, STRING_PRIMARY_EXP_NODE, ROOT_NODE, INIT_VAL_NODE, IDENT_NODE
};
class Node {
  NodeType node_type_;
  
  Node(NodeType node_type) : node_type_(node_type) {}
  
  inline bool CheckNodeType(NodeType node_type) const {
	  return node_type == node_type_;
  }
}
```

##### ExpNode

```c++
std::vector<Node*> LvalPrimaryExpNode::tmp_index_list_();

class LvalPrimaryExpNode : public Node {
  std::string ident_;
  std::list<Node*> index_list_;
  
  static std::vector<Node*> tmp_index_list_;
  
  LvalPrimaryExpNode(const IdentNode *ident) :
      Node(LVAL_PRIMARY_EXP_NODE),
      ident_(ident->GetIdent()),
      index_list_() {}
  inline void AddIndex(const Node *index_exp) {
    // TODO : error check
    index_list_.push_back(index_exp);
  }
}
class IntPrimaryExpNode : public Node {
  int int_value_;
  
  inline int GetIntValue() const {
		return int_value_;
  }
}
class FloatPrimaryExpNode : public Node {
  float float_value_;
  
  inline float GetFloatValue() const {
    return float_value_;
  }
}
class CharPrimaryExpNode : public Node {
  char char_value_;
  
  inline char GetCharValue_() const {
    return char_value_;
  }
}
class StringPrimaryExpNode : public Node {
  std::string string_value_;
}
class FuncCallExpNode : public Node {
  std::string ident_;
  std::vector<Node*> rparam_array_;
  
  FuncCallExpNode() :
      Node(FUNC_CALL_EXP_NODE),
      ident_(),
      rparam_array_() {}
  inline void SetIdent(const IdentNode *ident) {
    ident_ = ident->GetIdent;
  }
  inline void AddParam(const Node *param_entry) {
    // TODO : error check
    rparam_array_.push_back(param_entry);
  }
}
enum BinaryOpType {
  ADD_OP, SUB_OP, MUL_OP, DIV_OP,
  MOD_OP, AND_OP, OR_OP, EQ_OP,
  UNEQ_OP, LE_OP, GE_OP, LEEQ_OP,
  GEEQ_OP
};
class BinaryExpNode : public Node {
  BinaryOpType binary_op_type_;
  Node *lexp_, *rexp_;
  
  BinaryExpNode(BinaryOpType binary_op_type) :
      Node(BINARY_EXP_NODE),
      binary_op_type_(binary_op_type),
      lexp_(nullptr),
      rexp_(nullptr) {}
  inline void SetLeftExp(const Node *lexp) {
    // TODO : error check
    lexp_ = lexp;
  }
  inline void SetRightExp(const Node *rexp) {
    // TODO : error check
    rexp_ = rexp;
  }
}
enum UnaryOpType {
  POSITIVE_OP, NEGATIVE_OP, NOT_OP
}
class UnaryExpNode : public Node {
  UnaryOpType unary_op_type_;
  Node *exp_;
  
  UnaryExpNode(UnaryOpType unary_op_type) :
      Node(UNARY_EXP_NODE),
      unary_op_type_(unary_op_type) {}
  inline void SetExp(const Node *exp) {
    // TODO : error check
    exp_ = exp;
  } 
}
```

##### StmtNode

```c++
class AssignStmtNode : public Node {
	Node *lval_, *rexp_
                                    
  AssignStmtNode(const Node *lval, const Node *rexp) :
      Node(ASSIGN_STMT_NODE),
      lval_(lval),
      rexp_(rexp) {}
}
class IfStmtNode : public Node {
	Node *cond_, *if_stmt_, *else_stmt_;
  
  IfStmtNode(
      Node *const cond,
      Node *const if_stmt,
      Node *const else_stmt) : 
      cond_(cond),
      if_stmt_(if_stmt),
      else_stmt_(else_stmt) {}
}
class WhileStmtNode : public Node {
  Node *cond_;
  Node *stmt_;
  
  WhileStmtNode(const Node *cond, const Node *stmt) :
      Node(WHILE_STMT_NODE),
      cond_(cond),
      stmt_(stmt) {}
}
class BreakStmtNode : public Node {
  BreakStmtNode() :
      Node(BREAK_STMT_NODE) {}
}
class ContinueStmtNode : public Node {
  ContinueStmtNode() :
      Node(CONTINUE_STMT_NODE) {}
}
class ReturnStmtNode : public Node {
  Node *return_exp_;
  
  ReturnStmtNode(const Node *return_exp) :
      Node(RETURN_STMT_NODE),
      return_exp_(return_exp) {}
}
```

##### CompUnitNode

```c++
class RootNode : public Node {
	std::list<Node*> decl_funcdef_list_;
  
  RootNode() : 
      Node(ROOT_NODE),
  		decl_funcdef_list_(0);
  inline void AddNode(const Node *new_node) {
    // TODO : replace assert with error check
    assert(new_node != nullptr);
    assert(this->CheckNodeType(VAR_DECL_NODE)
         &&this->CheckNodeType(CONST_DECL_NODE)
         &&this->CheckNodeType(FUNC_DEF_NODE));
    decl_funcdef_list_.push_back(new_node);
	}
}
```

##### DeclNode

```c++
std::vector<Node*> DeclNode::tmp_array_dimension_array_();
std::string DeclNode::tmp_ident_();
Node *DeclNode::tmp_init_val_ = nullptr;
BasicType DeclNode::tmp_basic_type_ = VOID;

class DeclNode : public Node {
  BasicType basic_type_;
  std::list<std::list<Node*>*> array_dimension_list_list_;
  std::list<std::string> ident_list_;
 	std::list<Node*> init_val_list_;
  
  static std::vector<Node*> tmp_array_dimension_array_;
  static std::string tmp_ident_;
  static Node *tmp_init_val_;
  static BasicType tmp_basic_type_;
    
  DeclNode(NodeType node_type) :
  		Node(node_type),
      basic_type_(nullptr),
      array_dimension_list_list_(),
  		ident_list_(),
      init_val_list_() {}
  
  inline void SetBasicType() {
		// TODO : error check
    basic_type_ = tmp_basic_type_;
  }
  inline void AddDecl() {
		// TODO : error check
    array_dimension_list_list_.push_back(new std::list<Node*>());
    auto itr = array_dimension_list_list_.rbegin();
    for (auto itr1 : tmp_array_dimension_array_)
      (*itr)->push_back(itr1);
    ident_list_.push_back(decl_ident_);
    init_val_list_.push_back(decl_init_val_);
  }
}
```

##### FuncDefNode

```c++
Type* FuncDefNode::tmp_fparam_basic_type_ = nullptr;
FuncDefNode* FuncDefNode::tmp_func_def_node_ = nullptr; 
std::vector<Node*> tmp_fparam_index_list_(0);

class FuncDefNode : public Node {
	BasicType func_type_;
  std::string func_ident_;
  std::vector<BasicType> fparam_basic_type_array_;
  std::vector<std::list<Node*>*> fparam_index_list_array_;
  std::vector<std::string> fparam_ident_array_;
  Node *block_;
  
  static BasicType tmp_fparam_basic_type_;
  static std::vector<Node*> tmp_fparam_index_list_;
  static FuncDefNode* tmp_func_def_node_;
  
  FuncDefNode(BasicType func_type) :
      Node(FUNC_DEF_NODE),
      func_type_(func_type),
      func_ident(),
      fparam_basic_type_array_(),
      fparam_ident_array_(),
  		fparam_index_list_array_(),
      block_(nullptr) {}
  inline void SetIdent(const Node *ident) {
    // TODO : error check
    func_ident_ = ident->GetIdent();
  }
  inline void SetBlock(const Node *block) {
    // TODO : error check
    block_ = block;
  }
  void AddParam(const Node *ident) {
    // TODO : error check
    fparam_ident_array_.push_back(ident->GetIdent());
    fparam_index_list_array_.push_back(new std::list<Node*>(0));
    auto itr = fparam_index_list_array_.rbegin();
    for(auto itr1 : tmp_fparam_index_list_)
      itr->push_back(*itr1);
    fparam_basic_type_array_.push_back(tmp_fparam_basic_type_);
  }
}
```

##### BlockNode

```c++
class BlockNode : public Node {
  std::list<Node*> decl_stmt_list_;
  
  BlockNode() :
      Node(BLOCK_NODE),
  		decl_stmt_list_() {}
  
  inline void AddNode(const Node *new_node) {
	  decl_stmt_list_.push_back(new_node);
  }
}
```

##### Type

```c++
enum BasicType {
  INT, FLOAT, CHAR, VOID
};
class Type {
  BasicType basic_type_;
  std::list<int> array_size_;
  
  Type(BasicType basic_type) :
    basic_type_(basic_type), 
    array_size_() {}
}
```

##### InitValNode

```c++
class InitValNode : public Node {
  std::list<Node*> init_val_list_;
  
  InitValNode() :
      Node(INIT_VAL_NODE),
      init_val_list_() {}
  inline void AddInitVal(const Node *init_val) {
 	  // TODO : error check
    assert(init_val != nullptr);
    init_val_list_.push_back(init_val);
  }
}
```

##### IdentNode

```c++
class IdentNode : public Node {
  std::string ident_;
  
  IdentNode() :
      Node(IDENT_NODE),
  		ident_() {}
  
  inline void SetIdent(const std::string &ident) {
  	ident_ = ident;
  }
  std::string GetIdent() const {
    return ident_;
  }
}
```



