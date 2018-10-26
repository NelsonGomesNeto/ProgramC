#include <stdio.h>

typedef long long int M[2][2];
M m = {{1, 1}, {1, 0}};

void multiply(M res, M a, M b)
{
  res[0][0] = (a[0][0] * b[0][0]) + (a[0][1] * b[1][0]);
  res[0][1] = (a[0][0] * b[0][1]) + (a[0][1] * b[1][1]);
  res[1][0] = (a[1][0] * b[0][0]) + (a[1][1] * b[1][0]);
  res[1][1] = (a[1][0] * b[0][1]) + (a[1][1] * b[1][1]);
}

void assign(M a, M b)
{
  a[0][0] = b[0][0];
  a[0][1] = b[0][1];
  a[1][0] = b[1][0];
  a[1][1] = b[1][1];
}

void pot(M res, M x, int n)
{
  if (n == 1)
  {
    assign(res, x);
    return;
  }

  if (n & 1) // odd
  {
    M half; pot(half, x, (n - 1) / 2);
    M temp;
    multiply(temp, half, half);
    multiply(res, x, temp);
    return;
  }
  else
  {
    M half; pot(half, x, n / 2);
    multiply(res, half, half);

    return;
  }
}

long long int fib(int n)
{
  M result;
  pot(result, m, n);

  printf("%Ld %Ld\n%Ld %Ld\n", result[0][0], result[0][1], result[1][0], result[1][1]);
  return(result[0][1]);
}

int main()
{
  int n;
  while (scanf("%d", &n) != EOF)
    printf("Fib: %Ld\n", fib(n));

  return(0);
}