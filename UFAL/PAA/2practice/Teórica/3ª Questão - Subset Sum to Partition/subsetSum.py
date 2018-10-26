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
        print("done")
    else:
        sumMin, done = min( sum(positive), sum(negative) ), False
        for i in range(1, sumMin + 1):
            if (done):
                break
            dp = {}
            posAnswer = binPack(0, positive, i, dp)
            dp = {}
            negAnswer = binPack(0, negative, i, dp)
            if (posAnswer == negAnswer):
                done = True
        if (done):
            print("done")
        else:
            print("fock")
elif (target > 0):
    sumMin, done = sum(positive), False
    for i in range(target, sumMin + 1):
        if (done):
            break
        dp = {}
        posAnswer = binPack(0, positive, i, dp)
        dp = {}
        negAnswer = binPack(0, negative, i - target, dp)
        print(negAnswer, posAnswer)
        if (posAnswer - negAnswer == target):
            done = True
    if (done):
        print("done")
    else:
        print("fock")
else:
    sumMin, done = sum(negative), False
    for i in range(-target, sumMin + 1):
        if (done):
            break
        dp = {}
        negAnswer = binPack(0, negative, i, dp)
        dp = {}
        posAnswer = binPack(0, positive, i + target, dp)
        print(i, negAnswer, posAnswer)
        if (posAnswer - negAnswer == target):
            done = True
    if (done):
        print("done")
    else:
        print("fock")