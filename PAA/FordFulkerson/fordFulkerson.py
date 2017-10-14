from queue import *
inf = 2**33

def bfs(graph, residualGraph, source, target, parent): # Simple BFS that stores the path
    vertices = len(graph)
    visited = [0] * vertices
    queue = Queue()
    queue.put(source)
    visited[source] = 1
    parent[source] = -1
    while (not queue.empty()):
        u = queue.get()
        for v in graph[u]:
            if (not visited[v] and residualGraph[u][v] > 0): # If there's still flow there
                queue.put(v)
                parent[v] = u
                visited[v] = 1
    return(visited[target])

def fordFulkerson(graph, matrixGraph, source, target):
    vertices = len(graph)
    residualGraph = list(map(list, matrixGraph))
    parent = [0] * vertices
    maxFlow = 0
    while (bfs(graph, residualGraph, source, target, parent)): # While there is path to the end
        pathFlow = inf # Dream flow
        v = target
        while (v != source): # Find the bottleneck
            u = parent[v]
            pathFlow = min(pathFlow, residualGraph[u][v])
            v = parent[v]
        v = target
        while (v != source): # Remove the bottleneck
            u = parent[v]
            residualGraph[u][v] -= pathFlow
            residualGraph[v][u] += pathFlow
            v = parent[v]
        maxFlow += pathFlow # Add this flow to the total
    print("residualGraph", residualGraph)
    return(maxFlow)


vertices, edges = map(int, input().split())
graph = [[] for i in range(vertices)]
matrixGraph = [[0] * vertices for i in range(vertices)]
for i in range(edges):
    u, v, w = map(int, input().split())
    graph[u] += [v]
    graph[v] += [u]
    matrixGraph[u][v] = w

source = 0
sink = 1
print("graph", graph)
print("matrixGraph", graph)
print(fordFulkerson(graph, matrixGraph, source, sink))
