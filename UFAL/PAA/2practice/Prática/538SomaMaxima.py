inf = 2**33
DEBUG = 0

def printMatrix(mat):
    for i in mat:
        for j in i:
            print(j, end=' ')
        print()

dim = int(input())
mat = [[] for i in range(dim)]
filled = 0
while (filled < dim * dim):
    line = list(map(int, input().split()))
    for k in line:
        i = filled // dim
        mat[i] += [k]
        filled += 1
if (DEBUG):
    print("mat")
    printMatrix(mat)

spreadSum = [[0] * dim for i in range(dim)]
for i in range(dim):
    for j in range(dim):
        spreadSum[i][j] = mat[i][j]
        if (i):
            spreadSum[i][j] += spreadSum[i - 1][j]
        if (j):
            spreadSum[i][j] += spreadSum[i][j - 1]
        if (i and j):
            spreadSum[i][j] -= spreadSum[i - 1][j - 1]
if (DEBUG):
    print("spreadSum")
    printMatrix(spreadSum)

best = -inf
for iLo in range(dim):
    for jLo in range(dim):
        for iHi in range(iLo, dim):
            for jHi in range(jLo, dim):
                newBest = spreadSum[iHi][jHi]
                if (iLo):
                    newBest -= spreadSum[iLo - 1][jHi]
                if (jLo):
                    newBest -= spreadSum[iHi][jLo - 1]
                if (iLo and jLo):
                    newBest += spreadSum[iLo - 1][jLo - 1]
                if (newBest > best):
                    best = newBest
print(best)
