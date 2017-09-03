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

for i in range(100):
    counter[0] = 0
    firstFor(i)
    print(counter[0], i ** 5)
