def solve(groups, i, target, dp):
    if (i == len(groups)): return(0)
    if (dp[i][target] == -1):
        ans, aux = solve(groups, i + 1, target, dp), 0
        if (target - groups[i] >= 0):
            aux = groups[i] + solve(groups, i + 1, target - groups[i], dp)
        if (aux > ans): ans = aux
        dp[i][target] = ans
    return(dp[i][target])

s = list(map(int, input().split()))
groups = []
s.sort()
i = 0
while (i < len(s)):
    g = s[i]
    while (i < len(s) - 1 and (s[i] == s[i + 1] or s[i] == s[i + 1] - 1)):
        g += s[i + 1]
        i += 1
    groups += [g]
    i += 1
#print("groups", groups)

total = sum(groups)
dp = [[-1] * (1 + int(total / 2)) for i in range(len(groups))]
ans = solve(groups, 0, int(total / 2), dp)
print(abs((total - ans) - ans))