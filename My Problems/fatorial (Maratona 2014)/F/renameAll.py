import os

for i in range(1, 31):
    os.rename("F_%d.in" % i, "%d.in" % i)
    os.rename("F_%d.sol" % i, "%d.out" % i)
    #os.rename("%d.sol" % i, "%d.out" % i)