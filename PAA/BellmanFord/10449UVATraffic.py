inf = 2**33
DEBUG = 0

def bellmanFord(graph, cost, loop, start):
    parent = [-1] * len(graph)
    cost[start] = 0
    for i in range(len(graph) - 1):
        for u in range(len(graph)):
            for v, c in graph[u]:
                if (cost[u] + c < cost[v] and cost[u] != inf):
                    parent[v] = u
                    cost[v] = cost[u] + c

    if (DEBUG): print("parent", parent)
    for u in range(len(graph)):
        for v, c in graph[u]:
            if (cost[u] + c < cost[v] and cost[v] != inf):
                #loop[u], loop[v] = 1, 1
                #loop[v] = 1
                start, end, done = v, u, 0
                loop[end] = 1
                while (end != start and done < len(graph)):
                    end = parent[end]
                    loop[end] = 1
                    done += 1
                loop[end] = 1
    return(0)

case = 1
while (True):
    try:
        line = list(map(int, input().split()))
    except:
        break
    junctions, costs = line[0], line[1:]
    if (junctions == 0):
        trash = input()
        trash = input()
        print("Set #", case, sep='')
        case += 1
        continue

    graph = [[] for i in range(junctions)]
    roads = int(input())
    for i in range(roads):
        u, v = map(int, input().split())
        u, v = u - 1, v - 1
        graph[u] += [[v, (costs[v] - costs[u])**3]]
    if (DEBUG): print(graph)
    cost, loop = [inf] * junctions, [0] * junctions
    bellmanFord(graph, cost, loop, 0)
    if (DEBUG): print(cost)
    if (DEBUG): print(loop)

    queries = int(input())
    print("Set #", case, sep='')
    for i in range(queries):
        query = int(input())
        query -= 1
        if (cost[query] < 3 or loop[query] or cost[query] == inf):
            print("?")
        else:
            print(cost[query])
    case += 1