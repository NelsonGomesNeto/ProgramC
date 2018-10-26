
lines = []
while (True):
    try:
        line = input()
        if (line == ""): continue
        lines += [line]
    except:
        break

grammar = {}
for line in lines:
    left, right = line.split("=")
    left = left.strip(' ')
    grammar[left] = [r.strip(' ') for r in right.split('|')]

for n in grammar:
    for i in grammar[n]:
        print(n, "->", i)