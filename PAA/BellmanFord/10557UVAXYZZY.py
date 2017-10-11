DEBUG = 0
inf = 2**33

def bellmanFord(graph, cost, path, loop, start):
    path[start] = start
    cost[start] = 100
    for i in range(1, len(graph) - 1):
        for u in range(1, len(graph)):
            for v, c in graph[u]:
                if (cost[u] + c < cost[v] and cost[u] != inf):
                    path[v] = u
                    cost[v] = cost[u] + c
    for u in range(1, len(graph)):
        for v, c in graph[u]:
            if (cost[u] + c > cost[v] and cost[v] != inf):
                loop[v] = 1

def runPath(path, cost, loop, start, end):
    done = 0
    while (end != -1 and end != start and done < len(path) - 1):
        if (loop[end]): return(1)
        end = path[end]
        done += 1
    if (end != -1 and loop[end]): return(1)
    return(0)

while (True):
    rooms = -1
    try:
        rooms = int(input())
    except:
        try:
            rooms = int(input())
        excepte:
            break

    if (rooms == -1): break
    if (rooms == 0): continue
    graph = [[] for i in range(rooms + 1)]
    line = []
    for i in range(rooms):
        try:
            line += [list(map(int, input().split()))]
        except:
            line += [list(map(int, input().split()))]
    for i in range(1, rooms + 1):
        for j in range(line[i - 1][1]):
            graph[i] += [[line[i - 1][j + 2], line[line[i - 1][j + 2] - 1][0]]]
    if (DEBUG): print("graph", graph)

    cost, path, loop = [inf] * (rooms + 1), [-1] * (rooms + 1), [0] * (rooms + 1)
    #bellmanFord(graph, cost, path, loop, 1)
    canWin = 1#runPath(path, cost, loop, 1, rooms)
    if (DEBUG): print("path", path, "cost", cost)

    if (canWin or (cost[rooms] > 0 and cost[rooms] != inf)):
        print("winnable")
    else:
        print("hopeless")
