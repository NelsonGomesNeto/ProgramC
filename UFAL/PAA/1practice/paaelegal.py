counter = [0]

def firstFor(n):
    if (n < 0):
        return
    secondFor(n**2)
    firstFor(n - 1)
def secondFor(n):
    if (n < 0):
        return
    thirdFor(n)
    secondFor(n - 1)
def thirdFor(n):
    if (n < 0):
        return
    counter[0] += 1
    #print("PAA é legal")
    thirdFor(n - 1)

def paaelegal(n):
    counter = 0
    for i in range(n + 1):
        for j in range(i**2 + 1):
            for k in range(j + 1):
                counter += 1
    return(counter)


for i in range(30):
    counter[0] = 0
    #firstFor(i)
    print(paaelegal(i), ',', sep='', end='')

