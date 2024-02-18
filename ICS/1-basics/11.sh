#!/bin/bash

gcc 11.c -o 11.out

$RUN_WITH_VALGRIND ./11.out <<EOF
3824
EOF

$RUN_WITH_VALGRIND ./11.out <<EOF
525
EOF
