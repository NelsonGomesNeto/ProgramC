from heapq import *
inf = 2**33

def dijkstra(graph, monster, cost, visited, start, end):
    cost[start] = 0
    pq = []
    heappush(pq, [cost[start], start])
    while (pq):
        time, v = heappop(pq)
        if (visited[v] == monster[v]): continue
        visited[v] += 1
        for u in graph[v]:
            if ((time + 1) % monster[u] != 0):
                if (time + 1 < cost[u]):
                    cost[u] = time + 1
                heappush(pq, [time + 1, u])

#main
rooms, start, end, corridors = map(int, input().split())
monster = list(map(int, input().split()))
graph = [[] for i in range(rooms)]
for i in range(corridors):
    u, v = map(int, input().split())
    graph[u] += [v]
    #graph[v] += [u]
cost, visited = [inf] * rooms, [0] * rooms
dijkstra(graph, monster, cost, visited, start, rooms - 1)
#print(visited)
#print(cost)
if (cost[end] == inf):
    print("Araragi morreu")
else:
    print(cost[end], "minutos")