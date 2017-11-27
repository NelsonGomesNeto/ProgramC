from heapq import *
from queue import *
inf = 2**33

def dijkstra(graph, cost, visited, start):
    cost[start] = 0
    queue = []
    heappush(queue, [cost[start], start])

    while(queue):
        v = heappop(queue)[1]
        if (not visited[v]):
            visited[v] = 1
            for u in graph[v]:
                if (cost[v] + u[1] < cost[u[0]]):
                    cost[u[0]] = cost[v] + u[1]
                    heappush(queue, [cost[u[0]], u[0]])

def bfs(graph, visited, start, end):
    cost = 0
    queue = Queue()
    queue.put([cost, start])
    while (not queue.empty()):
        cost, v = queue.get()
        if (v == end):
            return(cost)
        cost += 1
        if (not visited[v]):
            visited[v] = 1
            for u in graph[v]:
                if (u == end):
                    return(cost)
                queue.put([cost, u[0]])

    return(inf)

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
        cost = [inf] * ports
        visited = [0] * ports
        dijkstra(graph, cost, visited, dictionary[q[1]])
        #cost = bfs(graph, visited, dictionary[q[1]], dictionary[q[2]])
        #print(q, cost)
        if (cost[dictionary[q[2]]] == inf):
            print("NO SHIPMENT POSSIBLE")
        else:
            print("$", cost[dictionary[q[2]]] * int(q[0]) * 100, sep='')

    run += 1
print("\nEND OF OUTPUT")
