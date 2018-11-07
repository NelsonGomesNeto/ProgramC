def expf(v,e):
	if e == 1:
		return v
	ans = expf(v,e//2)
	ans = ans*ans
	if e%2 == 0:
		return ans
	return ans*v
	pass

def search(v,n):
	if v == 0 or v == 1:
		return v
	else :
		begin = 0
		end = max(v,1.0)
		mid = 0
		while end-begin > 0.000001:
			mid = (begin+end)/2
			if expf(mid,n) > v:
				end = mid
			else :
				begin = mid
		return mid
	pass

# Q = int(input())
while (True):
	try:
		x,n = input().split()
		x = float(x)
		n = int(n)
		print( '{:.4f}'.format(search(x,n)) )
	except:
		break
