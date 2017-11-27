def binPack(s, i, target, total):
    if (i == len(s)): return(0)

    if (dp[i][total] == -1):
        ans = binPack(s, i + 1, target, total)
        if (total - s[i] >= target):
            aux = s[i] + binPack(s, i + 1, target, total - s[i])
            if (aux > ans):
                ans = aux
        dp[i][total] = ans

    return(dp[i][total])

s = list(map(int, input().split()))
target = int(input())
total = sum(s)

if ((total + target) & 1):
    print("No")
else:
    dp = [[-1] * (total + 1) for i in range(len(s))]
    now = binPack(s, 0, ((total + target) / 2), total)
    if (abs((total + target) / 2) - now == target):
        print("Yes")
    else:
        print("No")

#s1 - s2 = d
#s1 + s2 = total
#
#s1 = d + s2
#d + s2 + s2 = total
#s2 = (total - d) / 2
