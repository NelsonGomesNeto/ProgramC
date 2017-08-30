def calculate(d, x):
    s = 0
    for i in d:
        s += delta(i[0]*x - i[1])
    return(s)

def delta(x):
    if (x < 0):
        return(0)
    return(1)

size = int(input())
d = [0] * size
for i in range(size):
    s, a = map(int, input().split())
    d[i] = [s, a]
#print(d)

q = int(input())
q = input().split()
for x in q:
    print(calculate(d, int(x)))
