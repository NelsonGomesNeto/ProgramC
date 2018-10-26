DEBUG = 0
inf = 2**33

def printMatrix(m):
    for i in m:
        print(*i)
    print()

def optimalMatrixMultiplicationTopDown(lo, hi, dim, dp, parenthesis):
    if (lo == hi):
        return(0)

    if (dp[lo][hi] == -1):
        cost = inf
        for k in range(lo, hi):
            aux = optimalMatrixMultiplicationTopDown(lo, k, dim, dp, parenthesis) + optimalMatrixMultiplicationTopDown(k + 1, hi, dim, dp, parenthesis) + dim[lo - 1]*dim[k]*dim[hi]
            if (aux < cost):
                cost = aux
                parenthesis[lo][hi] = k
        dp[lo][hi] = cost

    return(dp[lo][hi])

def optimalMatrixMultiplicationBottomUp(dim):
    size = len(dim)
    m = [[0] * size for i in range(size)] # Minimal cost of multiplication form i to j
    parenthesis = [[0] * size for i in range(size)] # Saving where to put them, saving the place to cut
    for i in range(1, size):
        m[i][i] = 0 # Filling multiplications of nothing (haha)
    for l in range(2, size): # Size of the chain I will try to multiply
        for i in range(1, size - l + 1): # Where the chain begins
            j = i + l - 1 # Where the chain ends
            m[i][j] = inf # At first, this will cost inf
            for k in range(i, j):
                cost = m[i][k] + m[k + 1][j] + dim[i - 1]*dim[k]*dim[j] # Similar to recursive subdivision
                if (cost < m[i][j]): # Updating best multiplication
                    m[i][j] = cost
                    parenthesis[i][j] = k # Saving to use on printParenthesis
    return(m[1][size - 1], m, parenthesis)

def printParenthesis(i, j, s):
    if (i == j):
        print("A", i, sep='', end='')
        return
    print("(", sep='', end='')
    printParenthesis(i, s[i][j], s)
    print(" x ", sep='', end='')
    printParenthesis(s[i][j] + 1, j, s)
    print(")", sep='', end='')

run = 1
while (True):
    try:
        matrices = int(input())
        if (matrices == 0): break
    except:
        break

    dimensions = []
    for i in range(matrices):
        line = list(map(int, input().split()))
        dimensions += [line[0]]
        if (i == matrices - 1):
            dimensions += [line[1]]

    parenthesis, dp = [[-1] * (matrices + 1) for i in range(matrices + 1)], [[-1] * (matrices + 1) for i in range(matrices + 1)]
    cost = optimalMatrixMultiplicationTopDown(1, matrices, dimensions, dp, parenthesis)
    #cost, dp, parenthesis = optimalMatrixMultiplication(dimensions)

    if (matrices == 1):
        print("Case %d: (A1)" % run, end='')
    else:
        print("Case %d: " % run, end='')
        printParenthesis(1, matrices, parenthesis)
    print()
    run += 1
