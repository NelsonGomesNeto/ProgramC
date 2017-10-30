#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void printPath(char *path)
{
  int i;
  for (i = 0; path[i] != '\0'; i ++)
    printf("%c%c", path[i], path[i + 1] == '\0' ? '\n' : ' ');
}

void printMatrix(int y, int x, char **mat)
{
  int i;
  for (i = 0; i < y; i ++)
    printf("%s\n", mat[i]);
}

int getDir(int k)
{
  if (k == 0) return('v');
  if (k == 1) return('^');
  if (k == 2) return('>');
  return('<');
}

int getCom(int k)
{
  if (k == 0) return('D');
  if (k == 1) return('U');
  if (k == 2) return('R');
  return('L');
}

int pathFinding(int i, int j, int y, int x, char **maze, int now, char *path)
{
  //printf("%d %d %d\n", i, j, now); fflush(stdout);
  if (i < 0 || j < 0 || i >= y || j >= x || maze[i][j] == '#') return(0);
  if (i == y - 1 && j == x - 1) return(1);
  char aux = maze[i][j];
  maze[i][j] = '#';

  int k, res = 0;
  for (k = 0; k < 4; k ++)
  {
    if (pathFinding(i + dy[k], j + dx[k], y, x, maze, now + 1, path))
    {
      path[now] = getCom(k);
      maze[i][j] = getDir(k);
      return(1);
    }
  }
  if (!res) maze[i][j] = aux;
  return(0);
}

int main()
{
  int y, x; scanf("%d %d", &y, &x);
  char **maze = (char**) malloc(y * sizeof(char*)); int i, j;
  for (i = 0; i < y; i ++)
  {
    maze[i] = (char*) malloc((x + 1) * sizeof(char));
    getchar();
    scanf("%s", maze[i]);
    maze[i][x] = '\0';
  }

  char *path = (char*) malloc((y*x + 1) * sizeof(char)); memset(path, '\0', sizeof(path));
  pathFinding(0, 0, y, x, maze, 0, path);
  printf("done\n");
  maze[y - 1][x - 1] = 'O';

  printMatrix(y, x, maze);
  //printPath(path);

  return(0);
}