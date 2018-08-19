def printGraph(graph):
    for u in range(len(graph)):
        print(u, end=': ')
        for v, c in graph[u]:
            print(v, end=' ')
        print()

def root(v):
    if (parent[v] < 0):
        return(v)
    else:
        parent[v] = root(parent[v])
        return(parent[v])

def isSameSet(v, u):
    return(root(v) == root(u))

def merge(v, u):
    v = root(v)
    u = root(u)
    if (v == u): return
    if (parent[u] < parent[v]):
        parent[u], parent[v] = parent[v], parent[u]
    parent[v] += parent[u]
    parent[u] = v

def setSize(v):
    return(-parent[root(v)])

def kruskal(edges, n):
    edges.sort()
    mst, cost = [[] for i in range(n)], 0
    for c, u, v in edges:
        if (not isSameSet(u, v)):
            merge(u, v)
            mst[u] += [[v, c]]
            mst[v] += [[u, c]]
            cost += c
    return(mst, cost)

source = int(input())
raw = []
vertices = set()
while (True):
    try:
        line = list(map(int, input().split()))
        raw += [line]
        vertices.add(line[0])
        vertices.add(line[1])
    except:
        break
n = len(vertices)
edges = []
for u, v, c in raw:
    edges += [[c, u, v]]
    edges += [[c, v, u]]
parent = [-1] * (n + 1)
mst, cost = kruskal(edges, n + 1)
printGraph(mst)
print("MST Cost:", cost)