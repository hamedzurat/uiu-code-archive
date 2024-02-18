#!/bin/bash

gcc 6.c -o 6.out

for VARIABLE in $(seq -16 512)
do
$RUN_WITH_VALGRIND ./6.out <<EOF
$VARIABLE
EOF
done
