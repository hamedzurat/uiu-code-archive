#!/bin/bash

find . \( -name "*.c" -o -name "*.cpp" -o -name "*.cc" -o -name "*.cxx" -o -name "*.h" -o -name "*.hpp" -o -name "*.hh" -o -name "*.hxx" \) -exec clang-format -i {} +

echo "Formatting complete."
