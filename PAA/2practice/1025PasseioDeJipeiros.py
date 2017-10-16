from heapq import *
from queue import *
inf = 2**33
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
        for u in graph[v]:
            if (cost[v] + u[2] < cost[u[0]]):
                cost[u[0]] = cost[v] + u[2]
                path[u[0]] = v
                heappush(pq, [cost[u[0]], u[0]])

def runPath(path, placesCity, start, end):
    newPath = []
    while (end != start):
        newPath += [placesCity[end]]
        end = path[end]
    newPath += [end]
    newPath.reverse()
    return(set(newPath))

def bfs(graph, residualGraph, source, target, parent, placesCity, allowedCities):
    vertices = len(graph)
    visited = [0] * vertices
    visited[0] = 1
    parent[source] = -1
    queue = Queue()
    queue.put(source)
    while (not queue.empty()):
        u = queue.get()
        for i in graph[u]:
            v = i[0]
            if (not visited[v] and residualGraph[u][v] > 0 and placesCity[v] in allowedCities):
                parent[v] = u
                queue.put(v)
                visited[v] = 1
    return(visited[target])


def fordFulkerson(graph, matrixGraph, source, target, placesCity, allowedCities):
    vertices = len(graph)
    residualGraph = list(map(list, matrixGraph))
    parent = [-1] * vertices
    maxFlow = 0
    while (bfs(graph, residualGraph, source, target, parent, placesCity, allowedCities)):
        pathFlow = inf
        v = target
        while (v != source):
            u = parent[v]
            pathFlow = pathFlow if (pathFlow < residualGraph[u][v]) else residualGraph[u][v]
            v = parent[v]
        v = target
        while (v != source):
            u = parent[v]
            residualGraph[u][v] -= pathFlow
            residualGraph[v][u] += pathFlow
            v = parent[v]
        maxFlow += pathFlow
    if (DEBUG): print("residualGraph", residualGraph)
    return(maxFlow)

# Reading input
places = int(input())
cities = int(input())
cityPlaces, placesCity = [[] for i in range(cities)], [0] * places
for i in range(cities):
    cityPlaces[i] += list(map(int, input().split()))
    for j in cityPlaces[i]:
        placesCity[j] = i
if (DEBUG):
    print("cityPlaces", cityPlaces)
    print("placesCity", placesCity)

# Mapping everything to a graph
streets = int(input())
graph = [[] for i in range(places)]
matrixGraph = [[0] * places for i in range(places)]
for i in range(streets):
    u, v, c, d = map(int, input().split())
    graph[u] += [[v, c, d]]
    matrixGraph[u][v] = c

# Finding shortes path
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
maxPeople = fordFulkerson(graph, matrixGraph, source, destination, placesCity, citiesPath)
print(travelCost)
print(maxPeople)
