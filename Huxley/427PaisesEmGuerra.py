from heapq import *
inf = 2**33

def dijkstra(graph, cost, visited, start):
    cost[start] = 0
    pq = []
    heappush(pq, [cost[start], start])
    while (pq):
        v = heappop(pq)[1]
        if (visited[v]): continue
        visited[v] = 1
        for u in graph[v]:
            if (cost[v] + u[1] < cost[u[0]]):
                cost[u[0]] = cost[v] + u[1]
                heappush(pq, [cost[u[0]], u[0]])

run = 0
while (True):
    cities, connections = map(int, input().split())
    if (cities == 0 and connections == 0):
        break
    if (run > 0):
        print()

    dp = [[-1] * (cities + 1) for i in range(cities + 1)]
    graph = [[] for i in range(cities + 1)]
    for i in range(connections):
        u, v, c = map(int, input().split())
        if (dp[v][u] != -1): # If they are in the same country
            dp[u][v] = 0
            dp[v][u] = 0
            graph[u] += [[v, 0]]
            for i in range(len(graph[v])):
                if (graph[v][i][0] == u):
                    graph[v][i][1] = 0
                    break
        else:
            dp[u][v] = c
            graph[u] += [[v, c]]

    queries = int(input())
    for i in range(queries):
        begin, end = map(int, input().split())
        if (dp[begin][end] == -1):
            visited, cost = [0] * (cities + 1), [inf] * (cities + 1)
            dijkstra(graph, cost, visited, begin)
            if (cost[end] == inf):
                dp[begin][end] = "Nao e possivel entregar a carta"
            else:
                dp[begin][end] = cost[end]
        print(dp[begin][end])
    run += 1