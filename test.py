#Testando com HEAP

import heapq


def dijkstra(graph, starting_vertex):
    distances = {vertex: float('infinity') for vertex in graph}
    distances[starting_vertex] = 0

    entry_lookup = {}
    pq = []

    for vertex, distance in distances.items():
        entry = [distance, vertex]
        entry_lookup[vertex] = entry
        heapq.heappush(pq, entry)

    while len(pq) > 0:
        current_distance, current_vertex = heapq.heappop(pq)

        for neighbor, neighbor_distance in graph[current_vertex].items():
            distance = distances[current_vertex] + neighbor_distance
            if distance < distances[neighbor]:
                distances[neighbor] = distance
                entry_lookup[neighbor][0] = distance

    return distances


def make_reciprocity(graph,v,u):
    graph[u][v] = graph[v][u]

def check_reciprocity(graph,v,u):
    if graph[u].get(v) == None:
        make_reciprocity(graph,v,u)

def lendo_ABC():
  A,B,C = [int(i) for i in input().split()]
  lis_aux = [A, B, C]
  return(lis_aux)

def magica(): #Roda oque � pedido para cada teste
  i = 0
  soma = 0
  grafo_dic = {}
  lista_caminhos = []
  lista_locais = [] #locais dos pedidos
  grafo_dic[1] = {} #Pizzaria sempre � o n� inicial

  n,m = [int(i) for i in input().split()] #ARMAZENANDO N E M

  i = 1
  while i < n+1: #CRIANDO OS VERTICES NO DICIONARIO
    grafo_dic[i] = {}
    grafo_dic[i][i] = 0
    i = i+1

  i = 0
  while i != m: #COLOCANDO AS ARESTAS EM UMA LISTA
    r = lendo_ABC()
    grafo_dic[r[0]][r[1]] = r[2] #PREENCHENDO O DICION�RIO COM AS ARESTAS
    grafo_dic[r[1]][r[0]] = r[2] #FAZENDO A RECIPROCIDADE
    i = i+1
  print(grafo_dic)

  quantidade_pizzas = int(input())
  if(quantidade_pizzas == 0):
  	return 0
  lista_locais = [int(i) for i in input().split()] #LISTA DE CASAS
  #aux = lista_locais.split(" ")
  #lista_locais = [int(i) for i in aux] #LISTA DE VERTICES EM INTEIROS

  #i = 0
  #while i < m: #CRIANDO AS ARESTAS
  #  a = lista_caminhos[i][0]
  #  b = lista_caminhos[i][1]
  #  c = lista_caminhos[i][2]
  #  grafo_dic[a][b] = c
  #  i = i+1

  #for v in grafo_dic:
  #  for u in grafo_dic[v]:
  #      check_reciprocity(grafo_dic,v,u)

  distance = dijkstra(grafo_dic, 1)

  for casa in lista_locais: #CONTANDO O PERCURSO
    soma = soma + distance[casa]

  return soma*2 #MULTIPLICANDO POR 2 (IDA E VOLTA)


n_casos = int(input())
i = 0

while i != n_casos:
  resultado = magica()
  #print('caso', i+1,':',resultado)
  print('caso ',end='',flush=True)
  print(i+1,end='',flush=True)
  print(':',end='',flush=True)
  print('',resultado)
  i = i+1