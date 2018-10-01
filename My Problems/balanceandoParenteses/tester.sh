#!/usr/bin/env bash
$(g++ balanceandoNumeros.c -o test)
for ((i = 1; i <= 16; i ++))
do
  echo $(./test < ./testCases/$i.in)
done