from heapq import *
import sys
sys.setrecursionlimit(2**20)
WHITE, GRAY = 0, 1
inf = 2**33
DEBUG = 0

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

def tarjan(graph, color, discovery, discoveryTime, low, parent, articulation, u):
    children = 0
    discovery[u], low[u] = discoveryTime[0], discoveryTime[0]
    discoveryTime[0] += 1
    color[u] = GRAY
    for i in graph[u]:
        v = i[0]
        if (color[v] == WHITE):
            parent[v] = u
            children += 1
            tarjan(graph, color, discovery, discoveryTime, low, parent, articulation, v)
            isRoot = (parent[u] == -1)
            if (isRoot and children > 1):
                articulation[u] = 1
            elif (not isRoot and discovery[u] <= low[v]):
                articulation[u] = 1
            low[u] = min(low[u], low[v])
        elif (v != parent[u]):
            low[u] = min(low[u], discovery[v])


nodes, streets = map(int, input().split())
graph = [[] for i in range(nodes + 1)]
for i in range(streets):
    u, v, c = map(int, input().split())
    graph[u] += [[v, c]]
    graph[v] += [[u, c]]
if (DEBUG):
    print("graph", graph)

visited, cost = [0] * (nodes + 1), [inf] * (nodes + 1)
dijkstra(graph, cost, visited, 1)
if (DEBUG):
    print("cost", cost)

color, discovery, low = [WHITE] * (nodes + 1), [0] * (nodes + 1), [0] * (nodes + 1)
parent, articulation = [-1] * (nodes + 1), [0] * (nodes + 1)
discoveryTime = [0]
tarjan(graph, color, discovery, discoveryTime, low, parent, articulation, 1)
if (DEBUG):
    print("color", color)
    print("discovery", discovery)
    print("low", low)
    print("parent", parent)
    print("articulation", articulation)

distToBridge = []
for u in range(nodes):
    for node in graph[u]:
        v = node[0]
        if (discovery[u] < low[v]):
            minCost = min(cost[u], cost[v])
            if (minCost != inf):
                distToBridge += [minCost]

if (len(distToBridge) == 0):
    print("It's not possible")
else:
    print("It's possible with distance", min(distToBridge))
