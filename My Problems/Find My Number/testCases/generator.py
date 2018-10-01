from random import randint
import os
os.system("g++ ./../findMyNumber.cpp -o ./../test")

def isIn(a, b):
  while (a > 0):
    if (a % 1000 == b): return(1)
    a //= 10
  return(0)

testCases = int(input())
yes = 0
for i in range(1, testCases + 1):
  a, b = randint(100000000, 999999999), randint(100, 999)
  if (randint(0, 1)):
    yes += 1
    while (not isIn(a, b)):
      b = randint(100, 999)
  f = open("%d.in" % i, "w")
  print(a, b, file=f)
  f.close()
  os.system("./../test < %d.in > %d.out" % (i, i))
  os.system("cat %d.in" % i)
  os.system("cat %d.out" % i)

print(testCases, yes, testCases - yes)