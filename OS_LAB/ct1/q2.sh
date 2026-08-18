#!/bin/bash

read -p "N = " input

i=0
sum_even=0
sum_odd=0
diff=0

while [[ i -ne input+1 ]]
do	
	is_even=$((i%2))

	if [[ is_even -eq 0 ]] then
		sum_even=$((sum_even+i))
	else
		sum_odd=$((sum_odd+i))
	fi
	
	# echo "$i | $is_even | $sum_even | $sum_odd"
	((i++))
done

if [[ sum_even -gt sum_odd ]] then
	diff=$((sum_even-sum_odd))
else
	diff=$((sum_odd-sum_even))
fi

echo "Even sum = $sum_even"
echo "Odd sum = $sum_odd"
echo "Diff = $diff"

