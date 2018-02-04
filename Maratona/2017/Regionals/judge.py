import os

os.system("g++ BBrincadeira.cpp -o test")
for i in range(1, 49):
    os.system("./test < ./B/input/B_%d > out" % (i))
    os.system("cmp out ./B/output/B_%d" % (i))