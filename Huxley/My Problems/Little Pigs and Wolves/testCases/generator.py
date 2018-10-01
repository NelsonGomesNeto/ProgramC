import os
from random import randint
dx, dy = [1, -1, 0, 0], [0, 0, 1, -1]
os.system("g++ ./../littlePigsAndWolves.cpp -o ./../test -std=c++11")

def genYX():
  tries = 0
  y, x = randint(0, n - 1), randint(0, m - 1)
  while (field[y][x] != '.' and tries < 1000):
    y, x = randint(0, n - 1), randint(0, m - 1)
    tries += 1
  return(y, x)

def genDir(y, x):
  done = [0] * 4
  k = randint(0, 3)
  done[k] = 1
  while (sum(done) < 4 and ((not valid(y + dy[k], n)) or (not valid(x + dx[k], m)))):
    k = randint(0, 3)
    done[k] = 1
  return(k)

def valid(i, size):
  return(not (i < 0 or i >= size))

testCases = int(input())
for i in range(1, testCases + 1):
  f = open("%d.in" % i, "w")
  n, m = randint(1, 10), randint(1, 10)
  print(n, m, file=f)
  field = [['.'] * m for j in range(n)]
  pigs = randint(0, n*m)
  while (pigs):
    y, x = genYX()
    if (y == -1): continue
    field[y][x] = 'P'
    hasWolf = randint(0, 1)
    if (hasWolf):
      k = genDir(y, x)
      field[y + dy[k]][x + dx[k]] = 'W'
    pigs -= 1
  for j in range(n):
    print(*field[j], file=f)
  f.close()
  os.system("./../test < %d.in > %d.out" % (i, i))
