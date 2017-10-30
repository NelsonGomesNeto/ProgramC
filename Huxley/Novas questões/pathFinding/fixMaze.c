#include <stdio.h>
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

int valid(int i, int j, int y, int x, char maze[][x + 1])
{
  return(!(i < 0 || j < 0 || i >= y || j >= x || maze[i][j] == '.'));
}

int neighboorhood(int i, int j, int y, int x, char maze[][x + 1])
{
  int total = 0, k;
  for (k = 0; k < 4; k ++)
    total += valid(i + dy[k], j + dx[k], y, x, maze);
}

char getWall(int k)
{
  if (k == 0) return('#');
  if (k == 1)
}

int main()
{
  int y, x; scanf("%d %d", &y, &x);
  char maze[y][x + 1]; int i, j;
  for (i = 0; i < y; i ++)
  {
    getchar();
    scanf("%s", maze[i]);
  }

  for (i = 0; i < y; i ++)
  {
    for (j = 0; j < x; j ++)

  }

  return(0);
}