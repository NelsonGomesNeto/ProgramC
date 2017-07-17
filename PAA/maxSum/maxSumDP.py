def dp(a):
    size = len(a)
    som = maxSum = 0
    for i in range(0, size):
        som += a[i]
        if som > maxSum:
            maxSum = som
        if som < 0:
            som = 0

    return maxSum

while True:
    size = int(input())
    begin = end = -1
    array = [0] * size
    for i in range(0, size):
        array[i] = int(input())

    print(dp(array))
