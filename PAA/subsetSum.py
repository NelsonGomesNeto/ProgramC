def binPack(i, array, target, dp):
    if (i == len(array)):
        return(0)
    if (i not in dp):
        dp[i] = {}
    if (target not in dp[i]):
        best = binPack(i + 1, array, target, dp)
        if (target - array[i] >= 0):
            aux = binPack(i + 1, array, target - array[i], dp) + array[i]
            if (aux > best):
                best = aux
        dp[i][target] = best
    return(dp[i][target])

items = list(map(int, input().split()))
target = int(input())
positive, negative = [], []
for i in items:
    if (i < 0):
        negative += [-i]
    else:
        positive += [i]

if (target == 0):
    if (target in items):
        print("Yes")
    else:
        sumMin, Yes = min( sum(positive), sum(negative) ), False
        for i in range(1, sumMin + 1):
            if (Yes):
                break
            dp = {}
            posAnswer = binPack(0, positive, i, dp)
            dp = {}
            negAnswer = binPack(0, negative, i, dp)
            if (posAnswer == negAnswer):
                Yes = True
        if (Yes):
            print("Yes")
        else:
            print("No")
elif (target > 0):
    sumMin, Yes = sum(positive), False
    for i in range(target, sumMin + 1):
        if (Yes):
            break
        dp = {}
        posAnswer = binPack(0, positive, i, dp)
        dp = {}
        negAnswer = binPack(0, negative, i - target, dp)
        #print(negAnswer, posAnswer)
        total = sum(positive)
        if (abs(posAnswer - (total - posAnswer)) == target):
            Yes = True
    if (Yes):
        print("Yes")
    else:
        print("No")
else:
    sumMin, Yes = sum(negative), False
    for i in range(-target, sumMin + 1):
        if (Yes):
            break
        dp = {}
        negAnswer = binPack(0, negative, i, dp)
        dp = {}
        posAnswer = binPack(0, positive, i + target, dp)
        #print(i, negAnswer, posAnswer)
        if (posAnswer - negAnswer == target):
            Yes = True
    if (Yes):
        print("Yes")
    else:
        print("No")
