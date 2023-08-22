#!/bin/bash

SOURCE_FILE=*.c
OUT_FILE=app.exe

clang -std=c99 -g -Wall -Werror -Wextra -Wunused -Wpedantic -Wfloat-equal -Wfloat-conversion -Wvla -fsanitize=address -fno-omit-frame-pointer -fprofile-arcs -ftest-coverage -c $SOURCE_FILE -fsanitize=address
clang -std=c99 -g -Wall -Werror -Wextra -Wunused -Wpedantic -Wfloat-equal -Wfloat-conversion -Wvla -fsanitize=address -fno-omit-frame-pointer -fprofile-arcs -ftest-coverage *.o -o $OUT_FILE -lm -fsanitize=address
