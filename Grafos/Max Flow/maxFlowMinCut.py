def printGraph(graph):
	for u in sorted(graph):
		print(u, end=" -> ")
		for v in sorted(graph[u]):
			print((v, graph[u][v]), end=' ')
		print()

graph = {}
source, target = "source", "target"
graph[source], graph[target] = {}, {}
n = int(input())
for i in range(1, n + 1):
	graph["task %d" % i] = {}
	graph["task %d" % i][target] = [1, 0] # flow, cost

for i in range(1, n + 1):
	ce = input().split()
	graph[source]["emp %d" % i] = [1, 0]
	graph["emp %d" % i] = {}
	for j, c in enumerate(ce):
		graph["emp %d" % i]["task %d" % (j + 1)] = [1, int(c)]

printGraph(graph)