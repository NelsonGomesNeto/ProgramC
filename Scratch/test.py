# PROBLEM 1
#
# Modify the orbit function below to model
# one revolution of the moon around the earth,
# assuming that the orbit is circular.
#
# Use the math.cos(angle) and math.sin(angle)
# functions in order to accomplish this.

import math, numpy

moon_distance = 384e6 # m
pi = math.acos(-1)

def orbit():
    num_steps = 359
    x = numpy.zeros([num_steps + 1, 2])
    x[0][0], x[0][1] = moon_distance, 0
    for i in range(1, num_steps + 1):
        x[i][0] = moon_distance * math.cos((i / (num_steps + 1)) * 2 * pi)
        x[i][1] = moon_distance * math.sin((i / (num_steps + 1)) * 2 * pi)

    return x

x = orbit()
for j, i in enumerate(x):
    print(j, i)
