import sys
sys.setrecursionlimit(2**20)

def printTree(segTree, lo, hi, i):
    print(lo, hi, segTree[i])
    if (lo >= hi): return
    mid = (lo + hi) // 2
    printTree(segTree, lo, mid, 2*i + 1)
    print()
    printTree(segTree, mid + 1, hi, 2*i + 2)

def operation(a, b):
    return(max(a, b))

def build(segTree, array, lo, hi, i):
    if (lo >= hi):
        segTree[i] = array[lo]
        return(segTree[i])
    mid = (lo + hi) // 2
    left = build(segTree, array, lo, mid, 2*i + 1)
    right = build(segTree, array, mid + 1, hi, 2*i + 2)
    segTree[i] = operation(left, right)
    return(segTree[i])

def update(segTree, lo, hi, i, p, value):
    if (lo > p or hi < p or lo >= hi):
        if (lo == p): segTree[i] = value
        return(segTree[i])
    mid = (lo + hi) // 2
    left = update(segTree, lo, mid, 2*i + 1, p, value)
    right = update(segTree, mid + 1, hi, 2*i + 2, p, value)
    segTree[i] = operation(left, right)
    return(segTree[i])

def get(segTree, lo, hi, qlo, qhi, i):
    if (lo > qhi or hi < qlo): return(0)
    if (lo >= hi): return(segTree[i])
    mid = (lo + hi) // 2
    left = get(segTree, lo, mid, qlo, qhi, 2*i + 1)
    right = get(segTree, mid + 1, hi, qlo, qhi, 2*i + 2)
    return(operation(left, right))

n = int(input())
array = list(map(int, input().split()))
segTree = [0] * (n * 3)
build(segTree, array, 0, n - 1, 0)
printTree(segTree, 0, n - 1, 0)

queries = int(input())
for i in range(queries):
    line = input().split()
    print(line)
    if (line[0] == "U"):
        p, value = int(line[1]), int(line[2])
        array[p] = value
        update(segTree, 0, n - 1, 0, p, value)
        printTree(segTree, 0, n - 1, 0)
    if (line[0] == "G"):
        qlo, qhi = int(line[1]), int(line[2])
        print(get(segTree, 0, n - 1, qlo, qhi, 0))