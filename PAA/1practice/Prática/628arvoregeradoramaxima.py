from heapq import *

def prim(graph, cost, visited, path, start):
    total = 0
    cost[start] = 0
    queue = []
    path[start] = start
    heappush(queue, [cost[start], start])
    while (queue):
        c, v = heappop(queue)
        if (not visited[v]):
            visited[v] = True
            total += c
            for u in graph[v]:
                #if (cost[v] + u[1] < cost[u[0]]):
                cost[u[0]] = u[1]
                path[u[0]] = v
                heappush(queue, [cost[u[0]], u[0]])
    return(total)

tests = int(input())
while (tests > 0):
    size, conections = map(int, input().split())
    #print(size, conections)

    graph = [[] for i in range(size + 1)]
    for i in range(conections):
        v, u, c = map(int, input().split())
        graph[v] += [[u, -c]]
        graph[u] += [[v, -c]]
    #print("Graph:", graph)


    cost, visited, path = [9999999999] * (size + 1), [False] * (size + 1), [-1] * (size + 1)
    totalWeight = prim(graph, cost, visited, path, 1)
    #print("Cost:", cost)
    #print("Path:", path)

    print(totalWeight * (-1))

    tests -= 1
