#!/usr/bin/bash

# case condition

echo "is it morning? please answer yes or no"
read timeofday

case "$timeofday" in
	yes|y|Yes|YES) 	echo "good morning";;
	n*|N*)		echo "good afternoon";;
	*)		echo "sorry,answer not recognized";;
esac

exit 0
