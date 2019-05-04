def binarySearch(lo, hi):
	if (lo >= hi):
		return(lo)
	mid = (lo + hi) >> 1
	print(mid)
	dir = input()
	if (dir == '='): return(mid)
	if (dir == '<'): return(binarySearch(lo, mid))
	if (dir == '>'): return(binarySearch(mid, hi))

print("The number is:", binarySearch(0, 100))
