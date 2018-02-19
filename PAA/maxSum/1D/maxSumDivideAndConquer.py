def divideAndConquer(a, left, right):
    if (left == right):
        if (a[left] < 0):
            return 0
        else:
            return a[left]

    som = maxLeft = maxRight = 0
    mid = int((left + right) / 2)
    for i in range(mid, left - 1, -1):
        som += a[i]
        if (som > maxLeft):
            maxLeft = som

    som = 0
    for i in range(mid + 1, right + 1):
        som += a[i]
        if (som > maxRight):
            maxRight = som

    return max(max(divideAndConquer(a, left, mid), divideAndConquer(a, mid + 1, right)), maxLeft + maxRight)

while True:
    size = int(input())
    array = [0] * size
    for i in range(0, size):
        array[i] = int(input())

    print(divideAndConquer(array, 0, size - 1))
