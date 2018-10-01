from random import randint
import os, time
os.system("gcc ./../favoritePlanets.c -o ./../test")

testCases = int(input())
for t in range(1, testCases + 1):
    f = open("%d.in" % t, "w")
    size = randint(1, 1e3)
    visited = [False] * size
    nex = [0] * size
    for i in range(size):
        at = i
        while (not visited[at]):
            visited[at] = True
            prev, at = at, randint(0, size - 1)
            while (visited[at] and at != i): at = randint(0, size - 1)
            nex[prev] = at
    print(size, file=f)
    print(*nex, file=f)
    value = []
    for i in range(size):
        value += [randint(-1000, 1000)]
    print(*value, file=f)
    f.close()
    startTime = time.time()
    os.system("./../test < %d.in > %d.out" % (t, t))
    print(t, time.time() - startTime)
