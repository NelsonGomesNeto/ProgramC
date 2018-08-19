undirected = False

def dfs(graph, u, visited):
    if (visited[u]): return([])
    visited[u] = 1
    reachable = [u]
    for v in graph[u]:
        reachable += dfs(graph, v, visited)
    return(reachable)

def createVisited(graph):
    visited = {}
    for v in graph: visited[v] = 0
    return(visited)

def malgrange(graph, revGraph):
    y = list(graph.keys())
    stronglyConnected = []
    iteration = 1
    while (y):
        print(iteration, "step:")
        iteration += 1
        print("\tY:", y)
        u = y[0]
        visited = createVisited(graph)
        rplus = set(dfs(graph, u, visited))
        print("\tR+:", rplus)
        visited = createVisited(graph)
        rminus = set(dfs(revGraph, u, visited))
        print("\tR-:", rminus)
        intersection = rplus.intersection(rminus)
        print("\tIntersection:", intersection)
        stronglyConnected += [intersection]
        aux = set(y)
        for s in intersection:
            aux.remove(s)
        y = list(aux)
    return(stronglyConnected)

source = input()
graph, revGraph = {}, {}
while (True):
    try:
        u, v, c = input().split()
        c = int(c)
        if (u not in graph): graph[u], revGraph[u] = {}, {}
        if (v not in graph): graph[v], revGraph[v] = {}, {}
        graph[u][v] = c
        revGraph[v][u] = v
        if (undirected): graph[v][u] = c
        if (undirected): revGraph[u][v] = c
    except:
        break

stronglyConnected = malgrange(graph, revGraph)
print("Strongly Connected Components:", stronglyConnected)