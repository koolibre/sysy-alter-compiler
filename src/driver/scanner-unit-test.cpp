#include <cstdio>
#include <cstdlib>

extern FILE *yyin;
extern FILE *yyout;
extern int yylex();

int main(int agrc, char **argv) {
#ifdef DEBUG
#ifdef SCANNER_DEBUG
  yyin = fopen(argv[1], "r");
  yyout = fopen(argv[2], "w");
  while(yylex()) {}
  return 0;
#endif
#endif
}