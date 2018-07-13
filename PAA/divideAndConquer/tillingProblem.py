from math import log10, ceil

def fixedPrint(num, size):
  numSize = 0 if num <= 0 else int(log10(num))
  if (num < 0): numSize += 1
  for i in range(size - numSize):
    print(" ", end='')
  print(num, end='')

def printTable(table):
  biggest = int(log10(len(table)**2)) + 1
  for i in range(len(table)):
    for j in range(len(table[i])):
      fixedPrint(table[i][j], biggest)
      if (j < len(table[i]) - 1): print(" ", end='')
    print()

n = int(input())
table = [[0] * n for i in range(n)]
y, x = map(int, input().split())
table[y][x] = -1

printTable(table)

putTile(table)