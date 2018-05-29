import os
from random import randint
import time
os.system("gcc ./../coloring.c -o ./../test")

def genYX(n, m, field):
  y, x = randint(0, n - 1), randint(0, m - 1)
  while (field[y][x] != '.'):
    y, x = randint(0, n - 1), randint(0, m - 1)
  return(y, x)

testCases = int(input())
for i in range(1, testCases + 1):
  f = open("%d.in" % i, "w")
  n, m = randint(1, 100), randint(1, 100)
  print(n, m, file=f)
  blocks = randint(0, (n - 1)*(m - 1))
  field = [['.'] * m for j in range(n)]
  while (blocks):
    y, x = genYX(n, m, field)
    field[y][x] = '#'
    blocks -= 1
  for j in range(n):
    for k in range(m):
      print(field[j][k], end='', file=f)
    print(file=f)
  colors, cc = randint(0, min(200, (n - 1)*(m - 1))), 0
  cc = colors
  print(colors, file=f)
  while (colors):
    y, x, c = randint(0, n - 1), randint(0, m - 1), randint(0, 9)
    print(y, x, c, file=f)
    colors -= 1
  f.close()
  start = time.time()
  print(i, "%d x %d - %d" % (n, m, cc), "started")
  os.system("./../test < ./%d.in > ./%d.out" % (i, i))
  print(i, "- Took:", time.time() - start)
