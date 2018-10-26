from heapq import *
from math import sqrt
DEBUG = 0
inf = 2**33

def prim(graph, cost, visited, start):
    total = 0
    cost[start] = 0
    pq = []
    heappush(pq, [cost[start], start])
    while (pq):
        c, v = heappop(pq)
        if (visited[v]): continue
        visited[v] = 1
        total += c
        for u in graph[v]:
            cost[u[0]] = u[1]
            heappush(pq, [cost[u[0]], u[0]])
    return(total)

tests = int(input())
while (tests > 0):
    tests -= 1
    trash = input()
    freckles = int(input())
    pointToInt, intToPoint = {}, {}
    for i in range(freckles):
        line = list(map(float, input().split()))
        pointToInt[(line[0], line[1])] = i
        intToPoint[i] = (line[0], line[1])
    if (DEBUG):
        print("pointToInt", pointToInt)
        print("intToPoint", intToPoint)

    graph = [[] for i in range(freckles)]
    for i in range(freckles):
        for j in range(freckles):
            if (i != j):
                a, b = intToPoint[i], intToPoint[j]
                dist = sqrt((a[0] - b[0])**2 + (a[1] - b[1])**2)
                graph[i] += [[j, dist]]
    if (DEBUG):
        print("graph", graph)

    visited, cost = [0] * (freckles), [inf] * (freckles)
    minCost = prim(graph, cost, visited, 0)

    print("%.2lf" % minCost)
    if (tests > 0):
        print()