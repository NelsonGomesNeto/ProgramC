def pot(x, n):
    if (n == 0):
        return(1)
    if (n == 1):
        return(x)
    if (n % 2 == 0):
        half = pot(x, n / 2)
        return(half * half)
    else:
        half = pot(x, (n - 1) / 2)
        return(half * half * x)

x, n = map(int, input().split())
print(pot(x, n))

def compare(x, n):
    start = time.time()
    print(x**n)
    default = time.time() - start
    print("Python default: ", default, "sec")
    #
    start = time.time()
    print(pot(x, n))
    fast = time.time() - start
    print("Fast Exponentiation: ", fast, "sec")
    print("\nFast Exponentiation is: ", default - fast, "sec faster (", ((default - fast) / default) * 100, "%)")
