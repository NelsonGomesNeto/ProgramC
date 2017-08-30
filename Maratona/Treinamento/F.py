def abi(a):
    if (a < 0):
        return(-a)
    return(a)

people, vaults, space, time = map(int, input().split())
p = list(map(int, input().split()))
v = list(map(int, input().split()))
p.sort()
v.sort()

t, i = 0, 0
for j in v:
    k = space
    while (k > 0 and i < people):
        #print(abi(p[i] - j))
        if (abi(p[i] - j) <= time):
            k -= 1
            t += 1
        i += 1

print(t)
