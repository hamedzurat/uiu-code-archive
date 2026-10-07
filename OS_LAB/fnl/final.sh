#!/bin/bash

temp(){
  H=0
  L=999999
  A=0
  count=1
  sum=0

  while [[ $1 -ge 1 ]]; do
    read x

    if [[ x -gt $H ]]; then
      H=$x
    fi

    if [[ x -lt $L ]]; then
      L=$x
    fi

    sum=$((sum+x))
    A=$((sum/count))
    
    ((count++))
    ((n--))
  done

  echo "Lowest Temp: $L"
  echo "Avg Temp: $A"
  
  return $H
}

read -p "Enter number of records: " n
echo "Enter temperatures:"

temp n
echo "Retured Highest Temp: $?"
