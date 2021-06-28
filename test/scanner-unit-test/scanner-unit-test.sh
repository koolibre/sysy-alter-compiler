#!/bin/bash

var=$(pwd)

flex -o ../../src/driver/scanner.cpp ../../src/driver/scanner.l
bison -o ../../src/driver/parser.cpp -d ../../src/driver/parser.y -v
g++ \
-o ./scanner-unit-test.out ../../src/driver/scanner.cpp ../../src/driver/parser.cpp ../../src/ast/ast.cpp ../../src/driver/scanner-unit-test.cpp \
-I/usr/lib/llvm-11/include -D_GNU_SOURCE -D__STDC_CONSTANT_MACROS -D__STDC_FORMAT_MACROS -D__STDC_LIMIT_MACROS -std=gnu++17 \
-L/usr/include/llvm/lib -lpthread -ldl -lz -lncurses -rdynamic -L/usr/local/lib \
-lLLVM-11 \
-lfl -lm -I ../../src/ -DDEBUG -DAST_DEBUG -DSCANNER_DEBUG
rm ../../src/driver/scanner.cpp ../../src/driver/parser.cpp ../../src/driver/parser.hpp ../../src/driver/parser.output
./scanner-unit-test.out input.txt output.txt
rm ./scanner-unit-test.out
