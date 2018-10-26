def nond(a, lo, hi):
    mid = int((lo + hi) / 2)
    if (lo >= hi):
        return(a[mid])
    if (mid % 2 == 0):
        if (a[mid] != a[mid + 1]):
            return(nond(a, lo, mid))
        else:
            return(nond(a, mid + 1, hi))
    elif (a[mid] != a[mid - 1]):
        return(nond(a, lo, mid))
    else:
        return(nond(a, mid + 1, hi))


a = list(map(int, input().split()))
print(nond(a, 0, len(a) - 1))
