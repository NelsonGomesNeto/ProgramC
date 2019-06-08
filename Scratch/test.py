def vmax(lista):
    n = 0
    for c in range(len(lista)):
        for i in range(len(lista)):
            if lista[i] > lista[c]:
                n = i
    return n


freq = []
num = int(input())
lista = list(range(2, num + 1))
n = num
n_1 = 0
c = 0
while True:
    print(n_1)
    if n_1 <= len(lista) - 1:
        if n % lista[n_1] == 0:
            c += 1
            n = n / lista[n_1]
        else:
            n_1 += 1
            freq.append(c)
            c = 0
            n = num
    else:
        break
mais_fre = lista[vmax(freq)]
frequencia = max(freq)
print('mostFrequent: {}, frequency: {}'.format(mais_fre, frequencia))