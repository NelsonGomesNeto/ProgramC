def floodFill(graph, visited, leafs, root, level):
    if (visited[root]): return
    visited[root] = 1
    leafs[level] += [root]
    if (len(graph[root]) == 0): return
    for u in graph[root]:
        floodFill(graph, visited, leafs, u, level + 1)

while (True):
    try:
        lines = int(input())
    except:
        break
    graph, first = {}, -1
    for i in range(lines):
        u, v = input().split()
        if (first == -1): first = u
        if (u not in graph):
            graph[u] = []
        if (v not in graph):
            graph[v] = []
        graph[u] += [v]
    print("graph", graph)

    leafs = [[] for i in range(len(graph) + 1)]
    visited = {}
    for i in graph:
        visited[i] = 0
    for i in graph:
        if (not visited[i]):
            floodFill(graph, visited, leafs, i, 0)
            print(visited)

    allLeafs = []
    for i in range(len(leafs)):
        leafs[len(leafs) - i - 1].sort()
        allLeafs += leafs[len(leafs) - i - 1]
    print("allLeafs", allLeafs)
    # for i in leafs:
    #     if (len(i) == 0):
    #         break
    #     for j in i:
    #         print(j)