#!/bin/bash

read -p "Enter number: " num

e=0
o=0
z=0
sum=0

while read -n 1 digit; do
    if [[ $digit -eq 0 ]]; then
        ((z++))
    elif [[ $((digit % 2)) -eq 0 ]]; then
        ((e++))
        ((sum += digit))
    else
        ((o++))
    fi
done <<< "$num"

echo "Even digits: $e"
echo "Odd digits: $o"
echo "Zero digits: $z"
echo "Sum of even digits: $sum"
