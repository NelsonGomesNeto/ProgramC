from heapq import * #heapq is a minimum priority queue by default

def dijkstra(graph, visited, cost, path, start):
    cost[start] = 0 # Setting cost to go to origin node
    queue = [] # Initializing the Priority Queue (PQ)
    path[start] = [start] # Setting up the path
    heappush(queue, [cost[start], start]) # Adding first node to PQ, it will be ordered by the costs

    while (queue): # While queue not empty
        v = heappop(queue)[1] # pop the vertice to visit from queue

        if (not visited[v]):
            visited[v] = 1
            for u in graph[v]:
                # Cost until now + cost to this node < cost previously calculated to this node
                if (cost[v] + u[1] < cost[u[0]]):
                    cost[u[0]] = cost[v] + u[1]
                    path[u[0]] = [v]
                    heappush(queue, [cost[u[0]], u[0]])

tests, run = int(input()), 1
while (run <= tests):
    places, paths = map(int, input().split())
    graph = [[] for i in range(places + 1)]
    for i in range(paths):
        e, o, t = map(int, input().split())
        graph[e] += [[o, t]]
        graph[o] += [[e, t]]
        #print(graph)

    visited = [0] * (places + 1)
    cost = [9999999999999] * (places + 1)
    path = [0] * (places + 1)
    dijkstra(graph, visited, cost, path, 1)

    orders = int(input())
    orders = list(map(int, input().split()))
    total = 0
    for i in orders:
        total += 2 * cost[i]

    print("caso ", run, ": ", total, sep='')
    run += 1
