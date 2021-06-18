#!bin/bash

in_file="input.txt"

./objgen-unit-test.out < ${in_file}
clang output.o -o test
./test