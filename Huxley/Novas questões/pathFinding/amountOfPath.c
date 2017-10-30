#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DEBUG if(0)
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int exits = 0;

void print(int y, int x, char **maze, int **path)
{
  int i, j;
  for (i = 0; i < y; i ++)
  {
    for (j = 0; j < x; j ++)
    {
      if (path[i][j])
        printf("%d", path[i][j]);
      else
        printf("%c", maze[i][j]);
    }
    printf("\n");
  }
}

void printMatrix(int y, int x, char **mat)
{
  int i;
  for (i = 0; i < y; i ++)
    printf("%s\n", mat[i]);
}

int findExits(int i, int j, int x, int y, char **labyrinth, int **path)
{
  if (i < 0 || j < 0 || i >= y || j >= x || labyrinth[i][j] == '#' || labyrinth[i][j] == '*') return(0);
  if (i == y - 1 && j == x - 1)
  {
    exits ++;
    DEBUG print(y, x, labyrinth, path);
    return(1);
  }

  path[i][j] = path[i][j] != 0 ? path[i][j] : exits + 1;
  int k, res = 0, t;
  for (k = 0; k < 4; k ++)
  {
    labyrinth[i][j] = '*';
    if (findExits(i + dy[k], j + dx[k], x, y, labyrinth, path))
      res = 1;
    labyrinth[i][j] = '.';
  }
  if (!res && path[i][j] == exits + 1) path[i][j] = 0;
  return(res);
}


int main()
{
  int y, x; scanf("%d %d", &y, &x);
  char **labyrinth = malloc(y * sizeof(char**)); int i, j;
  int **path = malloc(y * sizeof(int**));

  for (i = 0; i < y; i ++)
  {
    getchar();
    labyrinth[i] = malloc(y * sizeof(char*));
    path[i] = malloc(y * sizeof(int*));
    for (j = 0; j < x; j ++)
    {
      scanf("%c", &labyrinth[i][j]);
      path[i][j] = 0;
    }
    labyrinth[i][j] = '\0';
  }

  findExits(0, 0, x, y, labyrinth, path);
  exits = 0;
  for (i = 0; i < y; i ++) for (j = 0; j < x; j ++) exits = exits > path[i][j] ? exits : path[i][j];

  printf("%d\n", exits);
  print(y, x, labyrinth, path);

  for (i = 0; i < y; i ++)
  {
    free(labyrinth[i]);
    free(path[i]);
  }
  free(labyrinth); free(path);
  return(0);
}