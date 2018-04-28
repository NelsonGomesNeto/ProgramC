import sys
from math import tan, acos
sys.setrecursionlimit(2**19)

def deg2rad(coef):
    return(coef * acos(-1) / 180)

def eva(x, y, coef, b):
    error = 0
    for i in range(19):
        error += (y[i] - tan(deg2rad(x[i] * coef + b)))**2
    return(error / 19)

def loleva(x, y, b, wut):
    bestCoef = ternarySearch(0, 100000, x, y, eva, b)
    return(eva(x, y, bestCoef, b))

def ternarySearch(lo, hi, x, y, func, b):
    if (lo >= hi - 1e-10): return(lo)
    midlo, midhi = (2*lo + hi) / 3, (lo + 2*hi) / 3
    if (func(x, y, midlo, b) <= func(x, y, midhi, b)):
        return(ternarySearch(lo, midhi, x, y, func, b))
    return(ternarySearch(midlo, hi, x, y, func, b))

x, y = [], []
for i in range(19):
    x += [float(input())]
for i in range(19):
    y += [float(input())]

#b = ternarySearch(0, 100000, x, y, loleva, 0)
a = ternarySearch(0, 100000, x, y, eva, 0)
#print(a, b, "error:", eva(x, y, a, b))
print(a, eva(x, y, a, 0))