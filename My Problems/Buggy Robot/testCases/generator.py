import os
from random import random

movements = ['R', 'L', 'U', 'D']

os.system("gcc ./../buggyRobot.c -o ./../test")

testCases = int(input())
for i in range(1, testCases + 1):
    fo = open("%d.in" % (i), "w")
    commands = (int(random() * 10000) % 100) + 1
    print(commands, file=fo)
    command = ""
    for j in range(commands):
        command += movements[int(random() * 10000) % 4]
    print(command, file=fo)
    fo.close()
    print("Case %d has %d commands" % (i, commands))
    os.system("./../test < %d.in > %d.out" % (i, i))