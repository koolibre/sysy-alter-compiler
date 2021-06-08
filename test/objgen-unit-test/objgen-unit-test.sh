#!/bin/bash

flex -o ../../src/driver/scanner.cpp ../../src/driver/scanner.l
bison -o ../../src/driver/parser.cpp -d ../../src/driver/parser.y -v
g++ \
-o ./objgen-unit-test.out \
../../src/obj-gen/obj-gen-unit-test.cpp \
../../src/driver/scanner.cpp ../../src/driver/parser.cpp ../../src/ast/ast.cpp \
../../src/obj-gen/obj-gen.cpp ../../src/ir-gen/ir-gen.cpp ../../src/ir-gen/symbol-table.cpp ../../src/ir-gen/type-system.cpp \
-I/usr/lib/llvm-11/include -D_GNU_SOURCE -D__STDC_CONSTANT_MACROS -D__STDC_FORMAT_MACROS -D__STDC_LIMIT_MACROS -std=gnu++17 \
-L/usr/lib/llvm-11/lib -lpthread -ldl -lz -lncurses -rdynamic -L/usr/local/lib \
-lLLVM-11 \
-lfl -lm -I ../../src/ -g -DDEBUG -DAST_DEBUG

