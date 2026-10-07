#!/bin/bash

x=1
N=1

while [[ x -ne $1+1 ]] do
	# echo $x $N
	echo -n $N

	if [[ x -ne $1 ]] then
		echo -n ", "
	fi
	
	((N++))
	((N++))

	((x++))
done
