import os
from random import randint
os.system("g++ ./../drawADiamond.cpp -o ./../test")

testCases = int(input())
s = set()
for i in range(1, testCases + 1):
    f = open("%d.in" % i, "w")
    radious = randint(1, 50)
    while (radious in s):
        radious = randint(1, 50)
    s.add(radious)
    print(radious, file=f)
    f.close()
    os.system("./../test < ./%d.in > ./%d.out" % (i, i))