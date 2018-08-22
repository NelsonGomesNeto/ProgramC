import os
from random import randint, shuffle
os.system("gcc ./../stringCompare.c -o ./../test")

testCases = int(input())
for t in range(1, testCases + 1):
    f = open("%d.in" % t, "w")
    stringA = ""
    sizeA = randint(1, 1e6)
    for i in range(sizeA):
        stringA += chr(randint(ord('a'), ord('z')))
    sizeB = randint(1, 1e6)
    stringB = ""
    for i in range(sizeB):
        stringB += chr(randint(ord('a'), ord('z')))
    if (randint(0, 3) == 0):
        l = list(stringA)
        shuffle(l)
        stringB = ""
        for s in stringA:
            stringB += s
    print(stringA, stringB, sep='\n', file=f)
    f.close()
    os.system("./../test < %d.in > %d.out" % (t, t))
