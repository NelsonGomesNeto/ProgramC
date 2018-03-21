import os
from random import randint
os.system("gcc ./../candySharing.c -o ./../test")

testCases = int(input())
for i in range(1, testCases + 1):
    f = open("%d.in" % i, "w")
    a = randint(0, 1000)
    b = randint(a, a + 1000)
    print(a, b, file=f)
    f.close()
    os.system("time ./../test < ./%d.in > ./%d.out" % (i, i))