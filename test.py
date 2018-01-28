def find_eulerian_tour(graph): # Função(grafo)
    tour=[] # Tour recebe uma lista vazia
    find_tour(graph[0][0],graph,tour) # Encontra o tour partindo de um nó
    return tour # Retorna o tour

def find_tour(u,E,tour): # Função(nó, grafo, tour)
  for (a,b) in E: # Para cada par (a, b) em E
    if a==u: # Se a == b
        E.remove((a,b)) # Remove o par (a, b) da lista/grafo E
        find_tour(b,E,tour) # Recursivamente acha o tour partindo de b
    elif b==u: # Se b == nó anterior (u)
        E.remove((a,b)) # Remove o par (a, b) da lista/grafo E
        find_tour(a,E,tour) # Recursivamente acha o tour partindo de a
  tour.insert(0,u) # Insere na lista o nó u