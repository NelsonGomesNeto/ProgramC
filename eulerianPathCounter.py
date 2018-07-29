def eulerianPath(u, graph, path, paths, dist):
  if (not dist):
    paths += [path + u]
    return

  for v in graph[u]:
    if (graph[u][v]):
      graph[u][v], graph[v][u] = 0, 0
      eulerianPath(v, graph, path + u, paths, dist - 1)
      graph[u][v], graph[v][u] = 1, 1

nodes = int(input())
graph = {}
line = list(map(str, input().split()))
for i in line:
  graph[i] = {}
  for j in line:
    graph[i][j] = 0

for i in range(nodes):
  line = list(map(str, input().split()))
  u = line[0]
  for i in range(1, len(line)):
    graph[u][line[i]] = 1

for u in graph:
  print(u, "->", graph[u])

visited = {}
for k in graph:
  visited[k] = 0
paths = []
eulerianPath('A', graph, "", paths, 8)
print("Eulerian Paths:", len(paths))
print(paths)

print("ADCBEDBAE" in paths)