def base3(num):
	if (num == 0): return([0])
	return(base3(num // 3) + [num % 3])

base = open("3 base", "r")
lines = base.readlines()
base.close()
edges = [[4, 5], [5, 3], [7, 5], [5, 6]]
for i in range(81):
	f = open("3 %d" % i, "w")
	for line in lines:
		print(line, end='', file=f)
	print("\n", file=f)
	ternary = base3(i)
	while (len(ternary) < 4):
		ternary += [0]
	if (len(ternary) > 4): ternary.pop(0)
	print(i, ternary)
	for j, edge in enumerate(edges):
		if (ternary[j] == 0): print(*reversed(edge), 1200, file=f)
		elif (ternary[j] == 1): print(*edge, 1200, file=f)
		else:
			print(*edge, 600, file=f)
			print(*reversed(edge), 600, file=f)
	f.close()
