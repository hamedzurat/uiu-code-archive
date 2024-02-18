#!/bin/bash

gcc 5.c -o 5.out

for VARIABLE in $(seq -3 512)
do
$RUN_WITH_VALGRIND ./5.out <<EOF
$VARIABLE
EOF
done
