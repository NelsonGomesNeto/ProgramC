#!/bin/bash
gcc treasureHunter.c -o test
for ((i = 1; i <= 11; i ++))
do
  ./test < ./testCases/$i.in > ./testCases/$i.out
done
