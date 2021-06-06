character [a-zA-Z]
digit [0-9]
Ident {character}({character}|"_"|{digit})*
IntConst {digit}+
floatConst ({digit}+\.{digit}*|({digit}*\.{digit}+))
CharConst '{character}'
StringConst \"[^\"]*\"
comment_typeone "//"
comment_typetwo "/*"([^\*]|(\*)*[^\*/])*(\*)*"*/"
symbol [,;\[\]{}+\-!\*/\%<>=\(\)]

%option yylineno

%{
#ifndef DEBUG
  #define NDEBUG
#else
  #undef NDEBUG
#endif

#include <cassert>            // use assert()
#include <cstdlib>            // use atoi() atof()
#include <cstdio>             // use fopen()

#include <iostream>           // use std::cout
#include <string>             // use std::string

#include "ast/ast.hpp"        // use nodes
#define YYSTYPE Node*
#include "driver/parser.hpp"  // generated from parser.y

// yyerror was defined in parser.cpp
void yyerror(const char *);

// for unit test, output scanning result
inline void test_output(const char *type) {
#ifdef DEBUG
#ifdef SCANNER_DEBUG
  fprintf(yyout, "%s: ~%s~\n", type, yytext);
#endif
#endif
}
%}

%%

<<EOF>> {
  return 0;
}

{comment_typetwo} {
  test_output("comment_typetwo");
} /* comment_typetwo */

{comment_typeone}.* {
  test_output("comment_typeone");
} /* comment_typeone*/

"def" {
  test_output("keyword");
  yylval = nullptr;
  return DEF;
}

"const" {
  test_output("keyword");
  yylval = nullptr;
  return CONST;
} /* keyword */

"int" {
  test_output("keyword");
  yylval = nullptr;
  return INT;
} /* keyword */

"float" {
  test_output("keyword");
  yylval = nullptr;
  return FLOAT;
} /* keyword */

"char" {
  test_output("keyword");
  yylval = nullptr;
  return CHAR;
} /* keyword */

"void" {
  test_output("keyword");
  yylval = nullptr;
  return VOID;
} /* keyword */

"if" {
  test_output("keyword");
  yylval = nullptr;
  return IF;
} /* keyword */

"else" {
  test_output("keyword");
  yylval = nullptr;
  return ELSE;
} /* keyword */

"while" {
  test_output("keyword");
  yylval = nullptr;
  return WHILE;
} /* keyword */

"break" {
  test_output("keyword");
  yylval = nullptr;
  return BREAK;
} /* keyword */

"continue" {
  test_output("keyword");
  yylval = nullptr;
  return CONTINUE;
} /* keyword */

"return" {
  test_output("keyword");
  yylval = nullptr;
  return RETURN;
} /* keyword */

{symbol} {
  test_output("symbol1");
  yylval = nullptr;
  return *(char*)(yytext);
} /* symbol with one character */

"<=" {
  test_output("symbol2");
  yylval = nullptr;
  return LEEQ;
} /* symbol with two characters */

">=" {
  test_output("symbol2");
  yylval = nullptr;
  return GEEQ;
} /* symbol with two characters */

"==" {
  test_output("symbol2");
  yylval = nullptr;
  return EQ;
} /* symbol with two characters */

"!=" {
  test_output("symbol2");
  yylval = nullptr;
  return UNEQ;
} /* symbol with two characters */

"&&" {
  test_output("symbol2");
  yylval = nullptr;
  return AND;
} /* symbol with two characters */

"||" {
  test_output("symbol2");
  yylval = nullptr;
  return OR;  
} /* symbol with two characters */

{Ident} {
  test_output("Ident");
  Node *new_node = new IdentNode(std::string(yytext),yylineno);
  assert(new_node != nullptr);
  yylval = new_node;
  return IDENT;
} /* identifier */

[ \t\n]+ /* eat up white space */

{IntConst} {
  test_output("IntConst");
  Node* new_node = new ValuePrimaryExpNode<int>(NodeType::INT_PRIMARY_EXP, atoi(yytext),yylineno);
  assert(new_node != nullptr);
  yylval = new_node;
  return INT_CONST;
} /* int literal */

{floatConst} {
  test_output("floatConst");
  Node* new_node = new ValuePrimaryExpNode<float>(NodeType::FLOAT_PRIMARY_EXP, atof(yytext),yylineno);
  assert(new_node != nullptr);
  yylval = new_node;
  return FLOAT_CONST;
} /* float literal */

{CharConst} {
  test_output("CharConst");
  Node* new_node = new ValuePrimaryExpNode<char>(NodeType::CHAR_PRIMARY_EXP, *((char*)yytext + 1),yylineno);
  assert(new_node != nullptr);
  yylval = new_node;
  return CHAR_CONST;
} /* char literal */

{StringConst} {
  if (yytext[yyleng-2] == '\\') {
    yyless(yyleng-1);
    yymore();
  } else {
    test_output("StringConst");
    Node* new_node = new ValuePrimaryExpNode<std::string>(NodeType::STRING_PRIMARY_EXP, std::string(yytext),yylineno);
    assert(new_node != nullptr);
    yylval = new_node;
    return STRING_CONST;
  }

} /* string literal */

. {
#ifdef DEBUG
#ifdef SCANNER_DEBUG
  fprintf(yyout, "unknown symbol: ~%s~\n", yytext);
#endif
#endif
  // return ERROR;
}/* error */

%%

int yywrap() {
  return 1;
}

void yyerror(const char *str) {
  assert(str != nullptr);
  fprintf(yyout,"//line %d: ",yylineno);
  fprintf(yyout,"%s\n", str);
}