from random import randint
import os
os.system("g++ ./../soldierAndBananas.cpp -o ./../test")

def apSum(a, b, q):
  return((a + b) / 2 * q * (b - a + 1))

testCases = int(input())
for i in range(1, testCases + 1):
  f = open("%d.in" % i, "w")
  k, n, w = randint(1, 1000), randint(0, 1e9), randint(1, 1000)
  if (randint(0, 10)):
    while (apSum(0, w, k) < n):
      k, n, w = randint(1, 1000), randint(0, 1e9), randint(1, 1000)
  print(k, n, w, file=f)
  f.close()

  os.system("./../test < %d.in > %d.out" % (i, i))