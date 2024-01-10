#!/bin/bash

if [ $# -ne 3 ];then
	echo "Not enough arguements:">&2
	exit
fi

if [ $3 -eq 1 ];then
	echo $(($1+$2))
	exit
elif [ $3 -eq 2 ];then
	echo $(($1-$2))
	exit
elif [ $3 -eq 3 ];then
	echo $(($1*$2))
	exit
elif [ $3 -eq 4 ];then
	if [ $2 -eq 0 ];then
		echo "Cant divide with 0.">&2
		exit
	else
		echo $(($1/$2))
		exit
	fi
fi
