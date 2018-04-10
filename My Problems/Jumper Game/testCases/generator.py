from random import randint
import os
os.system("gcc ./../jumperGame.c -o ./../test")

testCases = int(input())
for i in range(1, testCases + 1):
    f = open("%d.in" % i, "w")
    n, jumps = randint(1, 1000), randint(1, 1000)
    game = []
    for j in range(n):
        game += [randint(1, 1000)]
    print(n, jumps, file=f)
    print(*game, file=f)
    f.close()
    os.system("./../test < %d.in > %d.out" % (i, i))