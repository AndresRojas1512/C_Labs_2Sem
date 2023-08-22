#!/bin/bash

SOURCE_FILE=*.c
OUT_FILE=app.exe

gcc -std=c99 -g -Wall -Werror -Wextra -Wunused -Wpedantic -Wfloat-equal -Wfloat-conversion -Wvla --coverage -fprofile-arcs -ftest-coverage -c $SOURCE_FILE -lm
gcc -std=c99 -g -Wall -Werror -Wextra -Wunused -Wpedantic -Wfloat-equal -Wfloat-conversion -Wvla --coverage -fprofile-arcs -ftest-coverage *.o -o $OUT_FILE -lm