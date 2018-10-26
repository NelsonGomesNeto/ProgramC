import sys
sys.setrecursionlimit(100000)
def findBest(es, start, end):
    mid = (end + start) / 2
    gas = round(test(es, mid), 3)
    if (gas == 0):
        return(mid)
    if (gas > 0):
        return(findBest(es, start, mid - 1))
    else:
        return(findBest(es, mid + 1, end))

def test(es, gas):
    i, cons, leak, full = 2, es[1][2], 0, gas
    while (es[i - 1][1] != 'G'):
        km = es[i][0] - es[i - 1][0]
        gas -= ((km / 100) * cons) + (leak * km)
        if (gas < 0):
            break
        if (es[i][1] == 'L'):
            leak += 1
        if (es[i][1] == 'M'):
            leak = 0
        if (es[i][1] == 'S'):
            gas = full
        if (es[i][1] == 'F'):
            cons = es[i][2]
        i += 1
    return(gas)

def readEvents():
    i = 1
    while (True):
        if (event[i - 1][1] == 'G' or event[i - 1] == [0, 'F', 0]):
            break
        string = input()
        string = string.replace("Fuel consumption", "F")
        string = string.replace("Goal", "G")
        string = string.replace("Mechanic", "M")
        string = string.replace("Leak", "L")
        string = string.replace("Gas station", "S")
        event.append(string.split())
        event[i][0] = int(event[i][0])
        if (len(event[i]) > 2):
            event[i][2] = int(event[i][2])
        i += 1
    return(event)

while(True):
    event = [[0,0,0]]
    event = readEvents()
    if (event[1] == [0, 'F', 0]):
        break
    print("%.3f" % findBest(event, 0, 10000))
