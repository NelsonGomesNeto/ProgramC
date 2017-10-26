#include <stdio.h>
#include <math.h>

void printMatrix(int y, int x, int mat[][x])
{
  int i, j, k, biggest = log10(mat[y-1][x-1]);
  for (i = 0; i < y; i ++)
  {
    for (j = 0; j < x; j ++)
    {
      for (k = log10(mat[i][j]); k < biggest; k ++)
        printf(" ");
      printf("%d ", mat[i][j]);
    }
    printf("\n");
  }
}

int min(int a, int b)
{
  return(a < b ? a : b);
}

int max(int a, int b)
{
  return(a > b ? a : b);
}

int main()
{
  int y, x, i, j; scanf("%d %d", &y, &x);
  int mat[y][x];
  int go = 1, now = 1;
  for (i = 0; i < y + x - 1; i ++)
  {
    j = 0;
    while (j < go)
    {
      printf("%d %d %d\n", i - j, y - 1 - j, j + (i / y));
      mat[min(i, y - 1) - j][j + max(i - y + 1, 0)] = now ++;
      j ++;
    }
    // j = 0;
    // while (j < go)
    // {
    //   if (i - j >= 0 && i - j < y  && j >= 0 && j < x)
    //     mat[i - j][j] = now ++;
    //   j ++;
    // }
    go = y - (y - i) + 2;
  }

  printMatrix(y, x, mat);

  return(0);
}