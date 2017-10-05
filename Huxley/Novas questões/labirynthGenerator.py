import sys
sys.setrecursionlimit(2**20)
import random

dx = [0, 0, -1, 1]
dy = [1, -1, 0, 0]

def createPath(i, j, y, x, labirynth, visited):
    if (i < 0 or j < 0 or i >= y or j >= x): return
    if (visited[i][j]):
        return

    visited[i][j] = 1
    a = [[0,1],[0,-1],[-1,0],[1,0]]
    random.shuffle(a)
    for k in a:
        #if (i + dy[k] < 0 or j + dx[k] < 0 or i + dy[k] >= y or j + dx[k] >= x) and (visited[i + dy[k]][j + dx[k]]): continue
        createPath(i + k[0], j + k[1], y, x, labirynth, visited)

y, x = random.randint(1, 10), random.randint(1, 10)
print(y, x)
labirynth = [['#'] * x for i in range(y)]
visited = [[0] * x for i in range(y)]
for i in labirynth:
    print(i)
print()

createPath(0, 0, y, x, labirynth, visited)
for i in labirynth:
    print(i)
