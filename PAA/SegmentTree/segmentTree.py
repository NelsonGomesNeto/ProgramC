import time
from math import log2
DEBUG = 0

def getMid(lo, hi):
    return((lo + hi) // 2)
    #return(lo + (hi - lo) // 2)

def createSegmentTree(array, segmentTree, i, lo, hi):
    iterations[0] += 1
    if (lo == hi):
        segmentTree[i] = array[lo]
        return(array[lo])

    mid = getMid(lo, hi)
    segmentTree[i] = createSegmentTree(array, segmentTree, 2*i + 1, lo, mid) + createSegmentTree(array, segmentTree, 2*i + 2, mid + 1, hi)
    return(segmentTree[i])

def gs(segmentTree, i, lo, hi, ql, qh):
    iterations[0] += 1
    if (ql <= lo and qh >= hi):
        return(segmentTree[i])
    elif (hi < ql or lo > qh):
        return(0)

    mid = getMid(lo, hi)
    return(gs(segmentTree, 2*i + 1, lo, mid, ql, qh) + uv(segmentTree, 2*i + 2, mid + 1, hi, ql, qh))

def getSum(segmentTree, size, lo, hi):
    if (lo < 0 or hi > size - 1 or lo > hi):
        return(-1)
    return(gs(segmentTree, 0, 0, size - 1, lo, hi))

def uv(segmentTree, diff, lo, hi, pos, i):
    iterations[0] += 1
    if (hi < pos or lo > pos):
        return

    segmentTree[i] += diff
    if (lo != hi):
        mid = getMid(lo, hi)
        uv(segmentTree, diff, lo, mid, pos, 2*i + 1)
        uv(segmentTree, diff, mid + 1, hi, pos, 2*i + 2)

def updateValue(segmentTree, array, size, value, pos):
    if (pos < 0 or pos > size - 1):
        return
    diff = value - array[pos]
    array[pos] = value
    uv(segmentTree, diff, 0, size - 1, pos, 0)

def naiveSum(array, lo, hi):
    som = 0
    for i in range(lo, hi + 1):
        iterations[0] += 1
        som += array[i]
    return(som)

file = open("in", "r")
lines = file.readlines()

size = 10#int(lines[0])
array = []
for i in range(1):
    array += list(map(int, lines[1].split()))

array = array[:10]

startTime = time.time()
segmentTree = [0] * (2 * 2**(int(log2(size)) + 1) - 1)
iterations = [0]
createSegmentTree(array, segmentTree, 0, 0, size - 1)
print("SegmentTree created in %lf seconds (iterations: %d)" % (time.time() - startTime, iterations[0]))

while (True):
    line = list(input().split())
    k = line[0]
    if (k == 'Q'):
        begin, end = map(int, line[1:])
        startTime = time.time()
        iterations = [0]
        print("SegmentTree: range (%d, %d)" % (begin, end), "=", getSum(segmentTree, size, begin, end),
        "iterations:", iterations[0], "in %Lf seconds" % (time.time() - startTime))
        startTime = time.time()
        iterations = [0]
        print("Naive      : range (%d, %d)" % (begin, end), "=", naiveSum(array, begin, end),
        "iterations:", iterations[0], "in %Lf seconds" % (time.time() - startTime))
    else:
        value, pos = map(int, line[1:])
        startTime = time.time()
        iterations = [0]
        print("Update     : %d on position %d" % (value, pos), "=", updateValue(segmentTree, array, size, value, pos),
        "iterations:", iterations[0], "in %Lf seconds" % (time.time() - startTime))
# print("array", array)
# print("segmentTree", segmentTree)
# for i in range(size):
#     for j in range(i, size):
