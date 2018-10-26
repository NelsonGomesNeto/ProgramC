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

vertices, edges = map(int, input().split())
graph = [[] for i in range(vertices)]
parent = [-1] * vertices
edge = []
for i in range(edges):
    u, v, c = map(int, input().split())
    graph[u] += [[v, c]]
    graph[v] += [[u, c]]
    edge += [[c, u, v]]
print("Graph:")
printGraph(graph)

edge.sort()
#sprint("Edge:", edge)
spanningTree, cost = [[] for i in range(vertices)], 0
for c, u, v in edge:
    if (not isSameSet(u, v)):
        spanningTree[u] += [[v, c]]
        spanningTree[v] += [[u, c]]
        merge(u, v)
        cost += c
print("SpanningTree:")
printGraph(spanningTree)
print("Cost:", cost)

