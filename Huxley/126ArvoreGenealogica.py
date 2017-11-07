inf = 2**33

def grade(graph, a, b, dp):
    if (a == b): return(0)
    a1, a2 = inf, inf
    if (len(graph[a]) == 1):
        if (dp[graph[a][0]][b] == -1):
            dp[graph[a][0]][b] = grade(graph, graph[a][0], b, dp)
        a1 = dp[graph[a][0]][b]
    if (len(graph[b]) == 1):
        if (dp[a][graph[b][0]]):
            dp[a][graph[b][0]] = grade(graph, a, graph[b][0], dp)
        a2 = dp[a][graph[b][0]]
    if (a1 > a2):
        a1 = a2
    return(1 + a1)

relations = int(input())
stringToInt, intToString = {}, {}
preGraph = []
people = 0
for i in range(relations):
    u, v = int().split()
    preGraph += [[u, v]]
    if (u not in stringToInt):
        stringToInt[u] = people
        intToString[people] = u
        people += 1
    if (v not in stringToInt):
        stringToInt[v] = people
        intToString[people] = v
        people += 1
graph = [[] for i in range(people)]
for line in preGraph:
    graph[stringToInt[line[1]]] += [stringToInt[line[0]]]

dp = [[-1] * range(people) for i in range(people)]
best = [0]
for i in stringToInt:
    for j in stringToInt:
        if (dp[stringToInt[i]][stringToInt[j]] == -1):
            aux = grade(graph, stringToInt[i], stringToInt[j], dp)
            if (aux > best[0]):
                best = [aux, i, j]

print()