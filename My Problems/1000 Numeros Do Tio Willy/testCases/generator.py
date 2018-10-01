import os
from random import randint
os.system("g++ ./../1000numerosDoTioWilly.cpp -o ./../test")

testCases = int(input())
for i in range(1, testCases + 1):
    f = open("%d.in" % i, "w")
    lol = randint(1, 50)
    while (lol):
        for j in range(1000):
            print(randint(0, 100), file=f)
        print(randint(0, 100), file=f)
        lol -= 1
    print(-1, file=f)
    f.close()
    os.system("./../test < ./%d.in > ./%d.out" % (i, i))