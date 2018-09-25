import os, sys

p = sys.argv[1]
print(p)
allSub, totalSize = [], 0
found = 1
for path, subdir, files in os.walk(p):
    for s in subdir:
        indir = os.listdir(path + "\\" + s)
        for i in indir:
            if (i.find("ABERROMETRIA") != -1):
                prevPath = path + "\\" + s + "\\" + i
                targetPath = "I:\HOB\Aberrometrias\\" + "%d - [%s].pdf" % (found, s)
                os.system("copy \"%s\" \"%s\" > NUL" % (prevPath, targetPath))
                print(found)
                found += 1
                allSub += [prevPath]
                totalSize += os.stat(prevPath).st_size
# print(allSub)
print(len(allSub))
print(totalSize / 1024 / 1024)