total = []

def fill(i, a):
  global total
  if (i == -1):
    total += [a]
    return
  for j in range(3):
    fill(i - 1, a + [j])

fill(2, [])
print(total)
