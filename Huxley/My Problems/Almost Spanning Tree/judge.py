import os

for i in range(1, 101):
    os.system("python3 almostSpanningTree.py < ./testCases/%d.in > ./testCases/%d.out" % (i, i))