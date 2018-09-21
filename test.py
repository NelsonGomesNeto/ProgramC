import os, sys

p = sys.argv[1]
allSub = set()
for path, subdir, files in os.walk(p):
    for s in subdir:
        allSub.add(s)
print(allSub)
