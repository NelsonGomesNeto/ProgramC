import os, filecmp, time

os.system("g++ K.cpp -o test -O2")
toTest = os.listdir("./input/")
longestTime = 0
failed = []
for f in toTest:
    startTime = time.time()
    os.system("./test < ./input/%s > auxOut" % f)
    longestTime = max(longestTime, time.time() - startTime)
    result = filecmp.cmp("auxOut", "./output/%s" % f)
    print(f, result)
    if (result == False):
        failed += [f]
print("Worst testcase took:", longestTime)
if (failed):
    print("Failed these testcases:", *failed)
else:
    print("Accepted")
