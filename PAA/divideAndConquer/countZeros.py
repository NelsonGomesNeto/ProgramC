def countZeros(a, start, end):
    mid = int((start + end) / 2)
    if (start > end):
        return(len(a) - mid - a[mid])
    if (a[mid] == 0):
        return(countZeros(a, start, mid - 1))
    else:
        return(countZeros(a, mid + 1, end))

tests = int(input())
while (tests > 0):
    size = int(input())
    a = list(map(int, input().split()))
    print(countZeros(a, 0, size - 1))
    tests -= 1
