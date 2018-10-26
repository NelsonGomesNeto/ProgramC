def floodFill(graph, visited, start):
    if (visited[start]): return
    visited[start] = True
    print("Visiting:", start)
    for v in graph[start]:
        floodFill(graph, visited, v)

size = int(input())
graph = [[] for i in range(size)]
for i in range(size):
    u, v = map(int, input().split())
    graph[u] += [v]
    graph[v] += [u]
print("Graph:", graph)
visited = [False] * size
floodFill(graph, visited, 0)
print("Visited:", visited)