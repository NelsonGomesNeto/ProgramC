import os
from random import randint, shuffle
os.system("gcc ./../links.c -o ./../test -lm")

testCases = int(input())
for i in range(1, testCases + 1):
    f = open("%d.in" % i, "w")
    quantity = randint(1, 10)
    print(quantity, file=f)
    for j in range(quantity):
        bugChar = randint(0, 10)
        sizeOfLink = randint(bugChar, bugChar + 16)
        link = []
        for k in range(bugChar):
            link += ['I']
        for k in range(sizeOfLink - bugChar):
            newChar = chr(randint(ord('A'), ord('z')))
            while (newChar == 'I' or newChar == 'l'):
                newChar = chr(randint(ord('A'), ord('z')))
            link += [newChar]
        shuffle(link)
        strLink = ""
        for c in link:
            strLink += c
        print(strLink, file=f)
    f.close()
    os.system("./../test < ./%d.in > ./%d.out" % (i, i))
