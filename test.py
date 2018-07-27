prod = 1
while True:
	try:
		n = int(input())
		prod *= n
	except EOFError:
		break
print(prod)
