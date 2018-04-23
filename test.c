#include <stdio.h>
#include <stdlib.h>

void lerarray(int i, int j, int n, int v[][n])
{

  if(i >= n)
  {
    return;
  }
  else
  {
    if(j >= n)
    {
      j = 0;
      i = i + 1;
    }
      scanf("%d", &v[i][j]);
      lerarray(i, j+1, n, v);
  }
}

void somaarray(int n, int i, int j, int A[][n],int B[][n])
{
  if(i >= n)
  {
    return;
  }
  else
  {
    if(j >= n)
    {
      j = 0;
      i = i + 1;
    }
      printf("%d\n", A[i][j]+B[i][j]);
      somaarray(n, i, j+1, A, B);
  }

}

int main()
{
  int n;
  scanf("%d", &n);
  int A[n][n], B[n][n];
  lerarray(n, 0, 0, A);
  lerarray(n, 0, 0, B);
  somaarray(n, 0, 0, A, B);
  return 0;

}