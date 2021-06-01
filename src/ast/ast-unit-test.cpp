#include <cassert>       // use assert()
#include <cstdio>        // use FILE*

#include <fstream>       // use std::ofstream std::streambuf

#include "ast/ast.hpp"   // use RootNode

extern RootNode* root;
extern void yyparse();
extern FILE *yyin, *yyout;

int main(int argc, char **argv) {
#ifdef DEBUG
  using namespace std;
  streambuf *cout_buf = cout.rdbuf();
  ofstream output_stream(argv[2]);
  streambuf *file_buf = of.rdbuf();
  cout.rdbuf(file_buf);
  yyparse();
  assert(root != nullptr);
#ifdef AST_DEBUG
  root->Print();
#endif
  output_stream.flush();
  output_stream.close();
#endif
  return 0;
}