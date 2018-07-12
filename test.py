lines = open("in", "r").readlines()
for line in lines:
  e = line.split()
  print(e[0], "=", e[1])
