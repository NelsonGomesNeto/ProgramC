#include <stdio.h>
int DEBUG = 0;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {-1, 1, 0, 0};

void printMatrix(int y, int x, char mat[][x])
{
  int i, j;
  for (i = 0; i < y; i ++)
  {
    for (j = 0; j < x; j ++)
      printf("%c", mat[i][j]);
    printf("\n");
  }
}

int getPoints(char block)
{
  switch (block)
  {
    case '#': return(0);
    case '.': return(0);
    case 'b': return(1);
    case 'p': return(5);
    case 'o': return(10);
    case 'd': return(50);
  }
}

int max(int a, int b)
{
  return(a > b ? a : b);
}

int steps = 0;

int floodFill(int y, int x, char fi[][x], int i, int j)
{
  steps ++;
  if (fi[i][j] == '#') return(0);

  if (DEBUG == 1){printf("%d %d\n", i, j); printMatrix(y, x, fi); printf("\n");}
  int k; int points = 0, maxPoints = 0;
  for (k = 0; k < 4; k ++)
  {
    points = getPoints(fi[i][j]);
    if (i + dy[k] >= 0 && i + dy[k] < y
    &&  j + dx[k] >= 0 && j + dx[k] < x
    &&  fi[i + dy[k]][j + dx[k]] != '#')
    {
      char prev = fi[i][j];
      fi[i][j] = '#';
      points += floodFill(y, x, fi, i + dy[k], j + dx[k]);
      fi[i][j] = prev;
    }
    maxPoints = max(maxPoints, points);
  }
  return(maxPoints);
}

int main()
{
  int y, x; scanf("%d %d", &y, &x);
  char field[y][x];
  int i, j;
  for (i = 0; i < y; i ++)
  {
    getchar();
    for (j = 0; j < x; j ++)
      scanf("%c", &field[i][j]);
  }
  if (DEBUG == 1) printMatrix(y, x, field);

  int best = floodFill(y, x, field, 0, 0);
  if (DEBUG == 1) printMatrix(y, x, field);

  printf("%d\n", best);

  if (DEBUG == 2) printf("%d\n", steps);

  return(0);
}