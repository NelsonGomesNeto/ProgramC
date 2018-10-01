#!/bin/bash
gcc laplace.c -o test
for ((i = 1; i <= 10; i ++))
do
  ./test < ./testCases/$i.in > ./testCases/$i.out
done
