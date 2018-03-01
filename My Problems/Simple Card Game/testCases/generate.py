import os
from random import randint

os.system("gcc ./../simpleCardGame.c -o ./../test")
testCases = int(input())
for i in range(1, testCases + 1):
    f = open("%d.in" % i, "w")
    print(randint(1, 13), randint(1, 13), randint(1, 13), file=f)
    print(randint(1, 13), randint(1, 13), randint(1, 13), file=f)
    f.close()
    os.system("./../test < %d.in > %d.out" % (i, i))
