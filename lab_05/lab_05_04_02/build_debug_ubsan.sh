#!/bin/bash

SOURCE_FILE=*.c
OUT_FILE=app.exe

clang -std=c99 -g -Wall -Werror -Wextra -Wunused -Wpedantic -Wfloat-equal -Wfloat-conversion -Wvla -fsanitize=undefined -fprofile-arcs -ftest-coverage -c $SOURCE_FILE -fsanitize=undefined
clang -std=c99 -g -Wall -Werror -Wextra -Wunused -Wpedantic -Wfloat-equal -Wfloat-conversion -Wvla -fsanitize=undefined -fprofile-arcs -ftest-coverage *.o -o $OUT_FILE -lm -fsanitize=undefined