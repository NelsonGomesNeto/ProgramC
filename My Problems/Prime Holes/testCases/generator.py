import os
from random import randint
os.system("gcc ./../primeHoles.c -o ./../test -lm")

testCases = int(input())
for i in range(1, testCases + 1):
    f = open("%d.in" % i, "w")
    n = randint(0, 9223372036854775807)
    print(n, file=f)
    f.close()
    os.system("./../test < ./%d.in > ./%d.out" % (i, i))