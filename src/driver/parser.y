%{
#ifndef DEBUG
  #define NDEBUG
#else
  #undef NDEBUG
#endif

#include <cassert>     // use assert()

#include <iostream>    // use std::cout
#include <string>      // use std::string

#include "ast/ast.hpp" // use struct Node

#define YYSTYPE Node*
// output error message
// defined in scanner.cpp
extern void yyerror(const char *str);

// defined in scanner.cpp
extern int yylex();
%}

// token definition
// keyword
%token CONST INT FLOAT CHAR VOID IF ELSE WHILE BREAK CONTINUE RETURN DEF
// idenifier
%token IDENT
// literial
%token INT_CONST FLOAT_CONST CHAR_CONST STRING_CONST
// one-character symbol
// %token '+' '-' '*' '/' '%' '[' ']' '{' '}' ',' ';' '!' '<' '>'
// two-character symbol
%token LEEQ GEEQ EQ UNEQ AND OR
// error
%token ERROR

%start CompUnit

%%

CompUnit:
  CompUnit Decl {
    RootNode *tmp_root = dynamic_cast<RootNode*>($1);
    assert(tmp_root != nullptr);
    tmp_root->AddNode($2);
    $$ = $1;
  } |
  CompUnit FuncDef {
    RootNode *tmp_root = dynamic_cast<RootNode*>($1);
    assert(tmp_root != nullptr);
    tmp_root->AddNode($2);
    $$ = $1;    
  } |
  Decl {
    assert(root != nullptr);
    root->AddNode($1);
    $$ = root;
  } |
  FuncDef {
    assert(root != nullptr);
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
    DeclNode *tmp_decl_node = dynamic_cast<DeclNode*>($3);
    assert(tmp_decl_node != nullptr);
    tmp_decl_node->SetBasicType();
    $$ = $3;
  }
  ;

ConstDefList:
  ConstDef {
    DeclNode* new_decl_node = new DeclNode(NodeType::CONST_DECL);
    assert(new_decl_node != nullptr);
    new_decl_node->AddDecl();
    $$ = new_decl_node;
  } |
  ConstDefList ',' ConstDef {
    DeclNode* tmp_decl_node = dynamic_cast<DeclNode*>($1);
    assert(tmp_decl_node != nullptr);
    tmp_decl_node->AddDecl();
    $$ = $1;   
  }
  ;

ConstDef:
  IDENT ConstDefDimensionList '=' ConstInitVal {
    declnode_tmp_ident = dynamic_cast<IdentNode*>($1)->GetIdent();
    declnode_tmp_init_val = $4;
    $$ = nullptr;
  }
  ;

ConstDefDimensionList:
  /* empty */ {
    declnode_tmp_array_dimension_array.resize(0);
    $$ = nullptr;
  } |
  ConstDefDimensionList '[' ConstExp ']' {
    declnode_tmp_array_dimension_array.push_back($3);
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
    dynamic_cast<InitValNode*>($1)->AddInitVal($3);
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
    DeclNode *tmp_decl_node = dynamic_cast<DeclNode*>($2); 
    assert(tmp_decl_node != nullptr);
    tmp_decl_node->SetBasicType();
    $$ = $2;
  }
  ;

VarDefList:
  VarDef {
    DeclNode* new_decl_node = new DeclNode(NodeType::VAR_DECL);
    new_decl_node->AddDecl();
    $$ = new_decl_node;
  } |
  VarDefList ','  VarDef {
    dynamic_cast<DeclNode*>($1)->AddDecl();
    $$ = $1;
  }
  ;

VarDef:
  IDENT VarDefDimensionList '=' VarInitVal {
    declnode_tmp_ident = dynamic_cast<IdentNode*>($1)->GetIdent();
    declnode_tmp_init_val = $4;
    $$ = nullptr; 
  }
  ;

VarDefDimensionList:
  /* empty */ {
    declnode_tmp_array_dimension_array.resize(0);
    $$ = nullptr;
  } |
  VarDefDimensionList '[' VarExp ']' {
    declnode_tmp_array_dimension_array.push_back($3);
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
    dynamic_cast<InitValNode*>($1)->AddInitVal($3);
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
    declnode_tmp_ident = dynamic_cast<IdentNode*>($1)->GetIdent();
    declnode_tmp_init_val = nullptr;
    $$ = nullptr;
  }
  ;

BType:
  INT {
    declnode_tmp_basic_type = BasicType::INT;
    funcdefnode_tmp_fparam_basic_type = BasicType::INT;
    $$ = nullptr;
  } |
  FLOAT {
    declnode_tmp_basic_type = BasicType::FLOAT;
    funcdefnode_tmp_fparam_basic_type = BasicType::FLOAT;
    $$ = nullptr;
  } |
  CHAR {
    declnode_tmp_basic_type = BasicType::CHAR;
    funcdefnode_tmp_fparam_basic_type = BasicType::CHAR;
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
    assert($$ != nullptr);
  } |
  BlockItemList BlockItem {
    BlockNode *tmp_block_node = dynamic_cast<BlockNode*>($1); 
    assert(tmp_block_node != nullptr);
    tmp_block_node->AddNode($2);
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
    LValPrimaryExpNode* tmp_node = new LValPrimaryExpNode(dynamic_cast<IdentNode*>($1));
    tmp_node->AddLVal();
    $$ = tmp_node;
  }
  ;

IndexList:
  /* empty */ {
    lvalprimaryexpnode_tmp_index_array.resize(0);
    $$ = nullptr;
  } |
  IndexList '[' Exp ']' {
    lvalprimaryexpnode_tmp_index_array.push_back($3);
    $$ = nullptr;
  }
  ;

PrimaryExp:
  '(' LOrExp ')' {
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
    dynamic_cast<FuncCallExpNode*>($3)->SetIdent(dynamic_cast<IdentNode*>($1));
    $$ = $3;
  } |
  IDENT '(' ')' {
    FuncCallExpNode* new_node = new FuncCallExpNode;
    new_node->SetIdent(dynamic_cast<IdentNode*>($1));
    $$ = new_node;
  } |
  UnaryOp UnaryExp {
    dynamic_cast<UnaryExpNode*>($1)->SetExp($2);
    $$ = $1;
  }
  ;

FuncRParamList:
  Exp {
    FuncCallExpNode *new_node = new FuncCallExpNode;
    new_node->AddParam($1);
    $$ = new_node;
  } |
  FuncRParamList ',' Exp {
    dynamic_cast<FuncCallExpNode*>($1)->AddParam($3);
    $$ = $1;
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
    dynamic_cast<BinaryExpNode*>($2)->SetLeftExp($1);
    dynamic_cast<BinaryExpNode*>($2)->SetRightExp($3);
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
    dynamic_cast<BinaryExpNode*>($2)->SetLeftExp($1);
    dynamic_cast<BinaryExpNode*>($2)->SetRightExp($3);
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
    dynamic_cast<BinaryExpNode*>($2)->SetLeftExp($1);
    dynamic_cast<BinaryExpNode*>($2)->SetRightExp($3);
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
    dynamic_cast<BinaryExpNode*>($2)->SetLeftExp($1);
    dynamic_cast<BinaryExpNode*>($2)->SetRightExp($3);
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
    dynamic_cast<BinaryExpNode*>($2)->SetLeftExp($1);
    dynamic_cast<BinaryExpNode*>($2)->SetRightExp($3);
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
    dynamic_cast<BinaryExpNode*>($2)->SetLeftExp($1);
    dynamic_cast<BinaryExpNode*>($2)->SetRightExp($3);
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

VarExp:
  AddExp {
    $$ = $1;
  }
  ;

FuncDef:
  DEF FuncType IDENT '(' FuncFParamList ')' Block {
    dynamic_cast<FuncDefNode*>($2)->SetIdent(dynamic_cast<IdentNode*>($3));
    dynamic_cast<FuncDefNode*>($2)->SetBlock($7);
    $$ = funcdefnode_tmp_func_def_node;
  } |
  DEF FuncType IDENT '(' ')' Block {
    dynamic_cast<FuncDefNode*>($2)->SetIdent(dynamic_cast<IdentNode*>($3));
    dynamic_cast<FuncDefNode*>($2)->SetBlock($6);
    $$ = funcdefnode_tmp_func_def_node;
  }
  ;

FuncFParamList:
  FuncFParam {
    funcdefnode_tmp_func_def_node->AddParam(dynamic_cast<IdentNode*>($1));
    $$ = nullptr;
  } |
  FuncFParamList ',' FuncFParam {
    funcdefnode_tmp_func_def_node->AddParam(dynamic_cast<IdentNode*>($3));
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
    funcdefnode_tmp_fparam_index_list.resize(0);
    funcdefnode_tmp_fparam_index_list.push_back(nullptr);
    $$ = nullptr;
  } |
  FuncFParamIndexList '[' Exp ']' {
    funcdefnode_tmp_fparam_index_list.push_back($3);
    $$ = nullptr;
  }
  ;

FuncType:
  VOID {
    FuncDefNode *new_node = new FuncDefNode(BasicType::VOID);
    funcdefnode_tmp_func_def_node = new_node;
    $$ = new_node;
  } |
  INT {
    FuncDefNode *new_node = new FuncDefNode(BasicType::INT);
    funcdefnode_tmp_func_def_node = new_node;
    $$ = new_node;
  } |
  FLOAT {
    FuncDefNode *new_node = new FuncDefNode(BasicType::FLOAT);
    funcdefnode_tmp_func_def_node = new_node;
    $$ = new_node;
  } |
  CHAR {
    FuncDefNode *new_node = new FuncDefNode(BasicType::CHAR);
    funcdefnode_tmp_func_def_node = new_node;
    $$ = new_node;
  }
  ;

%%