#!/bin/bash

var=$(pwd)

flex -o ../../src/driver/scanner.cpp ../../src/driver/scanner.l
bison -o ../../src/driver/parser.cpp -d ../../src/driver/parser.y -v
g++ -o ./scanner-unit-test.out ../../src/driver/scanner.cpp ../../src/driver/parser.cpp ../../src/ast/ast.cpp ../../src/driver/scanner-unit-test.cpp -lfl -lm -I ../../src/ -DDEBUG -DSCANNER_DEBUG
rm ../../src/driver/scanner.cpp ../../src/driver/parser.cpp ../../src/driver/parser.hpp ../../src/driver/parser.output
./scanner-unit-test.out input.txt output.txt
rm ./scanner-unit-test.out