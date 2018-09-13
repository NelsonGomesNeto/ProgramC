import os
from random import randint, random
os.system("gcc ./../mat.c -o ./../test")

testCases = int(input())
for t in range(1, testCases + 1):
	f = open("%d.in" % t, "w")
	n, m = randint(1, 100), randint(1, 100)
	y, x = randint(0, n - 1), randint(0, m - 1)
	dy, dx = randint(-100, 100), randint(-100, 100)
	print(n, m, y, x, dy, dx, file=f)
	# print(t, "", n, m, y, x, dy, dx)
	f.close()
	os.system("./../test < %d.in > %d.out" % (t, t))