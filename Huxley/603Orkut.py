friendsSize = int(input())
friends = list(input().split())
stringToInt = dict(zip(friends, range(0, friendsSize)))
intToString = dict(zip(range(0, friendsSize), friends))
print(stringToInt, intToString)

graph = [[] for i in range(friendsSize)]
for i in range(friendsSize):
    line = input().split()
    u, uFriends = line[0], line[1:]
    for v in uFriends[1:]:
        graph[stringToInt[u]] += [stringToInt[v]]

print(graph)
for i, u in enumerate(graph):
    print(intToString[i], end='')
    for v in u:
        print('->', intToString[v], end = ' ')
    print()

# Do BFS Topological Sort!!!!