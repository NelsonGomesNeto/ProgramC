import os
from random import randint

def l(x, v, a, g):
    if (g <= 0):
        return(x)
    return(l(x + v, v + a, a, g - v))

testCases = int(input())
for i in range(1, testCases + 1):
    f = open("%d.in" % i, "w")
    a, g = randint(1, 100), randint(0, 100000)
    p = randint(max(l(0, 0, a, g) - 100, 0), l(0, 0, a, g) + 100)
    print(a, g, p, file=f)
    f.close()
    os.system("./../test < %d.in > %d.out" % (i, i))