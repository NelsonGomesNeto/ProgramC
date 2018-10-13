
lines = []
while (True):
    try:
        lines += [input()]
    except:
        break

print(lines)

for line in lines:
    line = line.split('=')
    print(line[1].strip(' '), "=", line[0].strip(' '))