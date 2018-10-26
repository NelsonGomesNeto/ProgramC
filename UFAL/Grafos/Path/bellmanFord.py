inf = 1e83921839210

def columns(graph):
    s = ""
    for u in sorted(graph):
        s += "|  " + str(u) + "  "
    return(s)

def inside(array): # It's actually a map haha
    s = ""
    for i in sorted(array):
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

def printEveryPath(graph, prev, cost, source):
    for u in sorted(graph):
        if (u == source or prev[u] == '-'): continue
        now, path = prev[u], [u]
        while (now != source):
            path += [now]
            now = prev[now]
        path += [source]
        path.reverse()
        print("Path to ", u, ": ", *path, ", cost: ", cost[u], sep='')

def bellmanFord(graph, source, verbose):
    cost, prev, step = {}, {}, 1
    for i in graph: cost[i], prev[i] = inf, '-'
    cost[source] = 0

    for i in range(len(graph) - 1):
        if (verbose):
            print("Step %d:" % step)
            print("\t     ", columns(graph))
            print("\tCost:", inside(cost))
            print("\tPrev:", inside(prev))
        for u in graph:
            for v in graph[u]:
                if (cost[u] + graph[u][v] < cost[v]):
                    cost[v] = cost[u] + graph[u][v]
                    prev[v] = u
        step += 1

    for u in graph:
        for v in graph[u]:
            if (cost[u] + graph[u][v] < cost[v]):
                print("Has a negative cycle")
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

cost, prev = bellmanFord(graph, source, True)
print()
print("Cost:", cost)
print("Prev:", prev)
printEveryPath(graph, prev, cost, source)
