#!/bin/bash

gcc number-systems-integer-to-binary.c -o number-systems-integer-to-binary.out -lm

for VARIABLE in $(seq -4 256)
do
$RUN_WITH_VALGRIND ./number-systems-integer-to-binary.out <<EOF
$VARIABLE
EOF
done
