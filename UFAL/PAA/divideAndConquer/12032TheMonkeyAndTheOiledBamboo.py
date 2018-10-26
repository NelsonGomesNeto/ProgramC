def test(b, k):
    prev = 0
    for h in b:
        if (h - prev > k):
            return(False)
        elif (h - prev == k):
            k -= 1
        prev = h
    return(True)

def findGuess(b, start, end):
    mid = int((start + end) / 2)
    if (start >= end):
        return(mid)
    if (test(b, mid)):
        return(findGuess(b, start, mid))
    else:
        return(findGuess(b, mid + 1, end))

tests = int(input())
run = 1
while (run <= tests):
    n = int(input())
    bamboo = list(map(int, input().split()))
    print("Case ", run, ": ", findGuess(bamboo, 0, bamboo[len(bamboo) - 1]), sep='')
    run += 1
