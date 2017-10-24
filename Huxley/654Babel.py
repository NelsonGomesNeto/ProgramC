from heapq import *
inf = 2**33
DEBUG = 0

def dijkstra(graph, cost, visited, start):
    cost[start] = 0
    pq = []
    heappush(pq, [cost[start], start])
    while (pq):
        c, v = heappop(pq)
        if (visited[v]): continue
        visited[v] = 1
        for u in graph[v]:
            if (cost[v] + u[1] < cost[u[0]]):
                cost[u[0]] = cost[v] + u[1]
                heappush(pq, [cost[u[0]], u[0]])

while (True):
    words = int(input())
    if (words == 0): break

    origin, destination = input().split()

    lines = [0] * words
    stringToInt = {}
    now = 1
    stringToInt[origin] = 0
    if (destination not in stringToInt):
        stringToInt[destination] = 1
        now = 2
    for i in range(words):
        line = list(input().split())
        lines[i] = line
        if (line[0] not in stringToInt):
            stringToInt[line[0]] = now
            now += 1
        if (line[1] not in stringToInt):
            stringToInt[line[1]] = now
            now += 1
    if (DEBUG):
        print("stringToInt", stringToInt)

    graph = [[] for i in range(len(stringToInt))]
    for i in lines:
        graph[stringToInt[i[0]]] += [[stringToInt[i[1]], len(i[2])]]
        graph[stringToInt[i[1]]] += [[stringToInt[i[0]], len(i[2])]]

    if (DEBUG):
        print("graph", graph)
    cost, visited = [inf] * len(graph), [0] * len(graph)
    dijkstra(graph, cost, visited, stringToInt[origin])

    if (cost[stringToInt[destination]] == inf):
        print("impossivel")
    else:
        print(cost[stringToInt[destination]])
