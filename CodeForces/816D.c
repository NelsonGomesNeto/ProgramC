#include <stdio.h>

int reducted(int size)
{
  if (size % 4 == 1)
    return(0);
  else if (size % 4 == 0)
    return(3);
  else if (size % 4 == 2)
    return(1);
  else
    return(2);
}

void doReduction(int a[], int size)
{
  int i, times = reducted(size), j, k;
  for (i = 0, k = 1; i < times; i ++)
  {
    for (j = 0; j < size - i - 1; j ++, k *= -1)
    {
      a[j] = (a[j] + (k * a[j + 1]));
      if (a[j] < 0) a[j] += 1000000007;
      a[j] %= 1000000007;
    }
  }
}

long long int binomial(int n, int k)
{
  long long int c = 1, i;
  if (k > n - k) k = n - k;
  for (i = 1; i <= k; i ++, n --)
    c = (long long int) (c/i * n + c%i * n / i) % 1000000007;

  return(c % 1000000007);
}

long long int mult(long long int j, long long int a)
{
  int i;
}

long long int doSum(int a[], int size)
{
  int i, k, mid = size / 2; long long int sum = 0, j;
  int pot = (size - 1) / 2;
  for (i = 0, k = 0; i < size; i += 2, k ++)
  {
    j = binomial(pot, k);

    sum += mult(j, a[i]);
    if (sum < 0) sum += 1000000007;
    sum %= 1000000007;
  }

  if (sum < 0) sum += 1000000007;

  return(sum % 1000000007);
}

int main()
{
  int numbers; scanf("%d", &numbers);
  int array[numbers], i;
  for (i = 0; i < numbers; i ++)
    scanf("%d", &array[i]);

  doReduction(array, numbers);

  printf("%Ld\n", doSum(array, numbers - reducted(numbers)));

  return(0);
}
