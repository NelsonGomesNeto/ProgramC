numPD, numPrism, rivalries, budget = map(int, input().split())
pd = list(map(int, input().split()))
prism = list(map(int, input().split()))
size = numPD * numPrism
enemy = [[0] * (size + 2) for in range(size + 2)]
for i in range(rivalries):
    u, v = map(int, input().split())
    enemy[u][v] = 1
    enemy[v][u] = 1
