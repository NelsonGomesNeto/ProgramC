from random import random, randint, shuffle
import filecmp, os

while (1):
  n, b = randint(2, 10), randint(1, 100)
  a = []
  for i in range(n):
    a += [randint(1, 100)]

  f = open("auxIn", "w")
  print(n, b, file=f)
  print(*a, file=f)
  f.close()
  print(*a)
  os.system("./test < auxIn > auxOut")
  os.system("./bug < auxIn > tryOut")
  if (not filecmp.cmp("auxOut", "tryOut")):
    break