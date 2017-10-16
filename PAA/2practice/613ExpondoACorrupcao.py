def binpack(enemy, now, prism, i, end, numPD, budget):
    if (i == end):
        return(0)

    best = binpack(enemy, now, prism, i + 1, end, numPD, budget)
    if (i not in now and budget - prism[i - numPD] >= 0):
        for j in enemy[i]:
            now.add(j)
        best = max(best, 1 + binpack(enemy, now, prism, i + 1, end, numPD, budget - prism[i - numPD]))
    return(best)


numPD, numPrism, rivalries, budget = map(int, input().split())
pd = list(map(int, input().split()))
prism = list(map(int, input().split()))
size = numPD + numPrism + 10
enemy = [[] for i in range(size + 2)]
for i in range(rivalries):
    u, v = map(int, input().split())
    u -= 1
    v += numPD - 1
    enemy[u] += [v]
    enemy[v] += [u]
    # enemy[u][v] = 1
    # enemy[v][u] = 1
print("enemy", enemy)

now = []
for i in range(0, numPD):
    now += enemy[i]
now = set(now)
print("now", now)
maxDP = numPD + binpack(enemy, now, prism, numPD, numPD + numPrism, numPD, budget)

now = []
for i in range(numPD, numPD + numPrism):
    now += enemy[i]
now = set(now)
print("now", now)
maxPrism = numPrism + binpack(enemy, now, pd, 0, numPD, 0, budget)

print(maxDP, maxPrism)