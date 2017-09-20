import sys
sys.setrecursionlimit(2**20)
DEBUG = 0

def solveRecursive(dp, values, size):
    if (dp[size] == -1):
        for i in range(size):
            aux = values[i] + solveRecursive(dp, values, size - i - 1)
            if (aux > dp[size]):
                dp[size] = aux
    return(dp[size])

def solveIterative(dp, values, size):
    for i in range(2, size + 1):
        for j in range(i):
            k = i - j - 1
            if (dp[i] < values[j] + dp[k]):
                dp[i] = values[j] + dp[k]
    return(dp[size])

while (True):
    size = int(input())
    if (size == 0):
        break

    values = []
    for i in range(size):
        values += [int(input())]
    if (DEBUG):
        print("values", values)

    #dp = [0] * (size + 1)
    #dp[1] = values[0]
    dp = [-1] * (size + 1)
    dp[0] = 0

    answer = solveRecursive(dp, values, size)
    print(answer)