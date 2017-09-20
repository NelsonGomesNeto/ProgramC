import sys
sys.setrecursionlimit(2**20)

def solve(dp, string, i, end):
    if (i > end):
        return(0)
    if (i == end):
        return(1)

    if (dp[i][end] == -1):
        if (string[i] == string[end]):
            dp[i][end] = 2 + solve(dp, string, i + 1, end - 1)
        else:
            dp[i][end] = solve(dp, string, i + 1, end)
            dp[i][end] = max(dp[i][end], solve(dp, string, i, end - 1))

    return(dp[i][end])

tests = int(input())
while (tests > 0):
    string = list(input())

    dp = [[-1] * len(string) for i in range(len(string))]
    answer = solve(dp, string, 0, len(string) - 1)

    print(answer)
    tests -= 1