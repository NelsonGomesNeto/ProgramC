def printMat(mat):
    for i in range(len(mat)):
        print(*mat[i])
    print()

size = 2
dx = [0, 1, 1, 1, 0, -1, -1, -1]
dy = [-1, -1, 0, 1, 1, 1, 0, -1]

mat = [[0]*size for p in range(size)]
# i, j = 1, 1
# print("Start:")
# printMat(mat)
# print("Movements:")
# for k in range(8):
#     mat[i + dy[k]][j + dx[k]] = 1
#     printMat(mat)
#     mat[i + dy[k]][j + dx[k]] = 0

def go(i, j, size):
    if (i < 0 or j < 0 or i >= size or j >= size or mat[i][j] == 1): # Invalid position
        return
    mat[i][j] = 1
    for k in range(8):
        go(i + dy[k], j + dx[k], size)
    printMat(mat)
    mat[i][j] = 0

go(1, 1, size)