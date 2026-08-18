#!/bin/bash

read -p "Number: " input

temp=$input
rev=0

while [[ $temp -ne 0 ]]; do
	digit=$((temp % 10))
	temp=$((temp / 10))

	rev=$((rev * 10 + digit))

	# echo "d: $digit | t: $temp | r: $rev"
done

if [[ $rev -eq $input ]] then
	echo "$input is pailndrome"
else
	echo "$input is not pailndrome"
fi


# echo $temp
