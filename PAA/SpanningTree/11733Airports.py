from heapq import *
inf = 2**33

def prim(graph, cost, visited, start):
    total = 0
    cost[start] = 0
    pq = []
    heappush(pq, [cost[start], start])
    while (pq):
        c, v = heappop(pq)
        if (visited[v]): continue
        visited[v] = 1
        total += c
        for u in graph[v]:
            cost[u[0]] = u[1]
            heappush(pq, [cost[u[0]], u[0]])
    return(total)

tests, case = int(input()), 1
while (case <= tests):
    locations, connections, buildCost = map(int, input().split())
    graph = [[] for i in range(locations + 1)]
    flagged = [0] * (locations + 1)
    airports = 0
    for i in range(connections):
        u, v, c = map(int, input().split())
        if (c >= buildCost):
            airports += 1
            c = buildCost
        graph[u] += [[v, c]]
        graph[v] += [[u, c]]

    visited, cost = [0] * (locations + 1), [inf] * (locations + 1)
    airports += 1
    minCost = prim(graph, cost, visited, 1) + buildCost
    for u in range(1, locations + 1):
        if (not visited[u] and not flagged[u]):
            airports += 1
            minCost += prim(graph, cost, visited, u) + buildCost
        elif (not visited[u]):
            airports += 1
            visited[u] = 1
            minCost += buildCost

    print("Case #", case, ": ", minCost, " ", airports, sep='')
    case += 1