#!/bin/bash
#gcc amountOfPath.c -o amo
gcc pathFinding.c -o path
gcc mazeGenerator.c -o gen
./gen < ./in
for ((i = 1; i <= 25; i ++))
do
  #./amo < ./maze > ./out
  echo $i
  ./path < ./testCases/$i.in > ./testCases/$i.out
done
