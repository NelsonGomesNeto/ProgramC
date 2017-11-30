import os

for i in range(3, 32):
    os.system("./../../../../UVA/test < ./%d.in > ./%d.out" % (i, i))