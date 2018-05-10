from random import randint, random
import os

def puzzle(a, seed):
    done = [0] * len(a)
    start, at = 0, 0
    while (sum(done) < len(a)):
        done[at] = 1
        toGo = 0
        print(toGo)
        while (done[toGo]):
            toGo = randint(0, len(a) - 1)
        if (random() > seed):
            a[at] = toGo
            at = toGo
        else:
            a[start] = toGo
            while (done[toGo]):
                toGo = randint(0, len(a) - 1)
    return(a)

os.system("gcc ./../biggestBurrow.c -o ./../test")
testCases = int(input())
for i in range(1, testCases + 1):
    f = open("%d.in" % (i), "w")
    size = randint(1, 10000)
    print(size, file=f)
    a = list(range(0, size))
    seed = random()
    puzzle(a, seed)
    print(*a, file=f)
    f.close()
    os.system("./../test < %d.in > %d.out" % (i, i))
