def floodfill(graph, visited, i):
    contamined = 0
    if (visited[i] == 1):
        return(0)

    #print("Visiting:", i)
    visited[i] = 1
    contamined += 1
    for i in graph[i]:
        if (visited[i] == 0):
            contamined += floodfill(graph, visited, i)
            visited[i] = 1

    return(contamined)

while (True):
    students, groups = map(int, input().split())
    if (students == 0 and groups == 0):
        break
    graph = [[] for i in range(students + 1)]
    for i in range(0, groups):
        g = list(map(int, input().split()))
        j = g[1]
        for k in g[2:]:
            graph[j] += [k]
            graph[k] += [j]
    #print(graph)
    visited = [0] * (students + 1)
    contamined = floodfill(graph, visited, 0)
    print(contamined)
