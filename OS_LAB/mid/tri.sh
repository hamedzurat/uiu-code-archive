#!/bin/bash

# echo "input: $1 $2 $3"

if [[ $1 -lt 0 || $2 -lt 0 || $3 -lt 0 || $1+$2 -le $3 || $2+$3 -le $1 || $3+$1 -le $2 ]] then
	echo "invalid"
else
	echo "valid"
fi

