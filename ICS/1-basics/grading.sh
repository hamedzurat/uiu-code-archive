#!/bin/bash

gcc grading.c -o grading.out

for VARIABLE in $(seq -3 103)
do
$RUN_WITH_VALGRIND ./grading.out <<EOF
$VARIABLE
EOF
done
