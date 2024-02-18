#!/bin/bash

gcc 4-prime.c -o 4-prime.out

for VARIABLE in $(seq 0 100)
do
$RUN_WITH_VALGRIND ./4-prime.out <<EOF
$VARIABLE
EOF
done
