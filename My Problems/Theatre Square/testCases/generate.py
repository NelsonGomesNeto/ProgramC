import os
from random import randint, random

os.system("gcc ./../theatreSquare.c -o ./../test")
testCases = int(input())
for i in range(1, testCases + 1):
    f = open("%d.in" % i, "w")
    if (random() > 0.5):
        print(randint(1, 10000), randint(1, 10000), randint(1, 10000), file=f)
    else:
        print(randint(5000, 10000), randint(5000, 10000), randint(1, 5000), file=f)
    f.close()
    os.system("./../test < %d.in > %d.out" % (i, i))
