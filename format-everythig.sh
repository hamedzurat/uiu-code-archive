#!/bin/bash

find . -name "*.c" -exec clang-format  -i {} +

echo "Formatting complete."
