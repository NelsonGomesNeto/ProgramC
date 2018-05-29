all = []
while (True):
    try:
        all += [list(map(str, input().split()))]
        input()
    except:
        break
names = []
for n in all:
    names += [n[2:]]
names.sort()
for n in names:
    print(*n)
