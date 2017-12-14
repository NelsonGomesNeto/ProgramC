from random import random

n, m = map(int, input().split())
print(n, m)
a, b = [], []
for i in range(n):
    a += [int(random() * 100)]
print(*a)
for i in range(m):
    b += [int(random() * 100)]
print(*b)