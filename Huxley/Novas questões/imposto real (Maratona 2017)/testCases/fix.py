import os

for i in range(1, 34):
    os.rename("./input/I_%d" % i, "./input/%d.in" % i)
    os.rename("./output/I_%d" % i, "./output/%d.out" % i)
