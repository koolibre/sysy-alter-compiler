#!/bin/bash

flex -o ../../src/driver/scanner.cpp ../../src/driver/scanner.l
bison -o ../../src/driver/parser.cpp -d ../../src/driver/parser.y -v
g++ \
-o ./ast-unit-test.out ../../src/driver/scanner.cpp ../../src/driver/parser.cpp ../../src/ast/ast.cpp ../../src/ast/ast-unit-test.cpp \
-I/usr/lib/llvm-10/include -D_GNU_SOURCE -D__STDC_CONSTANT_MACROS -D__STDC_FORMAT_MACROS -D__STDC_LIMIT_MACROS \
-L/usr/include/llvm/lib -lpthread -ldl  -lncurses -rdynamic -L/usr/local/lib \
-lLLVM-10 \
-lfl --std=gnu++17 -lm -I \
../../src/ -g -DDEBUG -DAST_DEBUG
rm ../../src/driver/scanner.cpp ../../src/driver/parser.cpp ../../src/driver/parser.hpp ../../src/driver/parser.output
./ast-unit-test.out input.txt output.txt
#rm ./ast-unit-test.out
