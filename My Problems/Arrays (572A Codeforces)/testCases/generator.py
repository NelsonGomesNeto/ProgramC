from random import randint
import os
os.system("g++ ./../arrays.cpp -o ./../test")

def genArray(size):
    array = []
    for i in range(size):
        array += [randint(1, 1000)]
    return(array)

testCases = int(input())
for i in range(1, testCases + 1):
    f = open("%d.in" % i, "w")
    na, nb = randint(1, 1000), randint(1, 1000)
    k, m = randint(1, na), randint(1, nb)
    print(na, nb, file=f)
    print(k, m, file=f)
    a = genArray(na)
    b = genArray(nb)
    print(*a, file=f)
    print(*b, file=f)
    f.close()
    os.system("./../test < %d.in > %d.out" % (i, i))
    os.system("cat %d.out" % i)