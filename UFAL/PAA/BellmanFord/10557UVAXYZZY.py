# For some unknown reason... UVA keeps return RunTimeError for Python is this question...

DEBUG = 0
inf = 2**33

while (True):
    rooms = -2
    while (rooms == -2):
        try:
            rooms = int(input())
        except EOFError:
            break
        except ValueError:
            continue

    if (rooms == -1): break

    if (rooms != 0):
        preGraph = [[] for i in range(rooms + 1)]
        energy = [0] * (rooms + 1)
        for i in range(1, rooms + 1):
            line = list(map(int, input().split()))
            energy[i] = line[0]
            for j in range(line[1]):
                preGraph[i] += [line[j + 2]]

        graph = [[] for i in range(rooms + 1)]
        for i in range(1, rooms + 1):
            for u in preGraph[i]:
                graph[i] += [[u, energy[u]]]

    cost = [inf] * (rooms + 1)
    #bellmanFord(graph, cost, path, loop, 1)
    canWin = 1
    #if (DEBUG): print("path", path, "cost", cost)

    if (canWin):
        print("winnable")
    else:
        print("hopeless")
