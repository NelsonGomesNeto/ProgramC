while True:
    size = int(input())
    begin = end = -1
    array = [0] * size
    for i in range(0, size):
        array[i] = int(input())

    maxSum = 0
    for first in range(0, size):
        som = 0
        for last in range(first, size):
            som += array[last]
            if som > maxSum:
                maxSum = som
                begin = first
                end = last

    print(maxSum, begin, end)
