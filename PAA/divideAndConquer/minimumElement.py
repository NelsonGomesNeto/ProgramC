def minimum(a, start, end):
    mid = int((start + end) / 2)
    if (start == end - 1):
        return(a[end])
    if (a[start] > a[mid]):
        return(minimum(a, start, mid))
    elif (a[end] < a[mid]):
        return(minimum(a, mid, end))
    else:
        return(a[0])

tests = int(input())
while (tests > 0):
    size = int(input())
    a = list(map(int, input().split()))
    print(minimum(a, 0, size - 1))
    tests -= 1
