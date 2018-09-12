inf = 1<<20
level = {}
VERBOSE = 1

def printGraph(graph):
    for u in sorted(graph):
        print("%3s ->" % (u), end='')
        for v in sorted(graph[u]):
            # if (graph[u][v]):
            print(" ", (v, graph[u][v]), sep='', end='')
        print()

def readGraph():
    graph = {}
    while (True):
        try:
            line = input()
            if (line == ""): continue
            u, v, c = line.split()
            if (u not in graph): graph[u] = {}
            if (v not in graph): graph[v] = {}
            graph[u][v], graph[v][u] = int(c), 0
        except:
            return(graph)

def bfs(graph, source, target):
    for i in graph: level[i] = -1
    level[source] = 0
    queue = [source]
    while (queue):
        u = queue.pop(0)
        for v in graph[u]:
            if (level[v] < 0 and graph[u][v] > 0):
                level[v] = level[u] + 1
                queue += [v]
    return(level[target] > 0)

def dfs(graph, u, target, flow):
    if (u == target): return(flow)
    actualFlow = 0
    for v in graph[u]:
        if (level[u] == level[v] - 1 and graph[u][v] > 0):
            pathFlow = dfs(graph, v, target, min(flow, graph[u][v]))
            flow -= pathFlow
            graph[u][v] -= pathFlow
            graph[v][u] += pathFlow
            actualFlow += pathFlow
    return(actualFlow)

def dinicMaxFlow(graph, source, target):
    maxFlow = 0
    iterations = 1
    while (bfs(graph, source, target)):
        pathFlow = dfs(graph, source, target, inf)
        maxFlow += pathFlow
        if (VERBOSE): print("\n\tIteration:", iterations)
        if (VERBOSE): printGraph(graph)
        iterations += 1
    return(maxFlow)

graph = readGraph()
if (VERBOSE): print("\tGraph:")
if (VERBOSE): printGraph(graph)

source, target = "s", "t"
maxFlow = dinicMaxFlow(graph, source, target)
print("Max Flow:", maxFlow)
if (VERBOSE): print("\tFlow Graph:")
if (VERBOSE): printGraph(graph)
