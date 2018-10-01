import os
from random import randint, shuffle

os.system("g++ ./../InversionCount.cpp -o ./../test")
numberOfTestCases = int(input())
for i in range(1, numberOfTestCases + 1):
    f = open("%d.in" % (i), "w")
    t = randint(1, 5)
    print(t, "\n", sep='', file=f)
    for j in range(t):
        a, size = [], randint(1, int(200000*((i/numberOfTestCases)**2)))
        print(size, file=f)
        for m in range(size):
            a += [randint(1, 10000000)]
            print(a[m], file=f)
        print(file=f)
    f.close()
    os.system("./../test < %d.in > %d.out" % (i, i))