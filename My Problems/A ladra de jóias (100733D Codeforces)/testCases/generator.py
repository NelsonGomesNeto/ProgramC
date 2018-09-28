from random import randint
import os
os.system("gcc ./../shi.c -o ./../test -O2")

testCases = int(input())
for t in range(1, testCases + 1):
    print(t)
    f = open("%d.in" % t, "w")
    size = randint(int((t - 1) / testCases * 1e6), int((t / testCases) * 1e6))
    print(size, file=f)
    a = []
    for i in range(size):
        a += [randint(1, 1e3)]
    print(*a, file=f)
    f.close()

    os.system("./../test < %d.in > %d.out" % (t, t))
