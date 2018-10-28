from turtle import *
from math import acos
import time
pi = acos(-1)
speed(0)
delay(0)
L = 7

r = 21

for r in range(14, 22):
    o, i = r, r - L
    so = 2 * pi * o
    si = 2 * pi * i
    speedo = 2 * pi * 3 * 3
    speedi = 2 * pi * 3 * 2
    print(so, o, si, i, so / speedo, si / speedi)

    for j in range(360):
        forward(so / speedo)
        right(1)

    penup()
    right(90)
    forward(L)
    left(90)
    pendown()

    for j in range(360):
        forward(si / speedi)
        right(1)

    reset()
