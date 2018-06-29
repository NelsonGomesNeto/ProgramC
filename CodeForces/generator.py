from random import random, randint, shuffle
import filecmp, os

while (1):
  n = 10
  a = []
  now = randint(1, 10)
  for i in range(n):
    a += [now]
    now = randint(1, 10)
    # next = randint(-1, 1)
    # if (now + next > 0):
    #   now += next

  f = open("auxIn", "w")
  print(n, file=f)
  print(*a, file=f)
  f.close()
  print(*a)
  os.system("./test < auxIn > auxOut")
  os.system("./bug < auxIn > tryOut")
  if (not filecmp.cmp("auxOut", "tryOut")):
    break