from random import random, randint, shuffle

n = 100
a = []
a += list(range(1, n + 1))
a += list(range(1, n + 1))
shuffle(a)
print(n)
print(*a)