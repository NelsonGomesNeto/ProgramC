def binsearch(a, lo, hi, target):
	mid = (lo + hi) // 2
	if (lo > hi):
		if (a[mid] == target):
			return(mid)
		return(-1)
	if (a[mid] > target):
		return(binsearch(a, lo, mid - 1, target))
	return(binsearch(a, mid + 1, hi, target))

y, x = map(int, input().split())
array = []
for i in range(y):
	array += list(map(int, input().split()))

queries = int(input())
queries = list(map(int, input().split()))
#dp = [-2] * len(queries)
for i in queries:
	#if (i >= 0 and i < len(queries)):
		#if (dp[i] == -2):
			#dp[i] = binsearch(array, 0, (y * x) - 1, i)
		#position = dp[i]
	#else:
	position = binsearch(array, 0, (y * x) - 1, i)
	if (position == -1):
		print("NO")
	else:
		i = (position % x) + 1
		j = (position // x) + 1
		print("YES WITH", j, "AND", i)
