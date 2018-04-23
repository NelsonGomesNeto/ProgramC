<<<<<<< HEAD
def a():
    x = 2

def b():
    a()
    print(x)

b()
=======
from random import randint

size = int(input())
f = open("in", "w")
print(size, file=f)

a = []
for i in range(size):
    a += [randint(1, size)]

print(*a, file=f)
f.close()
>>>>>>> 1557c37d0e52bfe89b6b29e052fea2422f70d9bb
