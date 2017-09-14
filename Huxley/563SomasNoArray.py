tests = int(input())
while (tests > 0):
    coins, queries = map(int, input().split())
    coin = list(map(int, input().split()))
    #coin.sort()

    coinChange = [[0] * (coin[coins - 1] + 1) for i in range(coins + 1)]
    coinChange[0] = 1
    for i in range(coins + 1)[1:]:
        mini = coins[0:i]
        mini.sort()
        for j in range(coin[coins - 1] + 1):
            for k in range(mini):
                coinChange[i][j] += coinChange[i][j - k]

    print(len(coinChange), len(coinChange[0]))
    for i in range(queries):
        elements, sumTarget = map(int, input().split())

    tests -= 1
