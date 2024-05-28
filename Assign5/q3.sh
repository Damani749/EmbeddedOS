#!/bin/bash

echo "Enter name:"
read name

if [ -e $name ]
then
	if [ -f $name ]
	then
		stat -c %s $name
	else
		ls -1
	fi

fi
