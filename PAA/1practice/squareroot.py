from math import sqrt

def sqroot(n):
    return(dc(0, n, n))

def dc(lo, hi, target):
    mid = (lo + hi) / 2
    if (round(mid * mid, 5) == target):
        return(round(mid, 5))
    if (mid * mid > target):
        return(dc(lo, mid - 1, target))
    return(dc(mid + 1, hi, target))

#main
n = float(input())
print(sqroot(n))