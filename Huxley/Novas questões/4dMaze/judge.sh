#!/bin/bash
#gcc amountOfPath.c -o amo
gcc 3dMaze.c -o path
gcc 3dMazeGenerator.c -o gen
./gen < ./in
for ((i = 1; i <= 25; i ++))
do
  #./amo < ./maze > ./out
  echo $i
  ./path < ./testCases/$i.in > ./testCases/$i.out
done
