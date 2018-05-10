def root(v):
    if (parent[v] < 0):
        return(v)
    else:
        parent[v] = root(parent[v])
        return(parent[v])

def isSameSet(v, u):
    return(root(v) == root(u))

def merge(v, u):
    v, u = root(v), root(u)
    if (v == u): return

    if (parent[u] < parent[v]):
        parent[u], parent[v] = parent[v], parent[u]

    parent[v] += parent[u]
    parent[u] = v

def setSize(v):
    return(-1 * parent[root(v)])

before = 0
for n in range(2, 100):
    #graph = [[1] * n for i in range(n)]
    edge = []
    for i in range(n):
        for j in range(n):
            #graph[i][j] = i ^ j
            edge += [[i ^ j, i, j]]

    parent = [-1] * n
    edge.sort()
    cost = 0
    for c, u, v in edge:
        if (not isSameSet(u, v)):
            merge(u, v)
            cost += c
    print(n, cost, cost - before)
    before = cost