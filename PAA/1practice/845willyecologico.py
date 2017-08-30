def cut(t, height):
	cutted = 0
	for i in t:
		if (i > height):
			cutted += i - height

	return(cutted)

def bestHeight(t, start, end, wanted):
	mid = int((start + end) / 2)
	#print(t[mid], start, end, mid, cutted)
	if (start >= end - 1):
		return(t[mid])

	if (cut(t, t[mid]) < wanted):
		return(bestHeight(t, start, mid, wanted))
	else:
		return(bestHeight(t, mid, end, wanted))

trees, wanted = map(int, input().split())
t = list(map(int, input().split()))
t.sort()
#print(t)
print(bestHeight(t, 0, trees - 1, wanted))
