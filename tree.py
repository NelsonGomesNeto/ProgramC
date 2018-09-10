from random import randint, random
global size
global isBinary

def fillTree(tree, father, left):
    global size
    size -= 1
    if (size <= 0): return
    node = (father - (1 if left else -1)) if (isBinary or randint(0, 2)) else (father + (1 if left else -1))
    tree += [node, [], []]
    fillTree(tree[2], node, 0)
    if (randint(0, 2)): fillTree(tree[1], node, 1)

def printTree(tree):
    print(end="(")
    if (len(tree) == 0):
        print(end=")")
        return
    print(end=str(tree[0]))
    printTree(tree[1])
    printTree(tree[2])
    print(end=")")

size = randint(1, 250)
isBinary = 0# randint(0, 1)
startingNode = randint(100, 200)
tree = [startingNode, [], []]
print(size)
fillTree(tree[1], startingNode, 1)
fillTree(tree[2], startingNode, 0)
print(isBinary)
printTree(tree)
print()

#