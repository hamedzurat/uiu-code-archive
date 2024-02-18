#!/bin/bash

gcc 10.c -o 10.out

$RUN_WITH_VALGRIND ./10.out <<EOF
57
EOF

$RUN_WITH_VALGRIND ./10.out <<EOF
79
EOF
