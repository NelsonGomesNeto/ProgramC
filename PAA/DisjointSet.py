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
    if (v == u) return

    if (parent[u] < parent[v]):
        aux = parent[u]
        parent[u] = parent[v]
        parent[v] = aux

    parent[v] += parent[u]
    parent[u] = v

def setSize(v):
    return(-1 * parent[root(v)])

parent = [-1] * 10
isSameSet(0, 2)
merge(0, 2)
merge(1, 2)
isSameSet(1, 2)
print(parent)
print(setSize(2))