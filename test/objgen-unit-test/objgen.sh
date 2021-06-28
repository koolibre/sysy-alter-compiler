#!bin/bash

in_file="test2.txt"

./objgen-unit-test.out < ${in_file}
clang output.o -o test
./test
