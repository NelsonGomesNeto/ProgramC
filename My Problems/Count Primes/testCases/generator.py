from random import randint
import os
os.system("gcc ./../countPrimes.c -o ./../test")

testCases = int(input())
for t in range(1, testCases + 1):
  f = open("%d.in" % t, "w")
  n = randint(1, 1000)
  print(n, file=f)
  for i in range(n):
    print(randint(0, 1e18), file=f)
  f.close()
  os.system("./../test < %d.in > %d.out" % (t, t))
