import os
from random import randint
os.system("g++ ./../sumOfDigits.cpp -o ./../test")

testCases = int(input())
for i in range(1, testCases + 1):
  f = open("%d.in" % i, "w")
  n, k = randint(1, 10000), randint(0, 36)
  print(n, k, file=f)
  f.close()

  os.system("./../test < %d.in > %d.out" % (i, i))