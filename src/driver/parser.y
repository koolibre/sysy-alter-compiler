%{
#ifndef DEBUG
  #define NDEBUG
#else
  #undef NDEBUG
  #define YYDEBUG 1
#endif

#include <cassert>     // use assert()

#include <iostream>    // use std::cout
#include <string>      // use std::string
#include <sstream>

#include "ast/ast.hpp" // use struct Node

#define YYSTYPE Node*
// output error message
// defined in scanner.cpp
extern void yyerror(const char *str);

// defined in scanner.cpp
extern int yylex();

extern int yylineno;


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
// TODO(kolibre) : finish error token
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
  } |
  ;

ConstDecl:
  CONST BType ConstDefList ';' {
    DeclNode *tmp_decl_node = dynamic_cast<DeclNode*>($3);
    assert(tmp_decl_node != nullptr);
    tmp_decl_node->SetBasicType();
    $$ = $3;
  } |
  CONST IDENT ConstDefList ';' {
    DeclNode *tmp_decl_node = dynamic_cast<DeclNode*>($3);
    assert(tmp_decl_node != nullptr);
    std::stringstream msg;
    msg << "[ERROR] Declaration to const value(s) at line " << dynamic_cast<Node*>($3)->line_no << " is omitted due to unknown type \"" << dynamic_cast<IdentNode*>($2)->GetIdent() << "\".";
    ErrorNode* new_node = new ErrorNode(msg.str(),dynamic_cast<Node*>($3)->line_no);
    $$ = new_node;
    delete tmp_decl_node;
    printf("%s\n",msg.str().c_str());
  } |
  CONST BType error ';' {
    std::stringstream msg;
    msg << "[ERROR] Declaration to const value(s) at line " << yylineno << " is omitted due to error(s) in the list of declaration.";
    ErrorNode* new_node = new ErrorNode(msg.str(),yylineno);
    $$ = new_node;
    printf("%s\n",msg.str().c_str());
  } |
  CONST IDENT error ';' {
    std::stringstream msg;
    msg << "[ERROR] Declaration to const value(s) at line " << dynamic_cast<Node*>($2)->line_no << " is omitted due to error(s) in the list of declaration and data type.";
    ErrorNode* new_node = new ErrorNode(msg.str(),dynamic_cast<Node*>($2)->line_no);
    $$ = new_node;
    printf("%s\n",msg.str().c_str());
  }
  ;

ConstDefList:
  ConstDef {
    DeclNode* new_decl_node = new DeclNode(NodeType::CONST_DECL,yylineno);
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
    $$ = new InitValNode(yylineno);
  }
  ;

ConstInitValList:
  ConstInitValList ',' ConstInitVal {
    dynamic_cast<InitValNode*>($1)->AddInitVal($3);
    $$ = $1;
  } |
  ConstInitVal {
    InitValNode *new_init_val_node = new InitValNode(yylineno);
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
  } |
  IDENT ConstDefList ';' {
    DeclNode *tmp_decl_node = dynamic_cast<DeclNode*>($2);
    assert(tmp_decl_node != nullptr);
    std::stringstream msg;
    msg << "[ERROR] Declaration to value(s) at line " << dynamic_cast<Node*>($2)->line_no << " is omitted due to unknown type \"" << dynamic_cast<IdentNode*>($1)->GetIdent() << "\".";
    ErrorNode* new_node = new ErrorNode(msg.str(),dynamic_cast<Node*>($2)->line_no);
    $$ = new_node;
    delete tmp_decl_node;
    printf("%s\n",msg.str().c_str());
  } |
  BType error ';' {
    std::stringstream msg;
    msg << "[ERROR] Declaration to value(s) at line " << yylineno << " is omitted due to error(s) in the list of declaration.";
    ErrorNode* new_node = new ErrorNode(msg.str(),yylineno);
    $$ = new_node;
    printf("%s\n",msg.str().c_str());
  } |
  IDENT error ';' {
    std::stringstream msg;
    msg << "[ERROR] Declaration to value(s) at line " << dynamic_cast<Node*>($1)->line_no << " is omitted due to error(s) in the list of declaration and data type.";
    ErrorNode* new_node = new ErrorNode(msg.str(),dynamic_cast<Node*>($1)->line_no);
    $$ = new_node;
    printf("%s\n",msg.str().c_str());
  }
  ;

VarDefList:
  VarDef {
    DeclNode* new_decl_node = new DeclNode(NodeType::VAR_DECL,yylineno);
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
    $$ = new InitValNode(yylineno);
  }
  ;

VarInitValList:
  VarInitValList ',' VarInitVal {
    dynamic_cast<InitValNode*>($1)->AddInitVal($3);
    $$ = $1;
  } |
  VarInitVal {
    InitValNode *new_init_val_node = new InitValNode(yylineno);
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
  } | 
  error {
    std::stringstream msg;
    msg << "[ERROR] Block or unknown in-block error found at line " << yylineno << ".";
    $$ = new ErrorNode(msg.str(),yylineno);
    printf("%s\n",msg.str().c_str());
  }
  ;

BlockItemList:
  /* empty */ {
    $$ = new BlockNode(yylineno);
    assert($$ != nullptr);
  } |
  BlockItemList BlockItem {
    BlockNode *tmp_block_node = dynamic_cast<BlockNode*>($1); 
    assert(tmp_block_node != nullptr);
    if($2->CheckNodeType(NodeType::ERROR)){
      tmp_block_node->AddError(dynamic_cast<ErrorNode*>($2));
      tmp_block_node->AddNode($2);
    } else {
      tmp_block_node->AddNode($2);
    }
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
    $$ = new ReturnStmtNode($2,yylineno);
  } |
  CONTINUE ';' {
    $$ = new ContinueStmtNode(yylineno);  
  } |
  BREAK ';' {
    $$ = new BreakStmtNode(yylineno);
  } | 
  WHILE '(' Cond ')' Stmt {
    $$ = new WhileStmtNode($3, $5,$3->line_no);
  } |
  IF '(' Cond ')' Stmt ElseChoice {
    $$ = new IfStmtNode($3, $5, $6,$3->line_no);
  } |
  Block {
    $$ = $1;
  } |
  ExpChoice ';' {
    $$ = $1;
  } |
  LVal '=' Exp ';' {
    $$ = new AssignStmtNode($1, $3,yylineno);
  } |
  WHILE error Stmt {
    std::stringstream msg;
    int start_line_no = 0;
    if($3==nullptr){
      start_line_no = yylineno;
    } else {
      start_line_no = $3->line_no;
    }
    msg << "[ERROR] While block at line " << start_line_no << " to " << yylineno << " is omitted due to error(s) found in its condition statement.";
    ErrorNode* new_node = new ErrorNode(msg.str(),yylineno);
    assert(new_node!=nullptr);
    printf("%s\n",msg.str().c_str());
    $$ = new_node;
    yyerrok;
  } |
  IF error Stmt ElseChoice {
    std::stringstream msg;
    int start_line_no = 0;
    if($3==nullptr){
      start_line_no = yylineno;
    } else {
      start_line_no = $3->line_no;
    }
    msg << "[ERROR] If block at line " << start_line_no << " to " << yylineno << " is omitted due to error(s) found in its condition statement.";
    ErrorNode* new_node = new ErrorNode(msg.str(),yylineno);
    assert(new_node!=nullptr);
    printf("%s\n",msg.str().c_str());
    $$ = new_node;
    yyerrok;
  } |
  error ';' {
    std::stringstream msg;
    msg << "[ERROR] Statement at line " << yylineno << " is omitted due to error(s) found in it.";
    ErrorNode* new_node = new ErrorNode(msg.str(),yylineno);
    printf("%s\n",msg.str().c_str());
    $$ = new_node;
    yyerrok;
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
    LValPrimaryExpNode* tmp_node = new LValPrimaryExpNode(dynamic_cast<IdentNode*>($1),yylineno);
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
    FuncCallExpNode* new_node = new FuncCallExpNode(yylineno);
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
    FuncCallExpNode *new_node = new FuncCallExpNode(yylineno);
    $$ = new_node;
  } |
  FuncRParamList ',' Exp {
    assert($1!=nullptr);
    dynamic_cast<FuncCallExpNode*>($1)->AddParam($3);
    $$ = $1;
  }
  ;

UnaryOp:
  '+' {
    UnaryExpNode *new_node = new UnaryExpNode(UnaryOpType::POSITIVE,yylineno);
    $$ = new_node;
  } |
  '-' {
    UnaryExpNode *new_node = new UnaryExpNode(UnaryOpType::NEGATIVE,yylineno);
    $$ = new_node;
  } |
  '!' {
    UnaryExpNode *new_node = new UnaryExpNode(UnaryOpType::NOT,yylineno);
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
    BinaryExpNode *new_node = new BinaryExpNode(BinaryOpType::MUL,yylineno);
    $$ = new_node;
  } |
  '/' {
    BinaryExpNode *new_node = new BinaryExpNode(BinaryOpType::DIV,yylineno);
    $$ = new_node;
  } |
  '%' {
    BinaryExpNode *new_node = new BinaryExpNode(BinaryOpType::MOD,yylineno);
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
    BinaryExpNode *new_node = new BinaryExpNode(BinaryOpType::ADD,yylineno);
    $$ = new_node;
  } |
  '-' {
    BinaryExpNode *new_node = new BinaryExpNode(BinaryOpType::SUB,yylineno);
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
    BinaryExpNode *new_node = new BinaryExpNode(BinaryOpType::LE,yylineno);
    $$ = new_node; 
  } |
  '>' {
    BinaryExpNode *new_node = new BinaryExpNode(BinaryOpType::GE,yylineno);
    $$ = new_node; 
  } |
  LEEQ {
    BinaryExpNode *new_node = new BinaryExpNode(BinaryOpType::LEEQ,yylineno);
    $$ = new_node; 
  } |
  GEEQ {
    BinaryExpNode *new_node = new BinaryExpNode(BinaryOpType::GEEQ,yylineno);
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
    BinaryExpNode *new_node = new BinaryExpNode(BinaryOpType::EQ,yylineno);
    $$ = new_node;
  } |
  UNEQ {
    BinaryExpNode *new_node = new BinaryExpNode(BinaryOpType::UNEQ,yylineno);
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
    BinaryExpNode *new_node = new BinaryExpNode(BinaryOpType::AND,yylineno);
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
    BinaryExpNode *new_node = new BinaryExpNode(BinaryOpType::OR,yylineno);
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
    assert($$!=nullptr);
    bool func_type_error = (dynamic_cast<FuncDefNode*>($2)->GetType() == BasicType::UNKNOWN);
    bool func_param_list_error = dynamic_cast<Node*>($$)->error_list_.size()>(func_type_error?1:0);
    if(func_type_error or func_param_list_error){
      std::stringstream msg;
      msg << "[ERROR] Function \"" << dynamic_cast<IdentNode*>($3)->GetIdent() << "\" at line " << dynamic_cast<Node*>($3)->line_no << " is omitted due to following error(s) in its declaration:\n";
      if(func_type_error){
        assert($$->error_list_.size()>0);
        msg << "  " << "Unknown return type \"" << dynamic_cast<ErrorNode*>($$->error_list_[0])->err_msg << "\".\n";
        $$->error_list_.erase($$->error_list_.begin());
      }
      if(func_param_list_error){
        for (auto iter: dynamic_cast<Node*>($$)->error_list_){
          msg << "  " << dynamic_cast<ErrorNode*>(&(*iter)) -> err_msg << ".\n";
        }
      }
      ErrorNode *new_node = new ErrorNode(msg.str(),dynamic_cast<Node*>($3)->line_no);
      printf("%s",msg.str().c_str());
      delete $$;
      $$ = new_node;
    }
    yyerrok;
  } |
  DEF FuncType IDENT '(' ')' Block {
    dynamic_cast<FuncDefNode*>($2)->SetIdent(dynamic_cast<IdentNode*>($3));
    dynamic_cast<FuncDefNode*>($2)->SetBlock($6);
    $$ = funcdefnode_tmp_func_def_node;
    assert($$!=nullptr);
    bool func_type_error = (dynamic_cast<FuncDefNode*>($2)->GetType() == BasicType::UNKNOWN);
    if(func_type_error){
      std::stringstream msg;
      msg << "[ERROR] Function \"" << dynamic_cast<IdentNode*>($3)->GetIdent() << "\" at line " << dynamic_cast<Node*>($3)->line_no << " is omitted due to following error(s) in its declaration:\n";
      assert($$->error_list_.size()>0);
      msg << "  " << "Unknown return type \"" << dynamic_cast<ErrorNode*>($$->error_list_[0])->err_msg << "\".\n";
      $$->error_list_.erase($$->error_list_.begin());
      ErrorNode *new_node = new ErrorNode(msg.str(),dynamic_cast<Node*>($3)->line_no);
      printf("%s",msg.str().c_str());
      delete $$;
      $$ = new_node;
    }
    yyerrok;
  } |
  IDENT FuncType IDENT '(' FuncFParamList ')' Block {
    if(funcdefnode_tmp_func_def_node!=nullptr){
      delete funcdefnode_tmp_func_def_node;
    }
    std::stringstream msg;
    msg << "[ERROR] An unit seems to be a declaration of a function at line " << yylineno << " is omitted.";
    ErrorNode *new_node = new ErrorNode(msg.str(),yylineno);
    printf("%s\n",msg.str().c_str());
    $$ = new_node;
    yyerrok;
  } |
  IDENT FuncType IDENT '(' ')' Block {
    if(funcdefnode_tmp_func_def_node!=nullptr){
      delete funcdefnode_tmp_func_def_node;
    }
    std::stringstream msg;
    msg << "[ERROR] An unit seems to be a declaration of a function at line " << yylineno << " is omitted.";
    ErrorNode *new_node = new ErrorNode(msg.str(),yylineno);
    printf("%s\n",msg.str().c_str());
    $$ = new_node;
    yyerrok;
  } |
  DEF FuncType IDENT error Block {
    std::stringstream msg;
    msg << "[ERROR] Function \"" << dynamic_cast<IdentNode*>($3)->GetIdent() << "\" at line " << $2->line_no << " is omitted due to error(s) found in its param list.";
    ErrorNode* new_node = new ErrorNode(msg.str(),$2->line_no);
    $$ = new_node;
    printf("%s\n",msg.str().c_str());
  }
  ;

FuncFParamList:
  FuncFParam {
    assert($1!=nullptr);
    if(dynamic_cast<Node*>($1)->CheckNodeType(NodeType::IDENT)){
      assert(funcdefnode_tmp_func_def_node!=nullptr);
      funcdefnode_tmp_func_def_node->AddParam(dynamic_cast<IdentNode*>($1));
    }
    else if(dynamic_cast<Node*>($1)->CheckNodeType(NodeType::ERROR)){
      dynamic_cast<Node*>(funcdefnode_tmp_func_def_node)->AddError(dynamic_cast<Node*>($1));
    }
    $$ = nullptr;
  } |
  FuncFParamList ',' FuncFParam {
    assert($3!=nullptr);
    if(dynamic_cast<Node*>($3)->CheckNodeType(NodeType::IDENT)){
      assert(funcdefnode_tmp_func_def_node!=nullptr);
      funcdefnode_tmp_func_def_node->AddParam(dynamic_cast<IdentNode*>($3));
    }
    else if(dynamic_cast<Node*>($3)->CheckNodeType(NodeType::ERROR)){
      dynamic_cast<Node*>(funcdefnode_tmp_func_def_node)->AddError(dynamic_cast<Node*>($3));
    }
    $$ = nullptr;
  }
  ;

FuncFParam:
  BType IDENT {
    $$ = $2;
  } |
  BType IDENT '[' ']' FuncFParamIndexList {
    $$ = $2;
  } |
  IDENT IDENT {
    assert($1!=nullptr);
    std::stringstream msg;
    msg << "Unknown data type \"" << dynamic_cast<IdentNode*>($1)->GetIdent() << "\" for param \"" << dynamic_cast<IdentNode*>($2)->GetIdent() << "\"";
    ErrorNode *new_node = new ErrorNode(msg.str(),dynamic_cast<IdentNode*>($2)->line_no);
        assert(new_node!=nullptr);
    $$ = new_node;
  } |
  IDENT IDENT '[' ']' FuncFParamIndexList {
    assert($1!=nullptr);
    std::stringstream msg;
    msg << "Unknown data type \"" << dynamic_cast<IdentNode*>($1)->GetIdent() << "[]\" for param \"" << dynamic_cast<IdentNode*>($2)->GetIdent() << "\"";
    ErrorNode *new_node = new ErrorNode(msg.str(),dynamic_cast<IdentNode*>($2)->line_no);
    assert(new_node!=nullptr);
    $$ = new_node;
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
    FuncDefNode *new_node = new FuncDefNode(BasicType::VOID,yylineno);
    funcdefnode_tmp_func_def_node = new_node;
    $$ = new_node;
  } |
  INT {
    FuncDefNode *new_node = new FuncDefNode(BasicType::INT,yylineno);
    funcdefnode_tmp_func_def_node = new_node;
    $$ = new_node;
  } |
  FLOAT {
    FuncDefNode *new_node = new FuncDefNode(BasicType::FLOAT,yylineno);
    funcdefnode_tmp_func_def_node = new_node;
    $$ = new_node;
  } |
  CHAR {
    FuncDefNode *new_node = new FuncDefNode(BasicType::CHAR,yylineno);
    funcdefnode_tmp_func_def_node = new_node;
    $$ = new_node;
  } |
  IDENT {
    FuncDefNode *new_node = new FuncDefNode(BasicType::UNKNOWN,yylineno);
    ErrorNode* error_info = new ErrorNode(dynamic_cast<IdentNode*>($1)->GetIdent(),yylineno);
    new_node -> AddError(error_info);
    funcdefnode_tmp_func_def_node = new_node;
    $$ = new_node;
  }
  ;

%%