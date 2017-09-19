import sys
sys.setrecursionlimit(2**20)
DEBUG = 1

def solve(obj, people, prev, i, end):
    #print(people)
    if (i == end):
        return(0)

    best = solve(obj, people, -1, i + 1, end)
    for j in range(len(people)):
        if (prev != j and people[j] >= obj[i][1]):
            people[j] -= obj[i][1]
            best = max(best, solve(obj, people, j, i, end) + obj[i][0])
            people[j] += obj[i][1]
            #print(best)
    return(best)


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

    answer = solve(obj, people, -1, 0, numObjects)
    print(answer)

    tests -= 1