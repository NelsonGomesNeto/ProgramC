#include <stdio.h>
#include <string.h>

void sieve(int isPrime[], int size)
{
  int i, j;
  for (i = 2; i <= size; i ++)
    if (isPrime[i])
      for (j = 2; i*j <= size; j ++)
        isPrime[i*j] = 0;
}

void printArray(int array[], int size)
{
  int i;
  for (i = 0; i <= size; i ++)
    if (array[i])
      printf("%d ", i);
  printf("\n");
}

int main()
{
  int size; scanf("%d", &size);

  int isPrime[size + 1];
  memset(isPrime, 1, sizeof(isPrime));
  isPrime[0] = isPrime[1] = 0;
  isPrime[2] = 1;
  sieve(isPrime, size);

  printArray(isPrime, size);

}