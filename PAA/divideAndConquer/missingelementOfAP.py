def ai(ao, r, i):
    return(ao + r * i)

def missing(ap, r, start, end):
    mid = int((start + end) / 2)
    correct = ai(ap[0], r, mid)
    if (start > end):
        return(correct + r)
    if (ap[mid] == correct):
        return(missing(ap, r, mid + 1, end))
    else:
        return(missing(ap, r, start, mid - 1))

tests = int(input())
while (tests > 0):
    size = int(input())
    ap = list(map(int, input().split()))
    r = (ap[size - 1] - ap[0]) / size
    print(missing(ap, r, 0, size - 1))
    tests -= 1
