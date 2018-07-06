#!/usr/bin/bash

echo "Is it morning? please answer yes or no"
read timeofday

if [ "$timeofday" = "yes" ]; then
	echo "good morning"
elif [ "$timeofday" = "no" ]; then
	echo "good afternoon"
else
	echo "Sorry,$timeofday not recognized.Enter yes or no"
	exit 1
fi

exit 0
