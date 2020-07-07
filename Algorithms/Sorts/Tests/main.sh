#!/bin/bash

rm -f results.txt

files=(answer*.txt)
total=${#files[@]}
i=0
descriptions=("Unsorted array, no duplicates" "Unsorted array, duplicates")
for f in "${files[@]}"; do
	temp=${descriptions[i]}
	i=$(( i + 1 ))
	echo "Test $i $temp" >> results.txt;
	./test.sh $i
done

cat results.txt
