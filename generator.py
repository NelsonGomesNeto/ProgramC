from random import randint
import os, time
from filecmp import cmp

while (True):

  size = int(input())
  a = []
  for i in range(size):
    a += [randint(-1000000, 1000000)]

  testCase = open("in", "w")
  print(size, file=testCase)
  print(*a, file=testCase)
  testCase.close()

  correct = open("out", "w")
  print("Before:", *a, file=correct)
  a.sort()
  print("After:", *a, file=correct)
  correct.close()

  startTime = time.time()
  os.system("./test < in > tryOut")
  endTime = time.time()

  print("Size of test:", size)
  print("Verdict:", cmp("out", "tryOut"))
  print("Sorting time: %.5lfs" % (endTime - startTime))
  print()

