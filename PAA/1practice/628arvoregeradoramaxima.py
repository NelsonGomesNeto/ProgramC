from heapq import *

def prim(graph, cost, visited, path, start):
    cost[start] = 0
    queue = []
    path[start] = start
    heappush(queue, [cost[start], start])
    while (queue):
        v = heappop(queue)[1]
        if (not visited[v]):
            visited[v] = True
            for u in graph[v]:
                if (cost[v] + u[1] < cost[u[0]]):
                    cost[u[0]] = -u[1]
                    path[u[0]] = v
                    heappush(queue, [cost[u[0]], u[0]])

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
    prim(graph, cost, visited, path, 1)
    #print("Cost:", cost)
    #print("Path:", path)

    #nodes = set(path)
    totalWeight = 0
    for i in cost[1:len(cost) - 1]:
        totalWeight += i

    print(totalWeight)

    tests -= 1
