import os
from random import randint

os.system("g++-7 ./../AjudeSeuMadruga.cpp -o ./../test -std=c++17")

def genArray():
    c = []
    for i in range(n):
        c += [randint(1, 1e4)]
    return(c)

testCases = int(input())
for t in range(1, testCases + 1):
    f = open("%d.in" % t, "w")
    tests = randint(1, 4)
    while (tests):
        n, a = randint(1, 1e5), randint(1, 1e9)
        chances = randint(1, 1e4)
        c = genArray()
        if (chances > 500):
            while (sum(c) < a):
                c = genArray()
                a = randint(1, 1e9)
        print(n, a, file=f)
        print(*c, file=f)
        tests -= 1
    print(0, 0, file=f)
    f.close()

    os.system("time ./../test < %d.in > %d.out" % (t, t))
