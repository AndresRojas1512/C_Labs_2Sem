#!/bin/bash

file_01="$1"
file_02="$2"

if diff -q "$file_01" "$file_02" >/dev/null ; then
    exit 0
else
    exit 1
fi