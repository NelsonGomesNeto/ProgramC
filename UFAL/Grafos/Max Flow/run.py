import os

for i in range(81):
	print(i)
	os.system("python3 maxFlow.py < \"3 %d\"" % i)
