inf = 1<<20

def mergeArray(a, b):
    lol = []
    i, j = 0, 0
    while (i < len(a) and j < len(b)):
        if (i == len(a)):
            lol += [b[j]]
            j += 1
        elif (j == len(b)):
            lol += [a[i]]
            i += 1
        elif (a[i] < b[j]):
            lol += [a[i]]
            i += 1
        else:
            lol += [b[j]]
            j += 1
    return(lol)

def printGraph(graph):
    for i in range(len(graph)):
        print(i, end='')
        for j, c in graph[i]:
            print(" -> (", j, ", ", c, ")", sep='', end='')
        print()

def root(v):
    if (parent[v] < 0):
        return(v)
    else:
        parent[v] = root(parent[v])
        return(parent[v])

def isSameSet(u, v):
    return(root(v) == root(u))

def merge(u, v):
    v = root(v)
    u = root(u)
    if (u == v): return

    if (parent[u] < parent[v]):
        aux = parent[u]
        parent[u] = parent[v]
        parent[v] = aux

    parent[v] += parent[u]
    parent[u] = v

def setSize(v):
    return(-1 * parent[root(v)])

def kruskal(edge):
    spanningTree, cost = [[] for i in range(vertices)], 0
    done, missing = [], []
    for c, u, v in edge:
        if (not isSameSet(u, v)):
            spanningTree[u] += [[v, c]]
            spanningTree[v] += [[u, c]]
            done += [[c, u, v]]
            merge(u, v)
            cost += c
        else: missing += [[c, u, v]]
    return(spanningTree, cost, done, missing)

vertices, edges = map(int, input().split())
parent = [-1] * vertices
edge = []
for i in range(edges):
    u, v, c = map(int, input().split())
    edge += [[c, u, v]]
edge.sort()

spanningTree, cost, d, m = kruskal(edge)

#print("First Spanning Tree:")
#printGraph(spanningTree)
print("First Spanning Tree Cost", cost)

#print("done:", d)
#print("missing:", m)
bestSpanningTree, bestCost = [], inf
for i in range(len(edge) - 1):
    newEdge = []
    if (i): newEdge += edge[0:i]
    if (i < len(edge) - 1): newEdge += edge[i + 1:]
    #newEdge = mergeArray(newEdge, m)
    #newEdge.sort()
    parent = [-1] * vertices
    newSpanningTree, newCost, t1, t2 = kruskal(newEdge)
    if (newCost < bestCost and newCost != 0 and newCost > cost):
        bestCost = newCost
        bestSpanningTree = newSpanningTree

#print("Second Spanning Tree:")
#printGraph(bestSpanningTree)
print("Second Spanning Tree Cost:", bestCost)