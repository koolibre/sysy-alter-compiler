#!bin/bash

in_file="test1.c"

./objgen-unit-test.out < ${in_file}
clang output.o -o qs
./qs
