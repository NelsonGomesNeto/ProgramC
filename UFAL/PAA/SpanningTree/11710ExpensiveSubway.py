from heapq import *
inf = 2 **33

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

while (True):
    stations, connections = map(int, input().split())
    if (stations == 0 and connections == 0): break

    stringToInt, intToString = {}, {}
    for i in range(stations):
        line = input()
        stringToInt[line] = i
        intToString[i] = line

    graph = [[] for i in range(stations)]
    for i in range(connections):
        u, v, c = input().split()
        u, v, c = stringToInt[u], stringToInt[v], int(c)
        graph[u] += [[v, c]]
        graph[v] += [[u, c]]

    origin = input()
    visited, cost = [0] * stations, [inf] * stations
    minCost = prim(graph, cost, visited, stringToInt[origin])
    if (min(visited) == 0):
        print("Impossible")
    else:
        print(minCost)
