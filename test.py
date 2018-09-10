name = input()
f = open("in", "r")
lines = f.readlines()
f.close()

for line in lines:
    print(line.replace("!@#$$#@!", name), end='')