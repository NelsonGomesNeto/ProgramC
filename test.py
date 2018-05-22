def min(a,b):
    if (a<b):
        return a
    return b

def dfs_novo(u):
    global tempo
    color[u] = 1 #Seen[u] no video
    numero_de_filhos=0
    tempo += 1
    tempo_de_descoberta[u] = tempo
    low[u] = tempo
    resposta = False
    e_raiz = False
    lista = lista_de_adjacencia[u]
    #print('Lista de adjacencia u: ', lista)
    for v in lista:
        if (color[v] == 0):
            pai[v]= u
            numero_de_filhos += 1
            dfs_novo(v)
            if(pai[u]==0):
                e_raiz=True
            if(e_raiz and numero_de_filhos>1):
                pontes.append([u,v])
                array_de_articulacao[u]=1
            elif(low[v]>=tempo_de_descoberta[u] and (not(e_raiz))):
                #resposta = True
                pontes.append([u, v])
                array_de_articulacao[u] = 1
            low[u] = min(low[u], low[v])
            #if(low[v]>=tempo_de_descoberta[u]):#Ent?o ? uma ponte
        else:
            low[u] = min(low[u], tempo_de_descoberta[v])

numero_de_vertices = 0
color=[]
tempo_de_descoberta = []
low = []
lista_de_adjacencia = []
pai=[]
pontes = []
array_de_articulacao = []
vertice = 0
lista_das_entradas=[]
numero_de_articulacoes = 0
tempo=0
vertice_raiz=0

#print(numero_de_vertices)
#print(type(numero_de_vertices))
controle=True
aux=[]
i=0
while(controle):
    aux = []
    entrada = input().split(" ")
    #print('len(entrada): ', len(entrada) )
    for j in entrada:
        #print('j: ', j)
        try:
            aux.append(int(j))
        except:
            pass
    lista_das_entradas.append(aux)
    #print('aux: ', aux)
    #print('lista_das_entradas:', lista_das_entradas)
    if(len(entrada)==1 and int(entrada[0])==0):
        if(len(lista_das_entradas[i-1])==1):
            if(int(lista_das_entradas[i-1][0])==0):
                controle=False
    #aux.clear()
    i+=1

#print(lista_das_entradas)
controle=True
i=0
while(i<len(lista_das_entradas)):
    if(len(lista_das_entradas[i]) == 1 and lista_das_entradas[i][0]!=0):#Se o tamanho da entrada for 1 e o elemento for diferentee de 0, esse ser? o n?mero de v?rtices
         numero_de_vertices = lista_das_entradas[i][0]
         #print('numero_de_vertices: ', numero_de_vertices)
         k = 0
         while (k <= numero_de_vertices):
             low.append(0)
             color.append(0)
             pai.append(0)
             array_de_articulacao.append(0)
             tempo_de_descoberta.append(0)
             lista_de_adjacencia.append([])
             k += 1
    elif(len(lista_das_entradas[i])!=1):#Se o tamanho da entrada for !=1, essa entrada d? um v?rtice e seus adjascentes
        j = 1
        while (j <len(lista_das_entradas[i]) ):
            lista_de_adjacencia[lista_das_entradas[i][0]].append(lista_das_entradas[i][j])
            lista_de_adjacencia[lista_das_entradas[i][j]].append(lista_das_entradas[i][0])
            j += 1
        #print('lista_de_adjacencia', lista_de_adjacencia)

    elif(len(lista_das_entradas[i]) == 1 and int(lista_das_entradas[i][0]) == 0):#Condi??o para encerrar o programa quando temos 2 zeros
        if (len(lista_das_entradas[i - 1]) == 1):
            if (int(lista_das_entradas[i - 1][0]) == 0):
                controle = False

        else:
            #print('vertice_raiz:', vertice_raiz)
            #l = vertice_raiz
            l=1
            while (l <= numero_de_vertices):
                #print('color(',l,'): ', color[l])
                if (color[l] == 0):
                    dfs_novo(l)
                l += 1
            #print('array_de_articulacao: ', array_de_articulacao)
            l = 1
            while (l <= numero_de_vertices):
                if (array_de_articulacao[l] == 1):
                    numero_de_articulacoes += 1
                l += 1
            #print('numero_de_articulacoes:', numero_de_articulacoes)
            #if(numero_de_vertices ==2):
             #   print(2)
            #else:
             #   print(numero_de_articulacoes)
            print(numero_de_articulacoes)
            low.clear()
            color.clear()
            pai.clear()
            array_de_articulacao.clear()
            tempo_de_descoberta.clear()
            lista_de_adjacencia.clear()
            pontes.clear()
            #lista_das_entradas.clear()
            numero_de_articulacoes=0
            vertice=0
            tempo=0
            vertice_raiz=0

    i += 1
