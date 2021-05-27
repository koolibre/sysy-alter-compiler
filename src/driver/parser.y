%{
#define DEBUG
#ifndef DEBUG
  #define NDEBUG
#else
  #undef NDEBUG
#endif

#include <cassert> // use assert()

#include <iostream> // use std::cout
#include <string> // use std::string

#include "ast/ast.hpp" // use struct Node

#define YYSTYPE Node*
// output error message
// used in scanner.cpp
void yyerror(char *str);

// defined in scanner.cpp
extern int yylex();
%}

// token definition
// keyword
%token CONST INT FLOAT CHAR VOID IF ELSE WHILE BREAK CONTINUE RETURN
// idenifier
%token IDENT
// literial
%token INT_CONST FLOAT_CONST CHAR_CONST STRING_CONST
// one-character symbol
// %token '+' '-' '*' '/' '%' '[' ']' '{' '}' ',' ';' '!' '<' '>'
// two-character symbol
%token LEEQ GEEQ EQ UNEQ AND OR
// TODO(kolibre) : finish error token
// %token ERROR

%start CompUnit

%%

CompUnit:
  CompUnit Decl {
    $1->AddNode($2);
    $$ = $1;
  } |
  CompUnit FuncDef {
    $1->AddNode($2);
    $$ = $1;    
  } |
  Decl {
    root->AddNode($1);
    $$ = root;
  } |
  FuncDef {
    root->AddNode($1);
    $$ = root;    
  }
  ;

Decl:
  ConstDecl {
    $$ = $1;
  } |
  VarDecl {
    $$ = $1;
  }
  ;

ConstDecl:
  CONST BType ConstDefList ';' {
    $3->SetBasicType();
    $$ = $3;
  }
  ;

ConstDefList:
  ConstDef {
    DeclNode* new_decl_node = new DeclNode(NodeType::CONST_DECL);
    new_decl_node->AddDecl();
    $$ = new_decl_node;
  } |
  ConstDefList ',' ConstDef {
    $1->AddDecl();
    $$ = $1;   
  }
  ;

ConstDef:
  IDENT ConstDefDimensionList '=' ConstInitVal {
    DeclNode::tmp_ident_ = $1->GetIdent();
    DeclNode::tmp_init_val_ = $4;
    $$ = nullptr;
  }
  ;

ConstDefDimensionList:
  /* empty */ {
    DeclNode::tmp_array_dimension_array_.resize(0);
    $$ = nullptr;
  } |
  ConstDefDimensionList '[' ConstExp ']' {
    DeclNode::tmp_array_dimension_array_.push_back($3);
    $$ = $1;
  }
  ;

ConstInitVal:
  ConstExp {
    $$ = $1;
  } |
  '{' ConstInitValList '}' {
    $$ = $2;
  } |
  '{' '}' {
    $$ = new InitValNode;
  }
  ;

ConstInitValList:
  ConstInitValList ',' ConstInitVal {
    $1->AddInitVal($3);
    $$ = $1;
  } |
  ConstInitVal {
    InitValNode *new_init_val_node = new InitValNode;
    new_init_val_node->AddInitVal($1);
    $$ = new_init_val_node;
  }
  ;

VarDecl:
  BType VarDefList ';' {
    $3->SetBasicType();
    $$ = $3;
  }
  ;

VarDefList:
  VarDef {
    DeclNode* new_decl_node = new DeclNode(NodeType::VAR_DECL);
    new_decl_node->AddDecl();
    $$ = new_decl_node;
  } |
  VarDefList ','  VarDef {
    $1->AddDecl();
    $$ = $1;
  }
  ;

VarDef:
  IDENT VarDefDimensionList '=' VarInitVal {
    DeclNode::tmp_ident_ = $1->GetIdent();
    DeclNode::tmp_init_val_ = $4;
    $$ = nullptr; 
  }
  ;

VarDefDimensionList:
  /* empty */ {
    DeclNode::tmp_array_dimension_array_.resize(0);
    $$ = nullptr;
  } |
  VarDefDimensionList '[' VarExp ']' {
    DeclNode::tmp_array_dimension_array_.push_back($3);
    $$ = $1;
  }
  ;

VarInitVal:
  VarExp {
    $$ = $1;
  } |
  '{' VarInitValList '}' {
    $$ = $2;
  } |
  '{' '}' {
    $$ = new InitValNode;
  }
  ;

VarInitValList:
  VarInitValList ',' VarInitVal {
    $1->AddInitVal($3);
    $$ = $1;
  } |
  VarInitVal {
    InitValNode *new_init_val_node = new InitValNode;
    new_init_val_node->AddInitVal($1);
    $$ = new_init_val_node;
  }
  ;

VarDef:
  IDENT VarDefDimensionList {
    DeclNode::tmp_ident_ = $1->GetIdent();
    DeclNode::tmp_init_val_ = nullptr;
    $$ = nullptr;
  }
  ;

BType:
  INT {
    DeclNode::basic_type_ = BasicType::INT;
    FuncDefNode::tmp_fparam_basic_type_ = BasicType::INT;
    $$ = nullptr;
  } |
  FLOAT {
    DeclNode::basic_type_ = BasicType::FLOAT;
    FuncDefNode::tmp_fparam_basic_type_ = BasicType::FLOAT;
    $$ = nullptr;
  } |
  CHAR {
    DeclNode::basic_type_ = BasicType::CHAR;
    FuncDefNode::tmp_fparam_basic_type_ = BasicType::CHAR;
    $$ = nullptr;
  }
  ;

Block:
  '{' BlockItemList '}' {
    $$ = $2;
  }
  ;

BlockItemList:
  /* empty */ {
    $$ = new BlockNode;
  } |
  BlockItemList BlockItem {
    $1->AddNode($2);
    $$ = $1;
  }
  ;

BlockItem:
  Decl {
    $$ = $1;
  } |
  Stmt {
    $$ = $1;
  }
  ;

Stmt:
  RETURN ExpChoice ';' {
    $$ = new ReturnStmtNode($2);
  } |
  CONTINUE ';' {
    $$ = new ContinueStmtNode;  
  } |
  BREAK ';' {
    $$ = new BreakStmtNode;
  } | 
  WHILE '(' Cond ')' Stmt {
    $$ = new WhileStmtNode($3, $5);
  } |
  IF '(' Cond ')' Stmt ElseChoice {
    $$ = new IfStmtNode($3, $5, $6);
  } |
  Block {
    $$ = $1;
  } |
  ExpChoice ';' {
    $$ = $1;
  } |
  LVal '=' Exp ';' {
    $$ = new AssignStmtNode($1, $3);
  }
  ;

ExpChoice:
  /* empty */ {
    $$ = nullptr;
  } |
  Exp {
    $$ = $1;
  }
  ;

Cond:
  LOrExp {
    $$ = $1;
  }
  ;

ElseChoice:
  /* empty */ {
    $$ = nullptr;
  } |
  ELSE Stmt {
    $$ = $2;
  }
  ;

Exp:
  AddExp {
    $$ = $1;
  }
  ;

LVal:
  IDENT IndexList {
    LvalPrimaryExpNode* tmp_node = new LvalPrimaryExpNode($1);
    tmp_node->AddLVal();
    $$ = tmp_node;
  }
  ;

IndexList:
  /* empty */ {
    LValPrimaryExpNode::tmp_index_array_.resize(0);
    $$ = nullptr;
  } |
  IndexList '[' Exp ']' {
    LValPrimaryExpNode::tmp_index_array_.push_back($3);
    $$ = nullptr;
  }
  ;

PrimaryExp:
  '(' Exp ')' {
    $$ = $2;
  } |
  LVal {
    $$ = $1;
  } |
  IntNumber {
    $$ = $1;
  } |
  FloatNumber {
    $$ = $1;
  } |
  character {
    $$ = $1;
  } |
  String {
    $$ = $1;
  }
  ;

IntNumber:
  INT_CONST {
    $$ = $1;
  }
  ;

FloatNumber:
  FLOAT_CONST {
    $$ = $1;
  }
  ;

character:
  CHAR_CONST {
    $$ = $1;
  }
  ;

String:
  STRING_CONST {
    $$ = $1;
  }
  ;

UnaryExp:
  PrimaryExp {
    $$ = $1;
  } |
  IDENT '(' FuncRParamList ')' {
    $3->SetIdent($1);
    $$ = $3;
  } |
  IDENT '(' ')' {
    FuncCallExpNode* new_node = new FuncCallExpNode;
    new_node->SetIdent($1);
    $$ = new_node;
  } |
  UnaryOp UnaryExp {
    $1->SetExp($2);
    $$ = $1;
  }
  ;

FuncRParamList:
  Exp {
    FuncCallExpNode *new_node = new FuncCallExpNode;
    $$ = new_node;
  } |
  FuncRParamList ',' Exp {
    $1->AddParam($3);
  }
  ;

UnaryOp:
  '+' {
    UnaryExpNode *new_node = new UnaryExpNode(UnaryOpType::POSITIVE);
    $$ = new_node;
  } |
  '-' {
    UnaryExpNode *new_node = new UnaryExpNode(UnaryOpType::NEGATIVE);
    $$ = new_node;
  } |
  '!' {
    UnaryExpNode *new_node = new UnaryExpNode(UnaryOpType::NOT);
    $$ = new_node;
  }
  ;

MulExp:
  UnaryExp {
    $$ = $1;
  } |
  MulExp MulOp UnaryExp {
    $2->SetLeftExp($1);
    $2->SetRightExp($3);
    $$ = $2;
  }
  ;

MulOp:
  '*' {
    BinaryExpNode *new_node = new BinaryExpNode(BinaryOpType::MUL);
    $$ = new_node;
  } |
  '/' {
    BinaryExpNode *new_node = new BinaryExpNode(BinaryOpType::DIV);
    $$ = new_node;
  } |
  '%' {
    BinaryExpNode *new_node = new BinaryExpNode(BinaryOpType::MOD);
    $$ = new_node;
  }
  ;

AddExp:
  MulExp {
    $$ = $1;
  } |
  AddExp AddOp MulExp {
    $2->SetLeftExp($1);
    $2->SetRightExp($3);
    $$ = $2; 
  }
  ;

AddOp:
  '+' {
    BinaryExpNode *new_node = new BinaryExpNode(BinaryOpType::ADD);
    $$ = new_node;
  } |
  '-' {
    BinaryExpNode *new_node = new BinaryExpNode(BinaryOpType::SUB);
    $$ = new_node;
  }
  ;

RelExp:
  RelExp RelOp AddExp {
    $2->SetLeftExp($1);
    $2->SetRightExp($3);
    $$ = $2;
  } |
  AddExp {
    $$ = $1; 
  }
  ;

RelOp:
  '<' {
    BinaryExpNode *new_node = new BinaryExpNode(BinaryOpType::LE);
    $$ = new_node; 
  } |
  '>' {
    BinaryExpNode *new_node = new BinaryExpNode(BinaryOpType::GE);
    $$ = new_node; 
  } |
  LEEQ {
    BinaryExpNode *new_node = new BinaryExpNode(BinaryOpType::LEEQ);
    $$ = new_node; 
  } |
  GEEQ {
    BinaryExpNode *new_node = new BinaryExpNode(BinaryOpType::GEEQ);
    $$ = new_node; 
  }
  ;

EqExp:
  RelExp {
    $$ = $1;
  } |
  EqExp EqOp RelExp {
    $2->SetLeftExp($1);
    $2->SetRightExp($3);
    $$ = $2;
  }
  ;

EqOp:
  EQ {
    BinaryExpNode *new_node = new BinaryExpNode(BinaryOpType::EQ);
    $$ = new_node;
  } |
  UNEQ {
    BinaryExpNode *new_node = new BinaryExpNode(BinaryOpType::UNEQ);
    $$ = new_node;
  }
  ;

LAndExp:
  EqExp {
    $$ = $1;
  } |
  LAndExp LAndOp EqExp {
    $2->SetLeftExp($1);
    $2->SetRightExp($3);
    $$ = $2;
  }
  ;

LAndOp:
  AND {
    BinaryExpNode *new_node = new BinaryExpNode(BinaryOpType::AND);
    $$ = new_node;
  }
  ;

LOrExp:
  LAndExp {
    $$ = $1;
  } |
  LOrExp LOrOp LAndExp {
    $2->SetLeftExp($1);
    $2->SetRightExp($3);
    $$ = $2;
  }
  ;

LOrOp:
  OR {
    BinaryExpNode *new_node = new BinaryExpNode(BinaryOpType::OR);
    $$ = new_node;
  }
  ;

ConstExp:
  AddExp {
    $$ = $1;
  }
  ;

FuncDef:
  FuncType IDENT '(' FuncFParamList ')' Block {
    $1->SetIdent($2);
    $1->SetBlock($6);
    $$ = FuncDefNode::tmp_func_def_node_;
  } |
  FuncType IDENT '(' ')' Block {
    $1->SetIdent($2);
    $1->SetBlock($6);
    $$ = FuncDefNode::tmp_func_def_node_;
  }
  ;

FuncFParamList:
  FuncFParam {
    FuncDefNode::tmp_func_def_node_->AddParam($1);
    $$ = nullptr;
  } |
  FuncFParamList ',' FuncFParam {
    FuncDefNode::tmp_func_def_node_->AddParam($1);
    $$ = nullptr;
  }
  ;

FuncFParam:
  BType IDENT {
    $$ = $2;
  } |
  BType IDENT '[' ']' FuncFParamIndexList {
    $$ = $2;
  }
  ;

FuncFParamIndexList:
  /* empty */ {
    FuncDefNode::tmp_param_index_list_.resize(0);
    FuncDefNode::tmp_param_index_list_.push_back(nullptr);
    $$ = nullptr;
  } |
  FuncFParamIndexList '[' Exp ']' {
    FuncDefNode::tmp_param_index_list_.push_back($3);
    $$ = nullptr;
  }
  ;

FuncType:
  VOID {
    FuncDefNode *new_node = new FuncDefNode(BasicType::VOID);
    FuncDefNode::tmp_func_def_node_ = new_node;
    $$ = new_node;
  } |
  INT {
    FuncDefNode *new_node = new FuncDefNode(BasicType::INT);
    FuncDefNode::tmp_func_def_node_ = new_node;
    $$ = new_node;
  } |
  FLOAT {
    FuncDefNode *new_node = new FuncDefNode(BasicType::FLOAT);
    FuncDefNode::tmp_func_def_node_ = new_node;
    $$ = new_node;
  } |
  CHAR {
    FuncDefNode *new_node = new FuncDefNode(BasicType::CHAR);
    FuncDefNode::tmp_func_def_node_ = new_node;
    $$ = new_node;
  }
  ;

%%

void yyerror(char *str) {
  assert(str != nullptr);
  std::cout << std::string(str);
}