import sys
sys.setrecursionlimit(2**20)

def solve(graph, gold, visited, capacity, now, prev, pathCost):
    if (visited[now]): return(0)
    visited[now] = 1
    ans = 0
    for v in graph[now]:
        ans += solve(graph, gold, visited, capacity, v[0], now, v[1])

    if (prev != -1):
        ans += 2 * pathCost * (int(gold[now] / capacity) + (gold[now] % capacity != 0))
        gold[prev] += gold[now]
    return(ans)

cities, capacity = map(int, input().split())
gold = list(map(int, input().split()))
graph = [[] for i in range(cities)]
for i in range(cities - 1):
    u, v, c = map(int, input().split())
    u -= 1
    v -= 1
    graph[u] += [[v, c]]
    graph[v] += [[u, c]]

visited = [0] * cities
ans = solve(graph, gold, visited, capacity, 0, -1, 0)
print(ans)