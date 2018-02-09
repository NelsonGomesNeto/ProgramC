DEBUG = 0

def func (a):
    if (a == 0): return(1)
    return(a)

def bottomUp():
    c = [0, 1]
    for i in range(2, 151):
        if (DEBUG): print(i)
        c += [0]
        for j in range(1, 2*i, 2):
            if (DEBUG): print(j // 2, (2*i - j) // 2, c[j // 2], c[(2*i - j) // 2])
            c[i] += func(c[j // 2]) * func(c[(2*i - j) // 2])
    return(c)

connections = bottomUp()
while (True):
    n = int(input())
    if (n == -1): break
    print(connections[n])