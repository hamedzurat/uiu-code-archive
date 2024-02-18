#!/bin/bash

gcc 9.c -o 9.out

$RUN_WITH_VALGRIND ./9.out <<EOF
157
EOF

$RUN_WITH_VALGRIND ./9.out <<EOF
2309
EOF
