#!/bin/bash

rm -f results.txt

i=0
descriptions=("Unsorted array, no duplicates" "Unsorted array, duplicates")
for f in answer*.txt; do
	i=$(( i + 1 ))
	echo "Test $i: ${descriptions[i-1]}" >> results.txt;
	./test.sh $i
done

cat results.txt
