#include <stdio.h>
#include <string.h>
int n, m, dx, dy;

void printMat(int mat[][m])
{
  int i, j;
  for (i = 0; i < n; i ++)
    for (j = 0; j < m; j ++)
      printf("%3d%c", mat[i][j], j < m - 1 ? ' ' : '\n');
}

int fix(int i, int size)
{
  if (i < 0) i = i % size + size;
  return(i % size);
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
  int mat[n][m]; memset(mat, 0, sizeof(mat));
  scanf("%d %d", &dx, &dy);

  move(0, 0, mat);
  printMat(mat);
}
