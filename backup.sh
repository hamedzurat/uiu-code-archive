#!/bin/bash

kernel=$(uname -o)
get_distro_name() {
	if [ "$kernel" = "Android" ]; then
		echo "$(getprop ro.product.brand) $(getprop ro.product.model)"
	elif [ "$kernel" = "Darwin" ]; then
		echo "macOS $(uname) $(sw_vers -productVersion)"
	elif [ "$kernel" = "Msys" ]; then
		echo "windows $(uname)"
	else
		awk -F '"' '/PRETTY_NAME/ { print $2 }' /etc/os-release
	fi
}

echo "commiting..."
echo "--------------------------------"
git commit -m "backup from ($(get_distro_name)) on \"$(date +%F--%R)\""
