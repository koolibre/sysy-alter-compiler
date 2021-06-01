#!/bin/bash

var=$(pwd)

flex -o ../../src/driver/scanner.cpp ../../src/driver/scanner.l
bison -o ../../src/driver/parser.cpp -d ../../src/driver/parser.y -v
g++ -o ./ast-unit-test.out ../../src/driver/scanner.cpp ../../src/driver/parser.cpp ../../src/ast/ast.cpp ../../src/ast/ast-unit-test.cpp -lfl -lm -I ../../src/ -DDEBUG -DAST_DEBUG
rm ../../src/driver/scanner.cpp ../../src/driver/parser.cpp ../../src/driver/parser.hpp ../../src/driver/parser.output
./ast-unit-test.out input.txt output.txt
rm ./ast-unit-test.out