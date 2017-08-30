def findPair(hs, start, end, target):
    mid = int((start + end) / 2)
    if (start > end or hs[mid] == target):
        smaller, taller = "X", "X"
        while (mid >= 0 and hs[mid] >= target):
            mid -= 1
        if (mid >= 0):
            smaller = hs[mid]
        mid = int((start + end) / 2)
        while (mid < len(hs) and hs[mid] <= target):
            mid += 1
        if (mid < len(hs)):
            taller = hs[mid]
        print(smaller, taller)
        return

    if (hs[mid] > target):
        findPair(hs, start, mid - 1, target)
    else:
        findPair(hs, mid + 1, end, target)

n = int(input())
heights = list(map(int, input().split()))
q = int(input())
luchu = list(map(int, input().split()))
for query in luchu:
    findPair(heights, 0, n - 1, query)
