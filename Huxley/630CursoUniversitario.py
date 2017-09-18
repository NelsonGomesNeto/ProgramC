DEBUG = 1

def topologicalSortBFS(graph):
	inDegree = [0] * len(graph)
	for u in graph:
		for v in u:
			inDegree[v] += 1

	queue = []
	for i, quantity in enumerate(inDegree):
		if (quantity == 0):
			queue += [i]

	answer, counter = [], 0
	while (queue):
		curr = queue.pop(0)
		answer += [curr]
		for u in graph[curr]:
			inDegree[u] -= 1
			if (inDegree[u] == 0):
				queue += [u]
		counter += 1

	if (counter != len(graph)):
		return([])
	else:
		return(answer)

while (True):
	advancedClasses, maximumClasses = map(int, input().split())
	if (advancedClasses == 0 and maximumClasses == 0):
		break

	preGraph, classes = [], []
	for i in range(advancedClasses):
		line = input().split()
		line.pop(1)
		preGraph += [line]
		classes += line
	classes = set(classes)
	stringToInt = dict(zip(classes, range(len(classes))))
	intToString = dict(zip(range(len(classes)), classes))
	if (DEBUG):
		print("PreGraph:", preGraph)
		print("Maps:", stringToInt, intToString)


	graph = [[] for i in range(len(classes))]
	for i in preGraph:
		for j in i[1:]:
			graph[stringToInt[i[0]]] += [stringToInt[j]]
	if (DEBUG):
		print("Graph", graph)

	answer = topologicalSortBFS(graph)
	answer.reverse()
	print(answer)
	semester, initialClass = 0, 0
	while (initialClass != len(classes)):
		semester += 1
		thisSemester = answer[initialClass : initialClass + maximumClasses]
		initialClass += maximumClasses
		print(semester, thisSemester)