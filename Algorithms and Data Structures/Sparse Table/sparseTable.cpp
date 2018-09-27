#include <bits/stdc++.h>
using namespace std;
const int maxLog = (int) floor(log2(1e6)) + 1;
int sparseTable[(int) 1e6][maxLog];

void printArray(int a[], int n)
{
  for (int i = 0; i < n; i ++) printf("%d%c", a[i], i < n - 1 ? ' ' : '\n');
}

int f(int a, int b)
{
  return(min(a, b));
}

void build(int a[], int n, int logn)
{
  for (int i = 0; i < n; i ++) sparseTable[i][0] = a[i];

  for (int j = 1; j <= logn; j ++)
    for (int i = 0, prev = j - 1; i < n; i ++)
    {
      // printf("%d %d - (%d, %d) (%d, %d)\n", i, j, i, prev, min(n-1, i + (1 << j)), prev);
      sparseTable[i][j] = f(sparseTable[i][prev], sparseTable[min(n-1, i + prev + 1)][prev]);
    }
}

int query(int lo, int hi)
{
  int fim = 1 << 20;
  for (int j = maxLog; j >= 0; j --)
    if (lo + (1 << j) - 1 <= hi)
    {
      printf("%d %d\n", lo, j);
      fim = f(fim, sparseTable[lo][j]);
      lo += (1 << j) - 1;
    }
  return(fim);
}

int main()
{
  int n; scanf("%d", &n);
  int array[n]; for (int i = 0; i < n; i ++) scanf("%d", &array[i]);
  int logn = floor(log2(n));
  printf("size: %d, logn: %d\n", n, logn);
  printArray(array, n);

  build(array, n, logn);
  for (int i = 0; i < n; i ++) printArray(sparseTable[i], logn + 1);

  int lo, hi;
  while (scanf("%d %d", &lo, &hi) != EOF)
  {
    printf("[%d, %d] = %d\n", lo, hi, query(lo, hi));
  }

  return(0);
}
