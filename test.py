import heapq

def dijkstra(start, graph, distances):
    distances[start] = 0
    pq = []
    heapq.heappush(pq,[0, start] )
    #pq.put([0, start])  # Distancia, Node
    while pq:
        curr = heapq.heappop(pq)
        u = curr[1]
        # print(u)
        dist = curr[0]
        if (dist <= distances[u]):
            for x in graph[u]:
                v = x[0]
                w = x[1]
                if distances[v] > distances[u] + w:
                    distances[v] = distances[u] + w
                    #pq.put([-distances[v], v])
                    heapq.heappush(pq,[distances[v], v])

def cnvtCalcula(l):  #Converte pra inteiro e j� soma na "soma". Usei no map.
    global soma
    l = int(l) -1
    soma += distances[l]
    return l


t = int(input())
for a in range(t):
    n_vertices, n_edges = map(int, input().split())
    graph = {}
    for b in range(n_edges):
        u, v, c = map(int, input().split())
        u = u - 1
        v = v - 1
        if u not in graph:
            graph[u] = []
        graph[u].append([v, c])
        if v not in graph:
            graph[v] = []
        graph[v].append([u, c])
    distances = []
    for b in range(n_vertices):
        distances.append(2 ** 20)
    dijkstra(0, graph, distances)
    n_pedidos = int(input())
    soma = 0
    pedidos = list(map(cnvtCalcula, input().split()))
    print("caso ",a+1,": ",soma*2,sep='')
