import sys
sys.setrecursionlimit(2**30)

dp = [-1] * int(1e6)

def solve(i, n):
    if (n < 3):
        return(max(v))
    dp[0], dp[1], dp[2] = v[0], max(v[0], v[1]), max(v[0], v[1], v[2])
    for i in range(3, n):
        dp[i] = max(dp[i - 1], dp[i - 3] + v[i])
    return(dp[n - 1])

n = int(input())
v = list(map(int, input().split()))
ans = solve(0, n)
print(ans)