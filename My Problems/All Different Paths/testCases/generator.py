from random import randint
import os, time
os.system("g++ ./../allDifferentPaths.cpp -o ./../test -std=c++17")

testCases = int(input())
maxTime = 0
for t in range(1, testCases + 1):
    f = open("%d.in" % t, "w")

    n = randint(2, 100)
    m = randint(n, 1000)
    print(n, m, file=f)
    for i in range(m):
        u, v = randint(0, n - 1), randint(0, n - 1)
        while (u == v): u, v = randint(0, n - 1), randint(0, n - 1)
        print(u, v, file=f)

    f.close()
    startTime = time.time()
    os.system("./../test < %d.in > %d.out" % (t, t))
    maxTime = max(maxTime, time.time() - startTime)
    os.system("cat %d.out" % t)
print(maxTime)