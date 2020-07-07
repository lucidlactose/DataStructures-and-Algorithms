#!/bin/bash

for file in *Test"$1".txt;
do
	newname="${file%Test"$1".txt}"$'\t'
	cmp -s  answer"$1".txt $file
	RETVAL=$?
	if [ $RETVAL -eq 0 ]; then
		echo "$newname SUCCESS" >> results.txt;
	else
		echo "$newname FAILURE" >> results.txt;
	fi
done
