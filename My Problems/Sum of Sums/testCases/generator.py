import os
from random import randint
os.system("gcc ./../sumOfSums.c -o ./../test -lm")

testCases = int(input())
for i in range(1, testCases + 1):
    f = open("%d.in" % i, "w")
    n, m = randint(0, 500), randint(0, 500)
    print(n, m, file=f)
    f.close()
    os.system("./../test < ./%d.in > ./%d.out" % (i, i))