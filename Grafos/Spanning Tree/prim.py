from heapq import *
undirected = True

def printGraph(graph):
    for u in sorted(graph):
        print(u, end=': ')
        for v in sorted(graph[u]):
            print(v, end=' ')
        print()

def cost(graph):
    c = 0
    for u in graph:
        for v in graph[u]:
            c += graph[u][v]
    return(c)

def prim(graph, source):
    mst, visited = {}, set()
    pq = []
    heappush(pq, [0, source, -1])
    while (pq):
        c, u, prev = heappop(pq)
        if (u in visited): continue
        visited.add(u)
        if (prev != -1):
            if (u not in mst): mst[u] = {}
            if (prev not in mst): mst[prev] = {}
            mst[prev][u] = c
        for v in graph[u]:
            heappush(pq, [graph[u][v], v, u])
    return(mst)

source = input()
graph = {}
while (True):
    try:
        u, v, c = input().split()
        c = int(c)
        if (u not in graph): graph[u] = {}
        if (v not in graph): graph[v] = {}
        graph[u][v] = c
        if (undirected): graph[v][u] = c
    except:
        break

print("Original Graph:")
printGraph(graph)
mst = prim(graph, source)
print("MST:")
printGraph(mst)
print("MST cost:", cost(mst))