#!/bin/bash
gcc findExit.c -o test
for ((i = 1; i <= 50; i ++))
do
  ./test < ./testCases/$i.in > ./testCases/$i.out
done
