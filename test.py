n, k, m, d = map(int, input().split())
if (d == 1):
    print(m)
else:
    ans = 0
    for i in range(0, d):
        x = (n // ((k * i) + 1))
        if (x > m): x = m
        ans = max(ans, x * (i + 1))
    print(ans)