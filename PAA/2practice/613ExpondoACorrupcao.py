DEBUG = 0

def floodFill(graph, visited, price, u, pdMembers):
    total, size = price[u], [0 + (u < pdMembers), 0 + (u >= pdMembers)]
    visited[u] = 1
    for v in graph[u]:
        if (not visited[v]):
            ret = floodFill(graph, visited, price, v, pdMembers)
            total += ret[0]
            size[0] += ret[1][0]
            size[1] += ret[1][1]
    return(total, size)

def binpack(dp, packages, i, budget, w):
    if (i == len(packages)):
        return(0)

    if (dp[budget][i] == -1):
        if (budget - packages[i][0] >= 0):
            dp[budget][i] = (packages[i][1][w] - packages[i][1][1 - w]) + binpack(dp, packages, i + 1, budget - packages[i][0], w)
        aux = binpack(dp, packages, i + 1, budget, w)
        if (aux > dp[budget][i]): dp[budget][i] = aux
    return(dp[budget][i])

pdMembers, prismMembers, rivalries, budget = map(int, input().split())
price = []
price += list(map(int, input().split()))
price += list(map(int, input().split()))
graph = [[] for i in range(pdMembers + prismMembers)]
for i in range(rivalries):
    u, v = map(int, input().split())
    u, v = u - 1, v + pdMembers - 1
    graph[u] += [v]
    graph[v] += [u]

visited = [0] * (pdMembers + prismMembers)
packages = []
for i in range(pdMembers + prismMembers):
    if (not visited[i]):
        packages += [floodFill(graph, visited, price, i, pdMembers)]
if (DEBUG):
    print("packages", packages)

dp = [[-1] * (pdMembers + prismMembers) for i in range(budget + 1)]
bestPD = binpack(dp, packages, 0, budget, 1)
dp = [[-1] * (pdMembers + prismMembers) for i in range(budget + 1)]
bestPrism = binpack(dp, packages, 0, budget, 0)

print(pdMembers + bestPD, prismMembers + bestPrism)

