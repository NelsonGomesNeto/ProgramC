#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void printMatrix(int y, int x, char **mat, FILE *pFile)
{
  int i;
  for (i = 0; i < y; i ++)
    fprintf(pFile, "%s\n", mat[i]);
}

int valid(int i, int j, int y, int x)
{
  return(!(i < 0 || j < 0 || i >= y || j >= x));
}

void generate(int i, int j, int y, int x, char **maze, int **visited)
{
  if (!valid(i, j, y, x)) return;
  if (i == y-1 && j == x-1) return;

  visited[i][j] = 1;
  int k, all;
  for (k = rand(), all = 0; all < 4; k ++, all ++)
  {
    k %= 4;
    if (valid(i + 2*dy[k], j + 2*dx[k], y, x) && !visited[i + 2*dy[k]][j + 2*dx[k]])
    {
      maze[i][j] = '.';
      maze[i + dy[k]][j + dx[k]] = '.';
      visited[i + dy[k]][j + dx[k]] = 1;
      maze[i + 2*dy[k]][j + 2*dx[k]] = '.';
      visited[i + 2*dy[k]][j + 2*dx[k]] = 1;
      generate(i + 2*dy[k], j + 2*dx[k], y, x, maze, visited);
    }
  }
}

int main()
{
  srand(time(NULL));
  int now = 1, quantity; scanf("%d", &quantity);
  while (now <= quantity)
  {
    char name[10]; sprintf(name, "./testCases/%d.in", now);
    FILE *pFile = fopen(name, "wb");

    int y = 999;//2*(125 * ((double)now / quantity)) + 2*(rand() % (int)(1 + 125 * ((double)now / quantity)))+1;
    int x = 999;//2*(125 * ((double)now / quantity)) + 2*(rand() % (int)(1 + 125 * ((double)now / quantity)))+1;;
    int i, j;
    printf("%d %d\n", y, x);
    fprintf(pFile, "%d %d\n", y, x);

    char **maze = (char**) malloc(y * sizeof(char**));
    int **visited = (int**) malloc(y * sizeof(int**));
    for (i = 0; i < y; i ++)
    {
      maze[i] = (char*) malloc((x + 1) * sizeof(char*));
      visited[i] = (int*) malloc(x * sizeof(int*));
    }

    for (i = 0; i < y; i ++)
    {
      for (j = 0; j < x; j ++)
      {
        maze[i][j] = '#';
        visited[i][j] = 0;
      }
      maze[i][x] = '\0';
    }

    generate(0, 0, y, x, maze, visited);

    printMatrix(y, x, maze, pFile);

    for (i = 0; i < y; i ++)
    {
      free(maze[i]);
      free(visited[i]);
    }
    free(maze); free(visited);
    fclose(pFile);
    now ++;
  }
  return(0);
}