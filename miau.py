def countLost(blocks, visited):
	now, F, R = 0, 0, 0
	for b in blocks:
		v = blocks[b]
		if (not (v == 'F' or v == 'R') and b not in visited): now += 1
		if (v == 'F'): F += 1
		if (v == 'R'): R += 1
	return(now, F, R)

def go(blocks, now, path, visited):
	path += [now]
	if (now == 'L' or now == 'B' or now == 'F' or now == 'R'): return
	visited.add(now)
	go(blocks, blocks[now], path, visited)

size = 80
blocks = {}
for i in range(80):
	name = input()
	next = input()
	blocks[name] = next
print(blocks, len(blocks))

size = 7
files = {}
for i in range(size):
	name, start = input().split()
	files[name] = start

visited = set()
for f in files:
	path = []
	go(blocks, files[f], path, visited)
	print("%s:" % f, ' -> '.join(path), "(íntegro)" if path[len(path) - 1] == 'L' else "(defeituoso)")

print("perdidos: %d (free: %d, reserved: %d, used: %d)" % (*countLost(blocks, visited), len(visited)))