from heapq import *
DEBUG = 0
inf = 2**33

def dijkstra(graph, cost, start):
    cost[start] = [0] * (len(graph) + 10)
    stops = -1
    pq = []
    heappush(pq, [cost[start][stops], start, stops])
    while (pq):
        c, v, stops = heappop(pq)
        if (stops > len(graph)): continue
        stops += 1
        for u in graph[v]:
            if (c + u[1] < cost[u[0]][stops]):
                for i in range(stops, len(graph) + 10):
                    cost[u[0]][i] = min(cost[u[0]][i], c + u[1])
                heappush(pq, [c + u[1], u[0], stops])
            #if (stops < stopovers):

tests, run = int(input()), 1
while (run <= tests):
    if (run > 1): print()
    try:
        trash = input()
    except:
        trash = 1

    cities = int(input())
    stringToInt, intToString = {}, {}
    for i in range(cities):
        city = input()
        stringToInt[city] = i
        intToString[i] = city

    graph = [[] for i in range(cities)]
    flights = int(input())
    for i in range(flights):
        u, v, c = input().split()
        u, v, c = stringToInt[u], stringToInt[v], int(c)
        graph[u] += [[v, c]]
    if (DEBUG): print("graph", graph)

    print("Scenario #%d" % run)
    queries = list(map(int, input().split()))
    cost = [[inf] * (cities + 10) for i in range(cities)]
    dijkstra(graph, cost, 0)
    #bellmanFord(graph, cost, 0)
    for i in queries[1:]:
        #print(cost[i:][cities - 1])
        if (i > len(graph)): i = len(graph)
        if (cost[cities - 1][i] == inf):
            print("No satisfactory flights")
        else:
            print("Total cost of flight(s) is $%d" % cost[cities - 1][i])

    run += 1