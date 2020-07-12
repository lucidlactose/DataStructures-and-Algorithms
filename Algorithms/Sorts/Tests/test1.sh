#!/bin/bash

rm -f results.txt
echo "Test 1: Unsorted array, no duplicates" > results.txt;
for file in *Test1.txt;
do
	newname="${file%Test1.txt}"$'\t'
	cmp -s answer.txt $file
	RETVAL=$?;
	if [ $RETVAL -eq 0 ]; then
		echo "$newname SUCCESS" >> results.txt;
	else
		echo "$nawname FAILURE" >> results.txt;
	fi
done
cat results.txt
