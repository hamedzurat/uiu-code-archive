#!/bin/bash

gcc number-systems-binary-to-integer.c -o number-systems-binary-to-integer.out -lm

for VARIABLE in 0 1 10 11 100 101 110 111 1000 1001 1010 1011 1100 1101 1110 1111 10000
do
$RUN_WITH_VALGRIND ./number-systems-binary-to-integer.out <<EOF
$VARIABLE
EOF
done
