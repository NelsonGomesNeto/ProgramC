import os

os.system("g++ ./../keyboard.cpp -o ./../test")

testCases = int(input())
for i in range(1, testCases + 1):
  fi = open("%d.in" % i, "w")
  fo = open("%d.out" % i, "w")
  for j in range(7):
    input()

  ii = []
  for j in range(2):
    ii += [input()]
  input()
  oo = input()

  for j in range(4):
    input()

  for j in ii:
    print(j, file=fi)
  print(oo, file=fo)

  fi.close()
  fo.close()
