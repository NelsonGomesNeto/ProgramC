from math import log, ceil
dx = [1, 0, 0, 1]
dy = [0, 0, 1, 1]

def quadrant(pi, pj, i, j):
    i += 0.5
    j += 0.5
    if (pi - i >= 0 and pj - j >= 0):
        return(4 - 1)
    if (pi - i <= 0 and pj - j >= 0):
        return(1 - 1)
    if (pi - i >= 0 and pj - j <= 0):
        return(3 - 1)
    if (pi - i <= 0 and pj - j <= 0):
        return(2 - 1)

def putSquare(b, i, j, color, pi, pj):
    prev = b[pi][pj]
    #print(color, pi, pj, prev)
    for k in range(i, i + 2):
        for m in range(j, j + 2):
            #if (b[k][m] == 0):
            b[k][m] = color
    k = quadrant(pi, pj, i, j)
    b[i + dy[k]][j + dx[k]] = prev
    #print("Quad", k + 1)
    #draw(b)

def fill(b, pi, pj, i0, iF, j0, jF):
    midi, midj = int((i0 + iF) / 2), int((j0 + jF) / 2)
    #print("Putting", midi, midj, "blocked", pi, pj, "quadrant", quadrant(pi, pj, midi, midj))
    if (i0 >= iF or j0 >= jF):
        return
    else:
        tiles[0] += 1
    putSquare(b, midi, midj, tiles[0], pi, pj)

    k = quadrant(pi, pj, midi, midj)
    if (k == 2 - 1):
        fill(b, pi, pj, i0, midi, j0, midj)
    else:
        fill(b, midi, midj, i0, midi, j0, midj)
    if (k == 1 - 1):
        fill(b, pi, pj, i0, midi, midj + 1, jF)
    else:
        fill(b, midi, midj + 1, i0, midi, midj + 1, jF)
    if (k == 3 - 1):
        fill(b, pi, pj, midi + 1, iF, j0, midj)
    else:
        fill(b, midi + 1, midj, midi + 1, iF, j0, midj)
    if (k == 4 - 1):
        fill(b, pi, pj, midi + 1, iF, midj + 1, jF)
    else:
        fill(b, midi + 1, midj + 1, midi + 1, iF, midj + 1, jF)


def printSpaces(n, spaces):
	if (n == -1):
		n = 11
	i = int(log(n, 10) + 1)
	while (i <= spaces):
		print(' ', sep='', end='')
		i += 1

def draw(b, spaces):
	for i in b:
		for j in i:
			printSpaces(j, spaces)
			print(j, sep='', end='')
		print()

tiles = [0]
size = int(input())
spaces = log(size**2, 10) + 1
board = [[0] * size for i in range(size)]
i, j = map(int, input().split())
board[i][j] = -1
print(board)
fill(board, i, j, 0, size - 1, 0, size - 1)
draw(board, spaces)

