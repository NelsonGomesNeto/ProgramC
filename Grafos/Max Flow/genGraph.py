base = open("3 base", "r")
lines = base.readlines()
base.close()
edges = [[4, 5], [5, 3], [7, 5], [5, 6]]
for i in range(16):
	f = open("3 %d" % i, "w")
	for line in lines:
		print(line, end='', file=f)
	print("\n", file=f)
	for j, edge in enumerate(edges):
		if ((1 << j) & i): print(*reversed(edge), 1200, file=f)
		else: print(*edge, 1200, file=f)
	f.close()