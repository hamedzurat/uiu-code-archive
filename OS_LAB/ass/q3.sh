#!/bin/bash

pass="12345"
max=3

while [[ $max -gt 0 ]]; do
    read -p "Enter password: " entered_password
    if [[ "$entered_password" == "$pass" ]]; then
        echo "Login Successful"
        exit 0
    else
        ((max--))
        if [[ $max -gt 0 ]]; then
            echo "Incorrect password. max remaining: $max"
        else
            echo "Account Locked"
        fi
    fi
done
