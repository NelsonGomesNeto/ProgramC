import sys
sys.setrecursionlimit(2**20)

def merge(array, lo, mid, hi):
    copy, i, j, inversions = [], lo, mid + 1, 0
    while (i <= mid or j <= hi):
        if (i == mid + 1):
            copy += [array[j]]
            j += 1
        elif (j == hi + 1):
            copy += [array[i]]
            i += 1
        elif (array[i] > array[j]):
            copy += [array[j]]
            j += 1
            inversions += (mid - i + 1)
        else:
            copy += [array[i]]
            i += 1

    for i in range(hi - lo + 1):
        array[lo + i] = copy[i]
    return(inversions)



def mergeSort(array, lo, hi):
    if (lo >= hi): return(0)

    inversions, mid = 0, (lo + hi) // 2
    inversions += mergeSort(array, lo, mid)
    inversions += mergeSort(array, mid + 1, hi)
    inversions += merge(array, lo, mid, hi)
    return(inversions)

t = int(input())
input()
while (t):
    t -= 1
    n = int(input())
    array = []
    for i in range(n):
        array += [int(input())]

    inversions = mergeSort(array, 0, n - 1)
    #print(array)
    print(inversions)
    try:
        input()
    except EOFError as e:
        break