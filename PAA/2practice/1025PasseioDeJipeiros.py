from heapq import *
inf = 10**9
DEBUG = 0

def dijkstra(graph, cost, visited, path, source):
    cost[source] = 0
    path[source] = -1
    pq = []
    heappush(pq, [cost[source], source])
    while (pq):
        v = heappop(pq)[1]
        if (visited[v]): continue
        visited[v] = 1
        for i in graph[v]:
            u = [i] + graph[v][i]
            if (cost[v] + u[2] < cost[u[0]]):
                cost[u[0]] = cost[v] + u[2]
                path[u[0]] = v
                heappush(pq, [cost[u[0]], u[0]])

def runPath(path, placesCity, start, end):
    newPath = set()
    while (end != start):
        newPath.add(placesCity[end])
        end = path[end]
    newPath.add(placesCity[end])
    return(newPath)

def bfs(residualGraph, source, target, parent, placesCity, allowedCities):
    visited = [0] * len(residualGraph)
    visited[0] = 1
    parent[source] = -1
    queue = [source]
    while (queue):
        u = queue.pop(0)
        for i in graph[u]:
            v = i
            if (not visited[v] and residualGraph[u][v][0] > 0 and placesCity[v] in allowedCities):
                parent[v] = u
                queue += [v]
                visited[v] = 1
    return(visited[target])


def fordFulkerson(residualGraph, source, target, placesCity, allowedCities):
    parent = [-1] * len(residualGraph)
    maxFlow = 0
    while (bfs(residualGraph, source, target, parent, placesCity, allowedCities)):
        pathFlow = inf
        v = target
        while (v != source):
            u = parent[v]
            pathFlow = pathFlow if (pathFlow < residualGraph[u][v][0]) else residualGraph[u][v][0]
            v = parent[v]
        v = target
        while (v != source):
            u = parent[v]
            residualGraph[u][v][0] -= pathFlow
            residualGraph[v][u][0] += pathFlow
            v = parent[v]
        maxFlow += pathFlow
    if (DEBUG): print("residualGraph", residualGraph)
    return(maxFlow)

# Reading input
places = int(input())
cities = int(input())
placesCity = [0] * places
for i in range(cities):
    cityPlaces = list(map(int, input().split()))
    for j in cityPlaces:
        placesCity[j] = i
if (DEBUG):
    #print("cityPlaces", cityPlaces)
    print("placesCity", placesCity)

# Mapping everything to a graph
streets = int(input())
graph = {}
for i in range(streets):
    u, v, c, d = map(int, input().split())
    if (u not in graph): graph[u] = {}
    graph[u][v] = [c, d]
    if (v not in graph): graph[v] = {}
    if (u not in graph[v]): graph[v][u] = [0, 0]

# Finding shortest path
source, destination = map(int, input().split())
cost, visited, path = [inf] * places, [0] * places, [-1] * places
dijkstra(graph, cost, visited, path, source)
if (DEBUG):
    print("cost", cost)
    print("path", path)

# Running through the path to find which cities belongs to it
citiesPath = runPath(path, placesCity, source, destination)
if (DEBUG):
    print("citiesPath", citiesPath)

travelCost = cost[destination]
maxPeople = fordFulkerson(graph, source, destination, placesCity, citiesPath)
print(travelCost)
print(maxPeople)
