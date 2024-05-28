#!/bin/bash

echo -n "Enter num: "
read num
if (( num==2 ))
then
	echo "2 is a prime no"

elif (( num==3 ))
then
	echo "3 is a prime no"
else
	for (( i=2; i <= num/2; i++ ))
	do
    
		if (( num%i==0 ))
		then
			echo "$num is not a prime no"
		elif (( i==num/2 ))
		then
			echo "$num is a prime no"
		fi

	done
fi
