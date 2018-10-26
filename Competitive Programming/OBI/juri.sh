#!/bin/bash
wrong=0
for ((fl = 1; fl <= 10; fl ++))
do
$(g++ 2017cortandoopapel.cpp -o test)
for ((i = 1; i <= 2; i ++))
do
  $(./test < ./papel/$fl/$i.in > out)
  if (!(cmp ./out ./papel/$fl/$i.sol)); then
    echo "Failed on $i"
    echo "You:"
    cat ./out
    echo "Should be:"
    cat ./papel/$fl/$i.sol
    wrong=1
  fi
  #if $(cmp "./out" "./warmup/A/output/A_$i"); then echo "Success";
  #else echo "Failed"; fi
done
if ((!$wrong)); then
  echo "Success!!!"
fi
done
