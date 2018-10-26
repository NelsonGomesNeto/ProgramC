from heapq import *
inf = 2**33

def dijkstra(graph, cost, visisted, path, start):
    cost[start] += [0]
    #path[start] = start
    pq = []
    heappush(pq, [0, start])
    while (pq):
        c, v = heappop(pq)
        if (visited[v]): continue
        visited[v] = 1
        for u in graph[v]:
            #if (u[0] == -1 or u[1] == -1): continue
            #if (cost[v] + u[1] < cost[u[0]]):
            newCost = c + u[1]
            cost[u[0]] += [newCost]
            #path[u[0]] = v
            heappush(pq, [newCost, u[0]])

def shortestPath(path, start, end):
    p = []
    while (end != start):
        p += [end]
        end = path[end]
    p += [end]
    p.reverse()
    return(p)

while (True):
    points, streets = map(int, input().split())
    if (points == 0 and streets == 0):
        break
    origin, destiny = map(int, input().split())
    graph = [[] for i in range(points)]
    for i in range(streets):
        u, v, c = map(int, input().split())
        graph[u] += [[v, c]]
    #print(graph)

    cost, visited, path = [[] for i in range(points)], [0] * points, [-1] * points
    dijkstra(graph, cost, visited, path, origin)
    cost[destiny].sort()
    print(cost, len(cost[destiny]), destiny)
    if (len(cost[destiny]) <= 1):
        print(-1)
    else:
        minimum = cost[destiny]
        for i in cost[destiny]:
            if (i != minimum):
                print(i)
                break
