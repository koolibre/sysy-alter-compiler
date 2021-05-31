#include <cstdio>
#include <cstdlib>

extern FILE *yyin;
extern FILE *yyout;

int main(int agrc, char **argv) {
  yyin = fopen(agrv[1]);
  while(yylex()) {}
  return 0;
}