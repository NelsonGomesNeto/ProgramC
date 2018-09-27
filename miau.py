import sys
import resource
resource.setrlimit(resource.RLIMIT_STACK, [0x10000000, resource.RLIM_INFINITY])
sys.setrecursionlimit(2**30)

def rec(i):
	# print(i)
	if (i >= 100000): return
	rec(i + 1)

rec(0)
print("Ended")