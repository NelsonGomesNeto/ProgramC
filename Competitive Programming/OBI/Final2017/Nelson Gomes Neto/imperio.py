def floodFill(graph, visited, start):
    if (start == -1):
        return(0)
    s = 0
    if (not visited[start]):
        s += 1
        visited[start] = 1
        for v in graph[start]:
            s += floodFill(graph, visited, v)
    return(s)

size = int(input())
graph = [[] for i in range(size)]
for i in range(size - 1):
    v, u = map(int, input().split())
    v -= 1
    u -= 1
    graph[v] += [u]
    graph[u] += [v]
#print(graph)

minimum = 9999999999
for i in range(size):
    for j in range(0, len(graph[i])):
        #print("Removing", graph[i][j])
        b = graph[i][j]
        graph[i][j] = -1
        visited = [0] * size
        #print(graph)
        aCity = floodFill(graph, visited, i)
        #print(a)
        bCity = floodFill(graph, visited, b)
        #print(b)
        dif = abs(aCity - bCity)
        minimum = min(dif, minimum)
        graph[i][j] = b

print(minimum)
