from math import log10, ceil
DEBUG = 1
dci, dcj = [0, 0, 1, 1], [1, 0, 0, 1]

def fixedPrint(num, size):
  numSize = 0 if num <= 0 else int(log10(num))
  if (num < 0): numSize += 1
  for i in range(size - numSize):
    print(" ", end='')
  print(num, end='')

def printTable(table):
  biggest = max(int(log10(len(table)**2//3)), 1)
  print("biggest", (len(table)**2 - 1)//3)
  for i in range(len(table)):
    for j in range(len(table[i])):
      fixedPrint(table[i][j], biggest)
      if (j < len(table[i]) - 1): print(" ", end='')
    print()

def getDir(mi, mj, y, x):
  if (mj < x and mi >= y): return(0)
  if (mj >= x and mi >= y): return(1)
  if (mj >= x and mi <= y): return(2)
  if (mj <= x and mi <= y): return(3)

def putColor(table, mi, mj, dir, color):
  for i in range(2):
    for j in range(2):
      if (dci[dir] == i and dcj[dir] == j): continue
      table[mi + i][mj + j] = color

def putTile(table, li, lj, hi, hj, y, x, now):
  if (li >= hi and lj >= hj): return
  now[0] += 1
  mi, mj = (li + hi) // 2, (lj + hj) // 2
  dir = getDir(mi, mj, y, x)
  if (DEBUG): print(li, lj, hi, hj, mi, mj, "dir", dir, "t", y, x)

  putColor(table, mi, mj, dir, now[0])

  if (dir == 0): putTile(table, li, mj + 1, mi, hj, y, x, now)
  else: putTile(table, li, mj + 1, mi, hj, mi, mj + 1, now)
  if (dir == 1): putTile(table, li, lj, mi, mj, y, x, now)
  else: putTile(table, li, lj, mi, mj, mi, mj, now)
  if (dir == 2): putTile(table, mi + 1, lj, hi, mj, y, x, now)
  else: putTile(table, mi + 1, lj, hi, mj, mi + 1, mj, now)
  if (dir == 3): putTile(table, mi + 1, mj + 1, hi, hj, y, x, now)
  else: putTile(table, mi + 1, mj + 1, hi, hj, mi + 1, mj + 1, now)


n = int(input())
table = [[0] * n for i in range(n)]
y, x = map(int, input().split())
table[y][x] = -1

printTable(table)

now = [0]
putTile(table, 0, 0, n - 1, n - 1, y, x, now)

printTable(table)


# k = 1
# for i in range(n):
#   for j in range(n):
#     table[i][j] = k
#     k += 1
