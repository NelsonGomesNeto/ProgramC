done = [0] * (10**5 + 1)
fat = [1]

def fillFat():
    global fat
    j, now = 2, 1
    while (now <= 10**5):
        fat += [now]
        now *= j
        j += 1

def bfs(target):
    queue = []
    queue += [[0, 0]]
    while (queue):
        now, steps = queue.pop(0)
        if (now == target): return(steps)

        if (done[now]): continue
        done[now] = 1

        for i in fat:
            if (i + now <= target):
                queue += [[i + now, steps + 1]]
            else:
                break

fillFat()
n = int(input())
ans = bfs(n)
print(ans)