#!bin/bash

flex -o ../src/driver/scanner.cpp ../src/driver/scanner.l
bison -b parser -d ../src/driver/parser.y
g++ -o ./scanner-unit-test.out ../src/driver/scanner.cpp ../src/driver/parser.cpp -lfl -lm -I ../src/
./scanner-unit-test.out test1.in test1.out