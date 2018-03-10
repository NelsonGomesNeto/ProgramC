from random import randint
import os

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
        aux = parent[u]
        parent[u] = parent[v]
        parent[v] = aux

    parent[v] += parent[u]
    parent[u] = v

def setSize(v):
    return(-1 * parent[root(v)])

testCases = int(input())
for i in range(1, testCases + 1):
    f = open("%d.in" % (i), "w")
    vertices = randint(0, 500)
    done, toPrint = [[0] * vertices for i in range(vertices)], []
    parent = [-1] * vertices
    edges, finalEdges = vertices + vertices // 3, 0
    while (edges > 0 or setSize(0) != vertices):
        u, v, c = randint(0, vertices - 1), randint(0, vertices - 1), randint(1, 1000)
        if (not done[u][v] and u != v):
            done[u][v], done[v][u] = 1, 1
            toPrint += [[u, v, c]]
            edges -= 1
            merge(u, v)
            finalEdges += 1
    print(vertices, finalEdges, file=f)
    for j in toPrint:
        print(*j, file=f)
    f.close()
    os.system("time python3 ./../almostSpanningTree.py < ./%d.in > ./%d.out" % (i, i))