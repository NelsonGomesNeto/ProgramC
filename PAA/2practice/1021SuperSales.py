import sys
sys.setrecursionlimit(2**20)
DEBUG = 0

def knapsack(dp, obj, i, weight):
    if (i == len(obj)):
        return(0)

    if (dp[i][weight] == -1):
        dp[i][weight] = knapsack(dp, obj, i + 1, weight)
        if (obj[i][1] <= weight):
            dp[i][weight] = max(dp[i][weight], knapsack(dp, obj, i + 1, weight - obj[i][1]) + obj[i][0])

    return(dp[i][weight])


def solve(obj, people):
    peopleDP = [-1] * 31
    total = 0
    for i in people:
        if (peopleDP[i] == -1):
            ksDP = [[-1] * (i + 1) for j in range(len(obj) + 1)]
            peopleDP[i] = knapsack(ksDP, obj, 0, i)
        total += peopleDP[i]
    return(total)


tests = int(input())
while (tests > 0):
    numObjects = int(input())
    obj = []
    for i in range(numObjects):
        obj += [list(map(int, input().split()))]
    if (DEBUG):
        print("obj", obj)

    numPeople = int(input())
    people = []
    for i in range(numPeople):
        people += [int(input())]
    if (DEBUG):
        print("people", people)

    answer = solve(obj, people)
    print(answer)

    tests -= 1