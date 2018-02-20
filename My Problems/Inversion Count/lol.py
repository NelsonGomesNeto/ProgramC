arr = []

test_cases = int(input())
input()

while test_cases > 0:

    array_size = int(input())
    arr.clear()

    # lê os elementos do array
    while array_size > 0:

        arr.append(int(input()))
        array_size -= 1

    input() # lê a linha em branco

    if array_size == 1:
        print("0")
    else:
        i = 0
        count = 0

        # verifica as inversões
        while i < len(arr) - 1:
            j = i + 1
            while j < len(arr):
                if arr[i] > arr[j]:
                    count += 1
                j += 1
            i += 1

    print(count)
    test_cases -= 1
