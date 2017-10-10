inf = 2**33
def bellmanFord(graph, visited, cost):
    for i in range(len(graph) - 1):
        for u in range(len(graph)):
            for v, c in graph[u]:
                if (cost[u] + c < cost[v]):
                    cost[v] = cost[u] + c

    for u in range(len(graph)):
        for v, c in graph[u]:
            if (cost[u] + c < cost[v]):
                return(1)
    return(0)

tests = int(input())
while (tests > 0):
    vertices, edges = map(int, input().split())
    graph = [[] for i in range(vertices)]
    for i in range(edges):
        u, v, c = map(int, input().split())
        graph[u] += [[v, c]]

    visited, cost = [0] * vertices, [inf] * vertices
    canTravel = bellmanFord(graph, visited, cost)
    possible = ["not possible", "possible"]
    print(possible[canTravel])
    tests -= 1
