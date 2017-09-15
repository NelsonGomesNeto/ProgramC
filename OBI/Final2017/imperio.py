import sys
sys.setrecursionlimit(2 ** 20)

best = [2**33]

def diff(cities, total):
    return(abs(cities - abs(total - cities)))

def dfs(graph, visited, start, total):
    cities = 1
    if (visited[start]): return(cities)
    visited[start] = 1
    for v in graph[start]:
        if (not visited[v]):
            cities += dfs(graph, visited, v, total)

    best[0] = min(best[0], diff(cities, total))
    return(cities)


cities = int(input())
graph = [[] for i in range(cities + 1)]
for i in range(cities - 1):
    u, v = map(int, input().split())
    graph[u] += [v]
    graph[v] += [u]

visited = [0] * (cities + 1)
dfs(graph, visited, 1, cities)
print(best[0])