from random import randint
import os

f = open("judgeIn", "w")
for i in range(10):
    size = 1000000
    a = [randint(-1000000, 1000000) for j in range(size)]
    print("input", file=f)
    print(size, file=f)
    print(*a, file=f)
    print("output", file=f)
    a.sort()
    print(*a, file=f)
print(file=f)
f.close()