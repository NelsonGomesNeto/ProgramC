DEBUG = 0
inf = 2**20

def bfs(graph, matrixGraph, source, target, parent):
    visited = [0] * 54
    queue = [source]
    visited[source] = 1
    parent[source] = 1
    while (queue):
        u = queue.pop(0)
        for v in graph[u]:
            if (not visited[v] and matrixGraph[u][v] > 0):
                queue += [v]
                parent[v] = u
                visited[v] = 1
    return(visited[target])

def fordFulkerson(graph, matrixGraph, source, target):
    maxFlow = 0
    parent = [-1] * 54
    while (bfs(graph, matrixGraph, source, target, parent)):
        pathFlow = inf
        v, u = target, 0
        while (v != source):
            u = parent[v]
            pathFlow = min(pathFlow, matrixGraph[u][v])
            v = parent[v]
        v = target
        while (v != source):
            u = parent[v]
            matrixGraph[u][v] -= pathFlow
            matrixGraph[v][u] += pathFlow
            v = parent[v]
        maxFlow += pathFlow
    return(maxFlow)

tests, run = int(input()), 1
while (run <= tests):
    matrixGraph = [[0] * 54 for i in range(54)]
    problems = int(input())
    name = []
    for i in range(problems):
        line = list(input().split())
        for i in range(1, len(line)):
            line[i] = line[i].lower()
            line[i] = list(line[i])
            line[i][0] = line[i][0].upper()
            line[i] = ''.join(line[i])
        name += [line[1:]]
    if (DEBUG): print("name", name)

    graph = [[] for i in range(54)]
    matrixGraph = [[0] * 54 for i in range(54)]
    for i in range(1, problems + 1):
        graph[0] += [i]
        graph[i] += [0]
        matrixGraph[0][i] = 1
    for i in range(27, 54):
        graph[i] += [53]
        graph[53] += [i]
        matrixGraph[i][53] = 1

    for i in range(problems):
        for j in name[i]:
            graph[i + 1] += [ord(j[0]) - ord('A') + 27]
            graph[ord(j[0]) - ord('A') + 27] += [i + 1]
            matrixGraph[i + 1][ord(j[0]) - ord('A') + 27] = 1

    ans = fordFulkerson(graph, matrixGraph, 0, 53)
    if (DEBUG): print(ans)

    print("Case #%d:" % run)
    for i in range(27, 53):
        for j in range(1, 27):
            if (matrixGraph[i][j]):
                for k in name[j - 1]:
                    if (ord(k[0]) - ord('A') + 27 == i):
                        print(k)

    run += 1