#!/bin/bash
tests=$1
num=$2

echo -e "Checker\tOperations\n"
for ((i = 1; i <= tests; i++)); do
	ARG=$(shuf -i 0-100000 -n "$num" | tr '\n' ' ')
	cnt=$(./push_swap $ARG | wc -l)
	result=$(./push_swap $ARG | ./checker_linux $ARG)
	echo -e "${result}\t${cnt}"
done
