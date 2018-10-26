from heapq import *

def dijkstra(graph, cost, visited, path, start, end):
    cost[start] = 0
    queue = []
    path[start] = start
    heappush(queue, [cost[start], start])
    while (queue):
        time, v = heappop(queue)
        if (visited[v] < 3):
            visited[v] += 1
            for u in graph[v]:
                if ((u[1] == 1 and time % 3 == 0) or (u[1] == 0 and time % 3 != 0)):
                    if (time + 1 < cost[u[0]]):
                        cost[u[0]] = time + 1
                        path[u[0]] = v
                    heappush(queue, [time + 1, u[0]])

rot, entrance, out, streets = map(int, input().split())
graph = [[] for i in range(rot)]
for i in range(0, streets):
    e, o, t = map(int, input().split())
    graph[e] += [[o, t]]
    #graph[o] += [[e, t]]
#print("Graph:", graph)

cost, visited, path = [99999999] * rot, [False] * rot, [-1] * rot
dijkstra(graph, cost, visited, path, entrance, out)
#print("Cost:", cost)
#print("Path:", path)
#print("Shortest Path", shortestPath(path, entrance, out)) Doesn't work because of cycles

if (cost[out] == 99999999):
    print("*")
else:
    print(cost[out])
