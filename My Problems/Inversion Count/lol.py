count = 0

def mergeSort(arr):
    global count

    if (len(arr) <= 1):
        return arr

    result = []
    mid = int(len(arr) // 2)

    left = mergeSort(arr[:mid])
    right = mergeSort(arr[mid:])

    while ((len(left) > 0) or (len(right) > 0)):
        if ((len(left) > 0) and (len(right) > 0)):
            if (left[0] > right[0]):
                result.append(right[0])
                count += len(left)
                right.pop(0)
            else:
                result.append(left[0])
                left.pop(0)
        elif (len(right) > 0):
            result.extend(right)
            right = []
        else:
            result.extend(left)
            left = []
    return result

test_cases = int(input())

for i in range(test_cases):
    input()
    array_size = int(input())
    arr = []
    for j in range(array_size):
        arr.append(int(input()))
    mergeSort(arr)
    print(count)
    count = 0
