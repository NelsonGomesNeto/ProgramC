#include <stdio.h>

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int max(int a, int b)
{
  return(a > b ? a : b);
}

int findExit(int i, int j, int x, int y, char labyrinth[][x + 1])
{
  //printf("%d %d\n", i, j);
  if (i < 0 || j < 0 || i >= y || j >= x) return(0);
  if (labyrinth[i][j] == '#') return(0);
  if (i == y - 1 && j == x - 1) return(1);

  int k, hasExit = 0;
  for (k = 0; k < 4; k ++)
  {
    labyrinth[i][j] = '#';
    hasExit = max(hasExit, findExit(i + dy[k], j + dx[k], x, y, labyrinth));
    labyrinth[i][j] = '.';
  }

  return(hasExit);
}

int main()
{
  int y, x; scanf("%d %d", &y, &x);
  char labyrinth[y][x + 1]; int i, j;

  for (i = 0; i < y; i ++)
  {
    getchar();
    for (j = 0; j < x; j ++)
      scanf("%c", &labyrinth[i][j]);
  }

  printf("%d\n", findExit(0, 0, x, y, labyrinth));

  return(0);
}