#!/bin/bash
for ((i = 1; i <= 22; i ++))
do
  ./e < ./warmup/A/input/A_$i > out
  #if $(cmp "./out" "./warmup/A/output/A_$i"); then echo "Success";
  #else echo "Failed"; fi
  cat ./out && cat ./warmup/A/output/A_$i
  diff ./out ./warmup/A/output/A_$i
done
