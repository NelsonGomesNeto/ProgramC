from copy import deepcopy
global inf
VERBOSE = 0
inf = 1<<20

def printGraph(graph):
    for u in sorted(graph):
        print(u, end=" -> ")
        for v in sorted(graph[u]):
            print((v, graph[u][v]), end=' ')
        print()

def bellmannFord(graph, prev, source, target):
    global inf
    cost = {}
    for i in graph: cost[i], prev[i] = inf, '-'
    cost[source] = 0

    for i in range(len(graph) - 1):
        done = 0
        for u in graph: # for each
            for v in graph[u]: # graph edge
                if (graph[u][v][0] != 0 and cost[u] + graph[u][v][1] < cost[v]):
                    cost[v] = cost[u] + graph[u][v][1]
                    prev[v] = u
                    done += 1
        if (done == 0): break

    return(cost[target] != inf)

def minCostFlow(graph, source, target):
    global inf
    prev, maxFlow, cost = {}, 0, 0
    while (bellmannFord(graph, prev, source, target)):
        v, flow = target, inf
        if (VERBOSE): print("path", v, end=" -> ")
        while (v != source):
            flow = min(flow, graph[prev[v]][v][0])
            v = prev[v]
            if (VERBOSE): print(v, end=" -> ")
        if (VERBOSE): print("|| flow:", flow)
        maxFlow += flow
        if (flow <= 0): break
        v = target
        while (v != source):
            cost += graph[prev[v]][v][1] * flow
            graph[prev[v]][v][0] -= flow
            if (prev[v] not in graph[v]): graph[v][prev[v]] = [0, 0]
            graph[v][prev[v]][0] += flow
            graph[v][prev[v]][1] = -graph[prev[v]][v][1] # negative cost
            v = prev[v]
        if (VERBOSE): print()
        if (VERBOSE): printGraph(graph)
    return(maxFlow, cost)

graph = {}
source, target = "source", "target"
graph[source], graph[target] = {}, {}
n = int(input())
for i in range(1, n + 1):
    graph["task %d" % i] = {}
    graph["task %d" % i][target] = [1, 0] # flow, cost

for i in range(1, n + 1):
    ce = input().split()
    graph[source]["emp %d" % i] = [1, 0]
    graph["emp %d" % i] = {}
    for j, c in enumerate(ce):
        graph["emp %d" % i]["task %d" % (j + 1)] = [1, int(c)]

prevGraph = deepcopy(graph)
if (VERBOSE): printGraph(graph)

flow, cost = minCostFlow(graph, source, target)
# print("flow:", flow, ", cost:", cost)
print(cost)
