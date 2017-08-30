def sqrt(n):
    return(dc(0, n, n))

def dc(lo, hi, target):
    mid = (lo + hi) / 2
    pot = round(mid**2, 10)
    if (pot == target):
        return(round(mid, 10))
    if (pot > target):
        return(dc(lo, mid - 1, target))
    return(dc(mid + 1, hi, target))

#main
n = float(input())
print(sqrt(n))