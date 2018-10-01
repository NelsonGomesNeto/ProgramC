import os
from random import randint
os.system("g++ ./../344AMagnets.cpp -o ./../test")

testCases = int(input())
for t in range(1, testCases + 1):
	f = open("%d.in" % t, "w")
	n = randint(1, 100000)
	print(n, file=f)
	for i in range(n):
		k = "10" if (randint(0, 1)) else "01"
		print(k, file=f)
	f.close()
	os.system("./../test < %d.in > %d.out" % (t, t))