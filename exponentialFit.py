from random import random
from random import randint
from math import exp
inf = 1<<20
dh = [0.1, 1, 10, 20]

def lol():
    if (random() >= 0.5):
        return(1)
    return(-1)

def neighbors(at, mult):
    nei = []
    for i in range(1000):
        miau = [at[0] + random() * mult * lol(), at[1] + random() * mult * lol()]
        nei += [[at[0], miau[1]]]
        nei += [[miau[0], at[1]]]
        nei += [[miau[0], miau[1]]]
    return(nei)

def discharge(node):
    dist = 0
    for i in range(len(t)):
        dist += (ddp[i] - node[0]*exp(-node[1]*t[i]))**2
    return(dist)

def charge(node):
    dist = 0
    for i in range(len(t)):
        dist += (ddp[i] - node[0]*(1-exp(-node[1]*t[i])))**2
    return(dist)

def evaluate(node, kind):
    if (kind == 1):
        return(charge(node))
    return(discharge(node))


def hillClimb(start, kind):
    curr, h = start, 0
    while (evaluate(curr, kind) > 0.0000001):
        h += 1
        h %= len(dh)
        l = neighbors(curr, min(1, evaluate(curr, kind)**dh[h]))
        nextEval = inf
        nextNode = curr
        for x in l:
            #print(x, evaluate(x))
            if (evaluate(x, kind) < nextEval):
                nextNode = x
                nextEval = evaluate(x, kind)
            #print(nextNode, nextEval)
        #if (nextEval >= evaluate(curr)):
        #    return(curr)
        print(curr[0], 1/curr[1], evaluate(curr, kind), end=' - ')
        if (nextEval < evaluate(curr, kind)):
            curr = nextNode
            print(dh[h], "changed")
        else: print()
    return(curr)

ddp, t = [], []
while (True):
    try:
        ddp += [float(input())]
        t += [float(input())]
    except EOFError as e:
        break
    except ValueError as e:
        break

print(ddp)
print(t)

win = hillClimb([1, 1], 2)
print(win, evaluate(win, 2))
#discharge = 10.038678573851678 10.093893587374863 0.14198754204797787