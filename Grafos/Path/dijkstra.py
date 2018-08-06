from heapq import *
inf = 1e83921839210

def columns(graph):
    s = ""
    for u in graph:
        s += "|  " + str(u) + "  "
    return(s)

def inside(array): # It's actually a map haha
    s = ""
    for i in array:
        size = len(str(array[i]))
        # print(array[i], size)
        s += "| "
        for kk in range(2 - size):
            s += " "
        s += str(array[i])
        for kk in range(2 - size):
            s += " "
        s += " "
        if (not (size & 1)): s += " "

    return(s)

def printEveryPath(graph, prev, source):
    for u in graph:
        if (u == source or prev[u] == '-'): continue
        now, path = prev[u], [u]
        while (now != source):
            path += [now]
            now = prev[now]
            path += [source]
            path.reverse()
            print("Path to ", u, ": ", *path, sep='')

def dijkstra(graph, source, verbose):
    pq, cost, prev, step = [], {}, {}, 1
    for i in graph: cost[i], prev[i] = inf, '-'
    cost[source] = 0

    heappush(pq, [[source, 0]])
    while (pq):
        u, c = heappop(pq)[0]
        if (verbose):
            print("Step %d:" % step)
            print("\t     ", columns(graph))
            print("\tCost:", inside(cost))
            print("\tPrev:", inside(prev))
        for v in graph[u]:
            if (c + graph[u][v] < cost[v]):
                cost[v] = c + graph[u][v]
                prev[v] = u
                heappush(pq, [[v, cost[v]]])
        step += 1

    return(cost, prev)

graph = {}
source = input()
while (True):
    try:
        u, v, c = input().split()
        c = int(c)
        if (u not in graph): graph[u] = {}
        if (v not in graph): graph[v] = {}
        graph[u][v] = c
    except:
        break
print("Graph:", graph)

cost, prev = dijkstra(graph, source, True)
print()
print("Cost:", cost)
print("Prev:", prev)
printEveryPath(graph, prev, source)
