#!/bin/bash

gcc 12.c -o 12.out

$RUN_WITH_VALGRIND ./12.out <<EOF
1627
EOF

$RUN_WITH_VALGRIND ./12.out <<EOF
789
EOF
