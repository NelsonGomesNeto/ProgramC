#include <stdio.h>

void printMatrix(int y, int x, int mat[][x])
{
  int i, j;
  for (i = 0; i < y; i ++)
  {
    for (j = 0; j < x; j ++)
      printf("%d ", mat[i][j]);
    printf("\n");
  }
}

int main()
{
  int y, x, i, j; scanf("%d %d", &y, &x);
  int mat[y][x];
  int go = 1, now = 1;
  for (i = 0, j = 0; i < y; i ++, j ++)
  {
    if (i > y) i = y - 1;
    if (j > x) j = x - 1;

  }

  printMatrix(y, x, mat);

  return(0);
}