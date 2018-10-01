import os
from random import randint

os.system("gcc ./../allPossibleStrings.c -o ./../test")

testCases = int(input())
for i in range(1, testCases + 1):
  f = open("%d.in" % i, "w")

  size = randint(1, 10)
  s = ""
  for j in range(size):
    s += chr(randint(ord('a'), ord('z')))
  print(s, file=f)

  f.close()
  os.system("./../test < %d.in > %d.out" % (i, i))
