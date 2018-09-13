from math import ceil
inf = 1e8414120412431

def printGraph(graph):
    for u in graph:
        print(u, end='')
        for v in graph[u]:
            print(" ->", (v, graph[u][v]), end='')
        print()

def distance(a, b, s):
    x, y, p, q = a[0], a[1], b[0], b[1]
    return(ceil(((p-x)**2 + (q-y)**2) / s**2))

def bellmannFord(graph, prev, source, target):
    cost = {}
    for i in graph: cost[i] = inf
    cost[source] = 0
    for i in range(len(graph) - 1):
        done = 0
        for u in graph:
            for v in graph[u]:
                if (graph[u][v][0] != 0 and cost[u] + graph[u][v][1] < cost[v]):
                    cost[v] = cost[u] + graph[u][v][1]
                    prev[v] = u
                    done = 1
        if (done == 0): break
    return(cost[target] != inf)


def minCostFlow(graph, source, target):
    prev, maxFlow, minCost = {}, 0, 0
    while (bellmannFord(graph, prev, source, target)):
        v, flow = target, inf
        while (v != source):
            flow = min(flow, graph[prev[v]][v][0])
            v = prev[v]
        maxFlow += flow

        v = target
        while (v != source):
            graph[prev[v]][v][0] -= flow
            graph[v][prev[v]][0] += flow
            v = prev[v]
        prev = {}
    #
    # minCost = []
    # for v in graph["mid"]:
    #     if (graph["mid"][v][0]):
    #         each = inf
    #         for u in graph[v]:
    #             if (graph[v][u][0]):
    #                 # print(u, v, graph[v][u])
    #                 minCost += [graph[u][v][1]]
    # minCost.sort()

    return(maxFlow, minCost)

n, m, k = map(int, input().split())
teamPos, team = [], []
for i in range(n):
    teamPos += [list(map(int, input().split()))]
    team += ["team %d" % i]
checkPos, check = [], []
for i in range(m):
    checkPos += [list(map(int, input().split()))]
    check += ["check %d" % i]
teamSpeed = list(map(int, input().split()))
# print(n, m, k, teamPos, teamSpeed, checkPos)

# [flow, cost]
graph = {}
graph["source"], graph["mid"], graph["target"] = {}, {}, {}
for i in range(m):
    graph[check[i]] = {}
    graph[check[i]]["mid"] = [1, 0]
    graph["mid"][check[i]] = [0, 0]
    for j in range(m):
        graph[check[i]][check[j]] = [1, inf]
for i in range(n):
    graph["source"][team[i]] = [1, 0]
    graph[team[i]] = {}
    graph[team[i]]["source"] = [0, 0]
    for j in range(m):
        d = distance(teamPos[i], checkPos[j], teamSpeed[i])
        graph[team[i]][check[j]] = [1, d]
        graph[check[j]][team[i]] = [0, -d]
graph["mid"]["target"] = [k, 0]
graph["target"]["mid"] = [0, 0]

# printGraph(graph)
flow, cost = minCostFlow(graph, "source", "target")
# print(flow, cost)
print(cost)
