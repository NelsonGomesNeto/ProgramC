import os
from random import randint

def genChar():
  newChar = randint(33, 126)
  while (chr(newChar) == '*'):
    newChar = randint(33, 126)
  return(newChar)

testCases = int(input())
for i in range(1, testCases + 1):
  f = open("%d.in" % i, "w")
  size = randint(1, 1000)
  string = ""
  while (size):
    newChar = genChar()
    string += chr(newChar)
    size -= 1
  print(string, end='', file=f)
  f.close()
  os.system("python3 ./../../../Huxley/1038ADifferentTree.py < %d.in > %d.out" % (i, i))
