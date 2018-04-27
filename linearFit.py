import sys
sys.setrecursionlimit(2**20)

def eva(x, y, coef, b):
    error = 0
    for i in range(20):
        error += (y[i] - (x[i] * coef + b))**2
    return(error / 20)

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
for i in range(20):
    x += [float(input())]
for i in range(20):
    y += [float(input())]

b = ternarySearch(0, 100000, x, y, loleva, 0)
a = ternarySearch(0, 100000, x, y, eva, b)
print(a, b, "error:", eva(x, y, a, b))