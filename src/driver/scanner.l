character [a-zA-Z]
digit [0-9]
Ident {character}({character}|"_"|{digit})*
IntConst [+-]?{digit}+
floatConst [+-]?({digit}+\.{digit}* | {digit}*\.{digit}+)
CharConst '{character}'
StringConst \"[^\"]*\"
comment_typeone "//"
comment_typetwo "/*"([^\*]|(\*)*[^\*/])*(\*)*"*/"
symbol1 [","";""[""]""{""}""+""-""!""*""/""%""<"">""="]
keyword "const" | "int" | "float" | "char" | "void" | "if" | "else" | "while" | "break" | "continue" | "return"

%option yylineno

%{
#define DEBUG
#ifndef DEBUG
  #define NDEBUG
#else
  #undef NDEBUG
#endif

#include "driver/parser.hpp" // generated from parser.y

#include <cassert> // use assert()
#include <cstdlib> // use atoi() atof()
#include <cstdio> // use fopen()

#include <iostream> // use std::cout
#include <string> // use std::string

#include "ast/ast.hpp" // use nodes

// yyerror was defined in parser.cpp
extern void yyerror(char *);

// for unit test, output scanning result
inline void test_output(const char *type) {
#ifdef DEBUG
  std::cout << std::string(type) << ": ~" << std::string(yytext) << "~"  << std::endl;
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

{comment_typeone} {
  std::cout << "comment_typeone: ~//";
  char c = input();
  std::cout << c;
  while (c != '\n' || c != EOF) {
    std::cout << c;
    c = input();
  }
  std::cout << "~" << std::endl;
} /* comment_typeone*/

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

{symbol1} {
  test_output("symbol1");
  yyval = nullptr;
  return *dynamic_cast<char*>(yytext);
} /* symbol with one character */

"<=" {
  test_output("symbol2");
  yyval = nullptr;
  return LEEQ;
} /* symbol with two characters */

">=" {
  test_output("symbol2");
  yyval = nullptr;
  return GEEQ;
} /* symbol with two characters */

"==" {
  test_output("symbol2");
  yyval = nullptr;
  return EQ;
} /* symbol with two characters */

"!=" {
  test_output("symbol2");
  yyval = nullptr;
  return UNEQ;
} /* symbol with two characters */

"&&" {
  test_output("symbol2");
  yyval = nullptr;
  return AND;
} /* symbol with two characters */

"||" {
  test_output("symbol2");
  yyval = nullptr;
  return OR;  
} /* symbol with two characters */

{Ident} {
  test_output("Ident");
  Node *new_node = new IdentNode(std::string(yytext));
  assert(new_node != nullptr);
  yylval = new_node;
  return IDENT;
} /* identifier */

[\t\n]+ /* eat up white space */

{IntConst} {
  test_output("IntConst");
  Node* new_node = new ValuePrimaryExpNode<int>(
      NodeType::INT_PRIMARY_EXP,
      atoi(yytext));
  assert(new_node != nullptr);
  yylval = new_node;
  return INT_CONST;
} /* int literal */

{floatConst} {
  test_output("floatConst");
  Node* new_node = new ValuePrimaryExpNode<float>(
      NodeType::FLOAT_PRIMARY_EXP,
      atoi(yytext));
  assert(new_node != nullptr);
  yylval = new_node;
  return FLOAT_CONST;
} /* float literal */

{CharConst} {
  test_output("CharConst");
  Node* new_node = new ValuePrimaryExpNode<char>(
      NodeType::CHAR_PRIMARY_EXP,
      atoi(yytext));
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
    Node* new_node = new ValuePrimaryExpNode<std::string>(
        NodeType::STRING_PRIMARY_EXP,
        std::string(yytext));
    assert(new_node != nullptr);
    yylval = new_node;
    return STRING_CONST;
  }

} /* string literal */

. {
#ifdef DEBUG
  yyerror("unknown symbol");
#endif
  // return ERROR;
}/* error */

%%

int yywrap() {
  return 1;
}