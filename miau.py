lines = []
while (True):
	try:
		lines += [input()]
	except:
		break
lines.sort()
for line in lines:
	print(line)

