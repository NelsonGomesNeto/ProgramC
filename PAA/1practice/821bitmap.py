def check(m, li, hi, lj, hj):
	repeating = m[li][lj]
	for i in range(li, hi + 1):
		for j in range(lj, hj + 1):
			#print(m[i][j], sep='', end='')
			if (repeating != m[i][j]):
				return('D')
		#print()

	return(repeating)

def bitmap(m, li, hi, lj, hj, t):
	#print(li, hi, lj, hj)
	if (li > hi or lj > hj):
		return

	midi = (li + hi) // 2
	midj = (lj + hj) // 2
	checked = check(m, li, hi, lj, hj) 
	if (t[0] == 50):
		print()
		t[0] = 0
	t[0] += 1
	print(checked, sep='', end='')
	if (checked == 'D'):
		bitmap(m, li, midi, lj, midj, t)
		bitmap(m, li, midi, midj + 1, hj, t)
		bitmap(m, midi + 1, hi, lj, midj, t)
		bitmap(m, midi + 1, hi, midj + 1, hj, t)


tests = int(input())
while (tests > 0):
	y, x = map(int, input().split())
	m, t = [0] * y, [0]
	for i in range(0, y):
		m[i] = input()

	#print(m)
	bitmap(m, 0, y - 1, 0, x - 1, t)
	print()
	tests -= 1
