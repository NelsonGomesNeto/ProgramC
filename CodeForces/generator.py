from random import random, randint

n, m = 200000, 2
a = []
now = 199999
for i in range(n):
  # a += [now]
  # if (i > 0 and not (i & 1)):
  #   now -= 1
  # a += [randint(0, 10**9)]
  a += [1]
f = open("gin", "w")
print(n, m, file=f)
print(*a, file=f)
f.close()