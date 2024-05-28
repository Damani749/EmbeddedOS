#!/bin/bash

echo "Enter choice :"
read choice

case $choice in
1)
	date
	;;
2)
	cal
	;;
3)
	ls
	;;
4)	
	pwd
	;;
5)
	exit
	;;
esac
