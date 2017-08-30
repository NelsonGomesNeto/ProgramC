from heapq import *

def dijkstra(graph, cost, visited, path, start):
    cost[start] = 0
    queue = []
    path[start] = start
    heappush(queue, [cost[start], start])

    while (queue):
        v = heappop(queue)[1]
        if (not visited[v]):
            visited[v] = 1
            for u in graph[v]:
                if (cost[v] + u[1] < cost[u[0]]):
                    cost[u[0]] = cost[v] + u[1]
                    path[u[0]] = v
                    heappush(queue, [cost[u[0]], u[0]])

tests, run = int(input()), 1
print("SHIPPING ROUTES OUTPUT")
while (run <= tests):
    print("\nDATA SET  ", run, "\n", sep='')
    ports, aqua, queries = map(int, input().split())
    p, key = input().split(), range(0, ports)
    dictionary = dict(zip(p, key))
    #print("Dictionary:", dictionary, '\n')

    graph = [[] for i in range(ports)]
    for i in range(aqua):
        u, v = input().split()
        graph[dictionary[u]] += [[dictionary[v], 1]]
        graph[dictionary[v]] += [[dictionary[u], 1]]
    #print("Graph:", graph, '\n')

    for i in range(queries):
        q = input().split()
        packageSize, origin, destiny = int(q[0]), dictionary[q[1]], dictionary[q[2]]
        cost, visited, path = [99999999] * ports, [0] * ports, [0] * ports
        dijkstra(graph, cost, visited, path, origin)
        #print(q, cost)
        if (cost[destiny] == 99999999):
            print("NO SHIPMENT POSSIBLE")
        else:
            print("$", cost[destiny] * packageSize * 100, sep='')

    run += 1
print("\nEND OF OUTPUT")
