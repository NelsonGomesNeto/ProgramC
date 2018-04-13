from random import randint

size = int(input())
f = open("in", "w")
print(size, file=f)

a = []
for i in range(size):
    a += [randint(1, size)]

print(*a, file=f)
f.close()