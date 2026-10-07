#!/bin/bash

sum=0
p=0
n=0

while read -r num; do
    if [[ $num -eq 0 ]]; then
        break
    fi

    sum=$((sum + num))

    if [[ $num -gt 0 ]]; then
        ((p++))
    elif [[ $num -lt 0 ]]; then
        ((n++))
    fi
done

echo "Sum: $sum"
echo "Positive numbers: $p"
echo "Negative numbers: $n"
