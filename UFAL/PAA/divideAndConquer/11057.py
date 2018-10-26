def findExact(bs, start, end, target):
    mid = int((start + end) / 2)
    if (start >= end or bs[mid] == target):
        if (bs[mid] != target):
            return(-1)
        return(mid)

    if (bs[mid] > target):
        return(findExact(bs, start, mid - 1, target))
    else:
        return(findExact(bs, mid + 1, end, target))

run = 0
while True:
    try:
        if (run > 0):
            print('\n')
            input()
        n = int(input())
        books = list(map(int, input().split()))
        books.sort()
        money = int(input())
        best = [books[0], books[len(books) - 1]]
        for i, book in enumerate(books):
            ans = findExact(books, 0, n - 1, money - book)
            if (ans != -1 and best[1] - best[0] >= ans - book and ans > i):
                best = [book, books[ans]]
            if (i + 1 < len(books) and book == books[i + 1] and book + books[i + 1] == money):
                best = [book, books[i + 1]]
                break
            if (ans != -1 and i > ans):
                break
        print("Peter should buy books whose prices are", best[0], "and", best[1], end='')
        print(".", end='')
        run += 1
    except:
        break
