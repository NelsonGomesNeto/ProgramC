import os
import filecmp

os.system("g++ HHipercampo.cpp -o test -std=c++11")
testCases = os.listdir("./H/input/")

for i in range(1, len(testCases)):
    os.system("./test < ./H/input/H_%d > out" % (i))
    print(i, ": ", filecmp.cmp("./H/output/H_%d" % (i), "out"), sep='')
