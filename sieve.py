size = int(input())
sieve = [1] * (size + 1)
sieve[0], sieve[1], sieve[2] = 0, 0, 1
for i in range(2, size + 1):
    if (sieve[i]):
        for j in range(2, size // i + 1):
            sieve[i*j] = 0
for i, isPrime in enumerate(sieve):
    if (isPrime):
        print(i)