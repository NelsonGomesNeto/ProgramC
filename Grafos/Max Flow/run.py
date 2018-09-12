import os

for i in range(16):
	print(i)
	os.system("python maxFlow.py < \"3 %d\"" % i)