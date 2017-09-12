from heapq import *
inf = 2**33

def dijkstra(graph, cost, visited, start, end):
    cost[start] = [0, 0]
    pq = []
    heappush(pq, [cost[start], start, 0])
    while (pq):
        v, paid = heappop(pq)[1:]
        if (visited[v] == 2): continue
        visited[v] += 1
        for u in graph[v]:
            if (cost[v][paid] + u[1] < cost[u[0]][1 - paid]):
                cost[u[0]][1 - paid] = cost[v][paid] + u[1]
                heappush(pq, [cost[u[0]][1 - paid], u[0], 1 - paid])

cities, streets = map(int, input().split())
graph = [[] for i in range(cities + 1)]
for i in range(streets):
    u, v, c = map(int, input().split())
    graph[u] += [[v, c]]
    graph[v] += [[u, c]]

cost, visited = [[inf, inf] for i in range(cities + 1)], [0] * (cities + 1)
dijkstra(graph, cost, visited, 1, cities)

if (cost[cities][0] == inf):
    print(-1)
else:
    print(cost[cities][0])
