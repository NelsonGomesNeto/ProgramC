#include <stdio.h>
int dx[6] = {0, 0, 0, 0, 1, -1};
int dy[6] = {1, -1, 0, 0, 0, 0};
int dz[6] = {0, 0, 1, -1, 0, 0};

void printMatrix(int z, int y, int x, char maze[][y][x + 1])
{
  int i, j, k;
  for (i = 0; i < z; i ++)
  {
    for (j = 0; j < y; j ++)
    {
      for (k = 0; k < x; k ++)
        printf("%c", maze[i][j][k]);
      printf("\n");
    }
    if (i < z - 1) printf("\n");
  }
}

char getDir(int n)
{
  if (n == 0) return('^');
  if (n == 1) return('v');
  if (n == 2) return('+');
  if (n == 3) return('@');
  if (n == 4) return('<');
  return('>');
}

int findPath(int z, int y, int x, int i, int j, int k, char maze[][y][x + 1])
{
  if (i < 0 || i >= z || j < 0 || j >= y || k < 0 || k >= x || maze[i][j][k] != '.') return(0);
  if (i == 0 && j == 0 && k == 0)
  {
    return(1);
  }

  int n;
  for (n = 0; n < 6; n ++)
  {
    char aux = maze[i][j][k];
    maze[i][j][k] = '*';
    if (findPath(z, y, x, i + dz[n], j + dy[n], k + dx[n], maze))
    {
      maze[i + dz[n]][j + dy[n]][k + dx[n]] = getDir(n);
      printf("(%d, %d, %d)%s", i /*+ dz[n]*(-1)*/, j /*+ dy[n]*(-1)*/, k /*+ dx[n]*(-1)*/, (i == z - 1 && j == y - 1 && k == x - 1) ? " -> END\n" : " -> ");
      return(1);
    }
    maze[i][j][k] = aux;
  }
  return(0);
}

int main()
{
  int z, y, x; scanf("%d %d %d", &z, &y, &x);
  char maze[z][y][x + 1]; int i, j, k;
  for (i = 0; i < z; i ++)
  {
    for (j = 0; j < y; j ++)
    {
      getchar();
      for (k = 0; k < x; k ++)
        scanf("%c", &maze[i][j][k]);
      maze[i][j][k] = '\0';
    }
    getchar();
  }

  int ans = findPath(z, y, x, z - 1, y - 1, x - 1, maze);
  printf("%d\n", ans);
  printMatrix(z, y, x, maze);

  return(0);
}