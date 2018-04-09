import os
from random import randint, shuffle
os.system("g++ ./../changes.cpp -o ./../test")

testCases = int(input())
for i in range(1, testCases + 1):
    f = open("%d.in" % i, "w")
    t = randint(1, 100)
    print(t, file=f)
    print(t)
    for j in range(t):
        pack = [randint(1, 9), randint(9, 99), randint(99, 999), randint(999, 9999)]
        shuffle(pack)
        print(*pack, randint(999, 9999999), file=f)
        #print(*pack)
    f.close()
    #os.system("cat ./%d.out" % i)
    os.system("./../test < ./%d.in > ./%d.out" % (i, i))
