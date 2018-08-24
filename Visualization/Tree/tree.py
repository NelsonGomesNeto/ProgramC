def dfs(tree, u, shift):
    if (len(tree[u]) == 0): return(shift, shift)
    size = len(tree[u])//2 - len(tree[u]) + (len(tree[u]) & 1) + (shift > 0 and len(tree[u]) > 1)
    print(u, shift)
    mini, maxi = shift, shift
    for v in tree[u]:
        lo, hi = dfs(tree, v, shift + size)
        mini, maxi = min(lo, mini), max(hi, maxi)
        size += 1
    level[]
    print(u, mini, maxi)
    return(mini, maxi)

source = input()
tree = {}
while (True):
    try:
        line = input().split()
        u, v = line[0], line[1:]
        if (u not in tree): tree[u] = []
        for vv in v:
            if (vv not in tree): tree[vv] = []
        tree[u] += v
    except:
        break
print(tree)

level = {}
dfs(tree, source, 0)