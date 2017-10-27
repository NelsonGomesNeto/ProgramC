#!/bin/bash
gcc linusPauling.c -o test
for ((i = 1; i <= 118; i ++))
do
  ./test < ./testCases/$i.in > ./testCases/$i.out
done
