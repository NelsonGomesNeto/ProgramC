#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
char freePlace = '.';
int dx[6] = {0, 0, 0, 0, 1, -1};
int dy[6] = {1, -1, 0, 0, 0, 0};
int dz[6] = {0, 0, 1, -1, 0, 0};

void printMatrix(int z, int y, int x, char ***mat, FILE *pFile, int c)
{
  int i, j;
  for (i = 0; i < z; i ++)
  {
    for (j = 0; j < y; j ++)
    {
      if (c) printf("%s\n", mat[i][j]);
      fprintf(pFile, "%s\n", mat[i][j]);
    }
    if (i < z - 1)
    {
      if (c) printf("\n");
      fprintf(pFile, "\n");
    }
  }
}

int valid(int i, int j, int k, int z, int y, int x)
{
  return(!(i < 0 || j < 0 || k < 0 || i >= z || j >= y || k >= x));
}

void generate(int i, int j, int k, int z, int y, int x, char ***maze, int ***visited)
{
  if (!valid(i, j, k, z, y, x)) return;
  if (i == z-1 && j == y-1 && k == x-1) return;

  visited[i][j][k] = 1;
  int n, all;
  for (n = rand(), all = 0; all < 6; n ++, all ++)
  {
    n %= 6;
    if (valid(i + 2*dz[n], j + 2*dy[n], k + 2*dx[n], z, y, x) && !visited[i + 2*dz[n]][j + 2*dy[n]][k + 2*dx[n]])
    {
      maze[i][j][k] = freePlace;
      maze[i + dz[n]][j + dy[n]][k + dx[n]] = freePlace;
      visited[i + dz[n]][j + dy[n]][k + dx[n]] = 1;
      maze[i + 2*dz[n]][j + 2*dy[n]][k + 2*dx[n]] = freePlace;
      visited[i + 2*dz[n]][j + 2*dy[n]][k + 2*dx[n]] = 1;
      generate(i + 2*dz[n], j + 2*dy[n], k + 2*dx[n], z, y, x, maze, visited);
    }
  }
}

int main()
{
  srand(time(NULL));
  int now = 1, quantity = 1; scanf("%d", &quantity);
  while (now <= quantity)
  {
    char name[10]; sprintf(name, "./testCases/%d.in", now);
    FILE *pFile = fopen(name, "wb");

    int z = 2*((int)(16 * ((double)now / quantity))) + 2*(rand() % (int)(1 + 16 * ((double)now / quantity)))+3;
    int y = 2*((int)(16 * ((double)now / quantity))) + 2*(rand() % (int)(1 + 16 * ((double)now / quantity)))+3;
    int x = 2*((int)(16 * ((double)now / quantity))) + 2*(rand() % (int)(1 + 16 * ((double)now / quantity)))+3;
    int i, j, k;
    printf("%d %d %d\n", z, y, x);
    fprintf(pFile, "%d %d %d\n", z, y, x);

    char ***maze = (char***) malloc(z * sizeof(char**));
    int ***visited = (int***) malloc(z * sizeof(int**));
    for (i = 0; i < z; i ++)
    {
      maze[i] = (char**) malloc(y * sizeof(char*));
      visited[i] = (int**) malloc(y * sizeof(int*));
      for (j = 0; j < y; j ++)
      {
        maze[i][j] = (char*) malloc((x + 1) * sizeof(char));
        visited[i][j] = (int*) malloc(x * sizeof(int));
      }
    }

    for (i = 0; i < z; i ++)
      for (j = 0; j < y; j ++)
      {
        for (k = 0; k < x; k ++)
        {
          maze[i][j][k] = '#';
          visited[i][j][k] = 0;
        }
        maze[i][j][x] = '\0';
      }

    generate(0, 0, 0, z, y, x, maze, visited);

    printMatrix(z, y, x, maze, pFile, 0);

    free(maze); free(visited);
    fclose(pFile);
    now ++;
  }
  return(0);
}