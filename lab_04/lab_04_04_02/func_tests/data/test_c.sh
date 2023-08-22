#!/bin/bash

for i in $(seq -f "%02g" 16 30)
do
    touch "pos_${i}_in.txt"
    touch "pos_${i}_out.txt"
done