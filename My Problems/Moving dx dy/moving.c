#include <stdio.h>
#include <string.h>
int n, m, dx, dy;

void printMat(int mat[][m])
{
  int i, j;
  for (i = 0; i < n; i ++)
    for (j = 0; j < m; j ++)
      printf("%4d%c", mat[i][j], j < m - 1 ? ' ' : '\n');
}

int fix(int i, int size)
{
  return(((i % size) + size) % size);
}

void move(int i, int j, int mat[][m])
{
  int step = 1;
  while (!mat[i][j])
  {
    mat[i][j] = step ++;
    i = fix(i + dy, n);
    j = fix(j + dx, m);
  }
}

int main()
{
  scanf("%d %d", &n, &m);
  int mat[n][m], y, x; memset(mat, 0, sizeof(mat));
  scanf("%d %d %d %d", &y, &x, &dy, &dx);

  move(y, x, mat);
  printMat(mat);
}
