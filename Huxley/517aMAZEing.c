#include <stdio.h>
#define DEBUG if(0)
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
// DO IT WITH UNION FIND!!! 
void printMatrix(int size, char m[][size + 1])
{
  int i, j;
  for (i = 0; i < size; i ++)
  {
    for (j = 0; j < size; j ++)
      printf("%c", m[i][j]);
    printf("\n");
  }
}

int has;

void hasExit(int i, int j, int size, char maze[][size + 1])
{
  if (has) return;
  if (i < 0 || j < 0 || i >= size || j >= size) return;
  if (maze[i][j] == '#') return;
  if (maze[i][j] == 'e') { has = 1; return; }

  int k;
  for (k = 0; k < 4; k ++)
  {
    maze[i][j] = '#';
    hasExit(i + dy[k], j + dx[k], size, maze);
    maze[i][j] = '.';
  }
}

int main()
{
  int size, walls, queries, run = 0;
  while (scanf("%d %d %d", &size, &walls, &queries) != EOF)
  {
    if (run == 1) printf("\n");

    size = (2 * size) - 1;
    char maze[size][size + 1];
    int i, j, k = 1;
    for (i = 0; i < size; i ++)
    {
      for (j = k; j < size; j += 2)
        maze[i][j] = '#';
      k = 1 - k;
    }
    //DEBUG { printMatrix(size, maze); printf("\n"); }

    int wall;
    for (i = 0; i < walls; i ++)
    {
      scanf("%d", &wall);
      DEBUG printf("%d %d\n", (2*wall + 1) / size, (2*wall + 1) % size);
      maze[(2*wall + 1) / size][(2*wall + 1) % size] = '.';
    }
    DEBUG printMatrix(size, maze);

    int start, end;
    for (i = 0; i < queries; i ++)
    {
      scanf("%d %d", &start, &end);
      DEBUG printf("%d %d %d %d\n", (2*start) / size, (2*start) % size, (2*end) / size, (2*end) % size);
      //maze[(2*start) / size][(2*start) % size] = 's';
      maze[(2*end) / size][(2*end) % size] = 'e';
      has = 0; hasExit((2*start) / size, (2*start) % size, size, maze);
      printf("%d.%d\n", i + 1, has);
      maze[(2*end) / size][(2*end) % size] = '.';
    }
    run = 1;
  }

  return(0);
}