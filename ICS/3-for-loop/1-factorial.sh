#!/bin/bash

gcc 1-factorial.c -o 1-factorial.out

for VARIABLE in $(seq 0 10)
do
$RUN_WITH_VALGRIND ./1-factorial.out <<EOF
$VARIABLE
EOF
done
