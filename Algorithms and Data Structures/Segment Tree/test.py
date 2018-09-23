import os
from random import randint, random
from filecmp import cmp
os.system("g++ naive.cpp -o test")
os.system("g++ segmentTreeLazyPropagation.cpp -o test2")

f = open("in", "w")
arraySize = int(input())
array = []
for i in range(arraySize): array += [randint(-1000, 1000)]
print(arraySize, file=f)
print(*array, file=f)

queries = int(input())
for i in range(queries):
    kind = randint(0, 2)
    lo = randint(0, arraySize - 1)
    hi = randint(lo, arraySize - 1)
    if (kind == 0):
        print("Q", lo, hi, file=f)
    elif (kind == 1):
        print("S", lo, hi, randint(-1000, 1000), file=f)
    elif (kind == 2):
        print("U", lo, hi, randint(-1000, 1000), file=f)
f.close()

os.system("./test < in > out")
os.system("./test2 < in > out2")
print("Verdict:", cmp("out", "out2"))
