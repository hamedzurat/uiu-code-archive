#!/usr/bin/env bash

set -e

log() {
	echo -e "\e[34m[LOG]\e[0m $1"
}

error_log() {
	echo -e "\e[31m[ERROR]\e[0m $1"
}

trap 'error_log "An error occurred during formatting."; exit 1' ERR

if ! command -v parallel &>/dev/null; then
	error_log "parallel is not installed."
	exit 1
fi

if command -v prettier &>/dev/null; then
	log "Running prettier"
	prettier --write --ignore-unknown .
fi

if command -v clang-format &>/dev/null; then
	log "Running clang-format"
	find . -type f \( -name "*.c" -o -name "*.cpp" -o -name "*.cc" -o -name "*.cxx" -o -name "*.h" -o -name "*.hpp" -o -name "*.hh" -o -name "*.hxx" -o -name "*.ino" \) -print0 | xargs -0 -r clang-format -i
fi

if command -v pg_format &>/dev/null; then
	log "Running pg_format"
	find . -type f -name '*.sql' -print0 | parallel -0 --no-run-if-empty pg_format -i {}
fi

if command -v php-cs-fixer &>/dev/null; then
	log "Running php-cs-fixer"
	php-cs-fixer fix .
fi

log "Formatting complete"
