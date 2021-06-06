#!/bin/bash 
g++ \
-I/usr/lib/llvm-11/include -D_GNU_SOURCE -D__STDC_CONSTANT_MACROS -D__STDC_FORMAT_MACROS -D__STDC_LIMIT_MACROS -std=gnu++17 \
-L/usr/lib/llvm-11/lib -lpthread -ldl -lz -lncurses -rdynamic -L/usr/local/lib \
-lLLVM-11 \
-o ./irgen-unit-test.out \
../../src/ir-gen/ir-gen.cpp ../../src/ir-gen/symbol-table.cpp ../../src/ir-gen/type-system.cpp \
-I ../../src/ -g -DAST_DEBUG

