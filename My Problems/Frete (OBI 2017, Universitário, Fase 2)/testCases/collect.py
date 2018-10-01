import os

at = 1
quantity = [11, 8, 8, 8]
for i in range(1, 4 + 1):
    for j in range(1, quantity[i - 1] + 1):
        os.system("mv ./%d/%d.in ./%d.in" % (i, j, at))
        os.system("mv ./%d/%d.sol ./%d.out" % (i, j, at))
        at += 1