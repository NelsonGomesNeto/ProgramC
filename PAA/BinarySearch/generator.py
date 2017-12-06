from random import random

def ranNeg():
    if (random() < 0.5):
        return(-1)
    else:
        return(1)

fo = open("in", "w")
numbers, limit = map(int, input().split())
print(numbers, file=fo)
array = []
for i in range(numbers):
    num = ((int(random() * 1000000) % limit)) * ranNeg()
    array += [num]
print(*array)
print(*array, file=fo)
fo.close()
