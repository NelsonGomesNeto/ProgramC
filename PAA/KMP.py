DEBUG = 0

def preProcess(subString):
    backTable = [-1] * (len(subString) + 1)
    i, j = 0, -1
    while (i < len(subString)):
        while (j >= 0 and subString[i] != subString[j]):
            j = backTable[j]
        i += 1
        j += 1
        backTable[i] = j
    return(backTable)

def kmpSearch(string, subString):
    i, j, occurrence = 0, 0, []
    while (i < len(string)):
        start = i
        if (DEBUG): print("i", i, "j", j)
        while (j >= 0 and string[i] != subString[j]):
            j = backTable[j]
            if (DEBUG): print("\tj", j)
        i += 1
        j += 1
        if (j == len(subString)):
            occurrence += [i - j]
            j = backTable[j]
    return(occurrence)

subString = input()
string = input()

backTable = preProcess(subString)
print("backTable", backTable)

occurrence = kmpSearch(string, subString)

print("occurrence", occurrence)

