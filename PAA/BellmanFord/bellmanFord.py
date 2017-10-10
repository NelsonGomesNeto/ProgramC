def bellmanFord(graph, cost, start):
    cost[start] = 0
    for i in range(len(graph) - 1):
        for u in range(len(graph)):
            for v, c in graph[u]:
                if (cost[u] + c < cost[v]):
                    cost[v] = cost[u] + c

    for u in range(len(graph)):
        for v, c in graph[u]:
            if (cost[u] + c < cost[v]):
                return(1) # Has a loop
    return(0) # Doesn't has a loop
