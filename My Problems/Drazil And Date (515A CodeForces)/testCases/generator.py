from random import randint
import os
os.system("g++ ./../drazilAndDate.cpp -o ./../test")

testCases = int(input())
for i in range(1, testCases + 1):
  f = open("%d.in" % i, "w")
  a, b, s = randint(-1000000000, 1000000000), randint(-1000000000, 1000000000), randint(1, 2000000000)
  if (randint(0, 1)):
    dist = abs(a) + abs(b)
    while (not (dist == s or (dist < s and (s - dist) % 2 == 0))):
      a, b, s = randint(-1000000000, 1000000000), randint(-1000000000, 1000000000), randint(1, 2000000000)
  print(a, b, s, file=f)
  f.close()
  os.system("./../test < %d.in > %d.out" % (i, i))
