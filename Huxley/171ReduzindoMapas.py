from heapq import *

def prim(graph, visited):
    mst = [[] for i in graph]
    pq = []
    heappush(pq, [0, 0, 1])
    while (pq):
        c, p, v = heappop(pq)
        if (visited[v]):
            continue
        visited[v] = True
        mst[p] += [[v, c]]
        mst[v] += [[p, c]]
        for u in graph[v]:
            if (not visited[u[0]]):
                heappush(pq, [u[1], v, u[0]])
    return(mst)

def floodFill(graph, visited, start):
    t = 0
    visited[start] = 1
    for v in graph[start]:
        if (not visited[v[0]]):
            visited[v[0]] = 1
            t += v[1]
            t += floodFill(graph, visited, v[0])
    return(t)

cities, streets = map(int, input().split())
graph = [[] for i in range(cities + 1)]
for i in range(streets):
    u, v, c = map(int, input().split())
    graph[u] += [[v, c]]
    graph[v] += [[u, c]]

visited = [0] * (cities + 1)
mst = prim(graph, visited)

visited = [0] * (cities + 1)
total = floodFill(mst, visited, 1)

print(total)