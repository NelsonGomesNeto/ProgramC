from random import randint, random
import os
DEBUG = 0

def puzzle(a, seed):
    done = [0] * len(a)
    start, at, toGo = 0, 0, 0
    while (sum(done) < len(a)):
        rr = random()
        if (DEBUG): print(a, done, rr)
        done[at] = 1
        if (rr > seed and sum(done) < len(a) - 1): # Will continue cycle
            toGo = randint(0, len(a) - 1)
            while (done[toGo] and sum(done) < len(a)): toGo = randint(0, len(a) - 1)
            a[at] = toGo
            done[at] = 1
            done[toGo] = 1
            at = toGo
        else:
            a[at] = start
            done[start] = 1
            done[at] = 1
            while (done[start] and sum(done) < len(a)): start = randint(0, len(a) - 1)
            at = start
    return(a)

def go(a, i, origin, visited):
    print(i, end=' -> ')
    visited[i] = 1
    if (a[i] == origin):
        return
    else:
        go(a, a[i], origin, visited)

def findCycles(a):
    visited = [0] * len(a)
    for i in range(len(a)):
        if (not visited[i]):
            go(a, i, i, visited)
            print("|")

# a = puzzle(list([0] * 10), random())
# findCycles(a)

os.system("gcc ./../biggestBurrow.c -o ./../test")
testCases = int(input())
for i in range(1, testCases + 1):
    f = open("%d.in" % (i), "w")
    size = randint(1, 10000)
    print(size, file=f)
    a = list(range(0, size))
    seed = random()
    a = puzzle(a, seed)
    print(*a, file=f)
    f.close()
    os.system("./../test < %d.in > %d.out" % (i, i))
