<<<<<<< HEAD
import sys
print(sys.argv)
print("sum =", int(sys.argv[1]) + int(sys.argv[2]))
=======
dp = ["y", "x", "ddp"]
l = []
while (True):
    try:
        l += [list(map(float, input().split(',')))]
        aux = l[len(l) - 1][0]
        l[len(l) - 1][0] = l[len(l) - 1][1]
        l[len(l) - 1][1] = aux
    except EOFError as e:
        break
l.sort()
for i in range(3):
    print(dp[i], "= c(", end='')
    for j in range(len(l)):
        print(l[j][i], end='')
        if (j != len(l) - 1): print(", ", end='')
    print(")")
>>>>>>> 297e44d5ff104d3746c3a7448fc6c1d7dec2eb77
