from heapq import *
inf = 2 ** 33

def waitingTime(time, cic):
    if (time % cic == 0):
        return(0)
    return(cic - (time % cic))

def dijkstra(graph, cost, visited, start, end, tripTime):
    time = 0
    cost[start] = 0
    pq = []
    #path[start] = start
    heappush(pq, [cost[start], start])
    #pq.put([cost[start], start])
    while (len(pq) != 0):
        time, v = heappop(pq)
        #v, time = v[1], v[0]
        #if (time > cost[v]):
            #continue
        if (not visited[v]):
            visited[v] = 1
            for u in graph[v]:
                wait = waitingTime(time, u[1])
                if (cost[v] + wait + tripTime < cost[u[0]]):
                    cost[u[0]] = cost[v] + wait + tripTime
                    #path[u[0]] = v
                    #pq.put([cost[u[0]], u[0]])
                    heappush(pq, [cost[u[0]], u[0]])

def shortestPath(path, start, end):
    p = []
    while (end != start):
        p += [end]
        end = path[end]
    p += [end]
    p.reverse()
    return(p)

tests, run = int(input()), 1
while (run <= tests):
    print("Caso #", run, ": ", sep='', end='')
    origin, destiny, tripTime, stations = input().split()
    tripTime, stations = int(tripTime), int(stations)
    #print(origin, destiny, tripTime, stations)

    graph, cost, visited = {}, {}, {}
    graph[origin], graph[destiny] = [], []
    cost[origin], cost[destiny] = inf, inf
    visited[origin], visited[destiny] = 0, 0
    for i in range(stations):
        s = input().split()
        if (s[0] not in graph):
            graph[s[0]] = []
        if (s[1] not in graph):
            graph[s[1]] = []
        graph[s[0]].append( [s[1], int(s[2])] )
        #graph[s[1]].append( [s[0], int(s[2])] )
        cost[s[0]], cost[s[1]] = inf, inf
        visited[s[0]], visited[s[1]] = 0, 0

    #path = [-1] * stations
    dijkstra(graph, cost, visited, origin, destiny, tripTime)
    #p = shortestPath(path, dictionary[origin], dictionary[destiny])
    #print("Path:", p)
    #print("Cost:", cost)

    if (cost[destiny] == inf):
        print("Destino inalcancavel")
    else:
        print(cost[destiny], "anticalmas")

    run += 1
