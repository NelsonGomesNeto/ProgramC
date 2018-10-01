import os
from random import randint

os.system("gcc ./../factsum.c -o ./../test")
testCases = int(input())
for i in range(1, testCases + 1):
    f = open("%d.in" % i, "w")
    print(randint(0, 100000), randint(1, 100), file=f)
    f.close()
    os.system("./../test < ./%d.in > ./%d.out" % (i, i))
