#!/bin/bash

prettier --write .

find . \( -name "*.c" -o -name "*.cpp" -o -name "*.cc" -o -name "*.cxx" -o -name "*.h" -o -name "*.hpp" -o -name "*.hh" -o -name "*.hxx" -o -name "*.ino" \) -exec clang-format -i {} +

find . -type f -name '*.sql' -print0 | parallel -0 --no-run-if-empty pg_format -i

php-cs-fixer fix

echo "Formatting complete."
