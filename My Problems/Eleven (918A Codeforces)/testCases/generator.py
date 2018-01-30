import os
from random import shuffle

os.system("gcc ./../Eleven.c -o ./../test")
a = list(range(1, 1001))
shuffle(a)
for i in range(50):
    f = open("%d.in" % (i + 1), "w")
    print(a[i], file=f)
    f.close()
    os.system("./../test < %d.in > %d.out" % (i + 1, i + 1))