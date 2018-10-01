import os
from random import randint
os.system("gcc ./../DificuldadesEmBhaskara.c -o ./../test -lm")

testCases = int(input())
for i in range(1, testCases + 1):
    f = open("%d.in" % i, "w")
    t = randint(1, 100)
    print(t, file=f)
    for j in range(t):
        a, b, c = 0, 0, 0
        while (a == 0 or b == 0):
            a, b, c = randint(-10, 10), randint(-10, 10), randint(-10, 10)
        print("%dx^2 + %dx + %d" % (a, b, c), file=f)
    f.close()
    os.system("./../test < %d.in > %d.out" % (i, i))