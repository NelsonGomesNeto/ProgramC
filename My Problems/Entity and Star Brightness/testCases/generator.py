from random import randint
import os
os.system("gcc ./../entityAndStarBrightness.c -o ./../test")

testCases = int(input())
for t in range(1, testCases + 1):
  f = open("%d.in" % t, "w")
  n = randint(1, 1000)
  print(n, file=f)
  for i in range(n):
    x = randint(0, 999999999999999999)
    print(x, file=f)
  f.close()

  os.system("./../test < %d.in > %d.out" % (t, t))
