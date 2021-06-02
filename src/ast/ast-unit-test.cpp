#include <cassert>       // use assert()
#include <cstdio>        // use FILE*

#include <fstream>       // use std::ofstream std::streambuf

#include "ast/ast.hpp"   // use RootNode

extern void yyparse();
extern RootNode* root;
extern FILE *yyin;

int main(int argc, char **argv) {
#ifdef DEBUG
  using namespace std;
  yyin = fopen(argv[1], "r");
  streambuf *cout_buf = cout.rdbuf();
  ofstream output(argv[2]);
  streambuf *file_buf = output.rdbuf();
  cout.rdbuf(file_buf);
  assert(root != nullptr);
  yyparse();
#ifdef AST_DEBUG
  root->Print(0);
#endif
  output_stream.flush();
  output_stream.close();
#endif
  return 0;
}