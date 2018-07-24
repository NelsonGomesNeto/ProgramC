import os
import filecmp
from random import randint

size, done = 1000000, 0
while (True):
    a = []
    for i in range(size):
        a += [randint(0, 1000000)]
    f = open("in", "w")
    print(*a, file=f)
    f.close()

    a.sort()
    f = open("ans", "w")
    print(len(a), "~~", *a, file=f)
    f.close()

    os.system("./test < in > out")

    if (not filecmp.cmp("out", "ans")):
        print(len(a), "~~", *a)
        break
    print(done)
    done += 1
