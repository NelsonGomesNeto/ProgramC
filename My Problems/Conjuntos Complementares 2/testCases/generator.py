import os
from random import random

testCases = int(input())
for i in range(1, testCases + 1):
    fo = open("%d.in" % (i), "w")
    size = ((int(random() * 10000) % 1000) + 1)
    s = []
    for j in range(size):
        s += [(int(random() * 10000) % 300) + 1]
    print(*s, file=fo)
    fo.close()
    print("Case %d has %d numbers, and sum: %d" % (i, size, sum(s)))
    os.system("time python3 ./../conjuntosComplementares.py < %d.in > %d.out" % (i, i))
