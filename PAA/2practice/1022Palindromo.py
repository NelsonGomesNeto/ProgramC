import sys
sys.setrecursionlimit(2**20)

def newSize(string):
    size = 0
    for i in string:
        if (i != 0):
            size += 1
    return(size)

def verifyPalindrome(string):
    size, jump = len(string), 0
    for i in range(size):
        j = size - jump - i - 1
        #print(string, i, j)
        if (i >= j):
            break
        if (string[i] == 0):
            i += 1
            jump += 1
        if (string[j] == 0):
            j -= 1
            jump += 1
        if (i < size and j >= 0 and string[i] != string[j]):
            return(0)
    return(size - jump)

def solve(dp, string, i, end):
    if (i == end):
        return(0)

    size = newSize(string)
    if (dp[i][size] == -1):
        verified = verifyPalindrome(string)
        best = max(verified, solve(dp, string, i + 1, end))

        #aux, string[i] = string[i], 0
        copy = string.copy()
        copy[i] = 0
        verified = verifyPalindrome(copy)
        best = max(best, verified, solve(dp, copy, i + 1, end))
        #string[i] = aux

        dp[i][size] = best

    return(dp[i][size])

tests = int(input())
while (tests > 0):
    string = list(input())

    dp = [[-1] * (len(string) + 1) for i in range((len(string) + 1))]
    answer = solve(dp, string, 0, len(string))

    print(answer)
    tests -= 1