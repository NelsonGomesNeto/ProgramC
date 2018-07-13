def exp(x, y):
  aux = 1
  while (y):
    if (y & 1): aux *= x
    x *= x
    y //= 2
  return(aux)

x, y = map(int, input().split())
print(x**y, exp(x, y))
