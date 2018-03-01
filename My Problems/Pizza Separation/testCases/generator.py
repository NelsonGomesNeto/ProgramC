import os
from math import log
from random import random

os.system("gcc ./../pizzaSeparation.c -o ./../test")

testCases = int(input())
for i in range(1, testCases + 1):
    fo = open("%d.in" % (i), "w")
    pizza = []
    totalAngle, slices = 0, 0
    while (totalAngle < 360):
        if (i < 25):
            angle = (int(random() * 10000) % int(360 / (8*i))) + 1
        else:
            angle = (int(random() * 10000) % int(360))
        if (totalAngle + angle >= 360):
            angle = 360 - totalAngle
        pizza += [angle]
        totalAngle += angle
        slices += 1
    print(slices, file=fo)
    print(*pizza, file=fo)
    fo.close()
    print("Case %d has %d slices" % (i, slices))
    os.system("./../test < ./%d.in > ./%d.out" % (i, i))
    os.system("cat ./%d.out" % i)