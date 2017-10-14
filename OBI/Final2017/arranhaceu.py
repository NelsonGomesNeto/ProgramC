from math import log2
import sys
sys.setrecursionlimit(2**20)
DEBUG = 0

def createSegmentTree(segmentTree, array, i, lo, hi):
    if (lo == hi):
        segmentTree[i] = array[lo]
        return(array[lo])
    elif (lo > hi):
        return(0)

    mid = (lo + hi) // 2
    segmentTree[i] = createSegmentTree(segmentTree, array, 2*i + 1, lo, mid) + createSegmentTree(segmentTree, array, 2*i + 2, mid + 1, hi)
    return(segmentTree[i])

def gs(segmentTree, i, lo, hi, qlo, qhi):
    if (lo >= qlo and hi <= qhi):
        return(segmentTree[i])
    elif (lo > qhi or hi < qlo):
        return(0)

    mid = (lo + hi) // 2
    return(gs(segmentTree, 2*i + 1, lo, mid, qlo, qhi) + gs(segmentTree, 2*i + 2, mid + 1, hi, qlo, qhi))

def getSum(segmentTree, size, lo, hi):
    if (lo < 0 or hi > size - 1 or lo > hi):
        return(-1)
    return(gs(segmentTree, 0, 0, size - 1, lo, hi))

def uv(segmentTree, diff, i, lo, hi, pos):
    if (lo > pos or hi < pos):
        return

    segmentTree[i] += diff
    if (lo != hi):
        mid = (lo + hi) // 2
        uv(segmentTree, diff, 2*i + 1, lo, mid, pos)
        uv(segmentTree, diff, 2*i + 2, mid + 1, hi, pos)

def updateValue(segmentTree, array, size, value, pos):
    if (pos < 0 or pos > size - 1):
        return
    diff = value - array[pos]
    array[pos] = value
    uv(segmentTree, diff, 0, 0, size - 1, pos)

floors, events = map(int, input().split())
building = list(map(int, input().split()))

segmentTree = [0] * (2 * 2**(int(log2(floors)) + 1) - 1)
createSegmentTree(segmentTree, building, 0, 0, floors - 1)

if (DEBUG):
    print("segmentTree", segmentTree)

for i in range(events):
    line = list(map(int, input().split()))
    if (line[0] == 0):
        floor, people = line[1:]
        updateValue(segmentTree, building, floors, people, floor - 1)
    else:
        floor = line[1]
        print(getSum(segmentTree, floors, 0, floor - 1))