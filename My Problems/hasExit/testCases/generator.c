#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int max(int a, int b)
{
  return(a > b ? a : b);
}

int findExit(int i, int j, int x, int y, char labyrinth[][x + 1])
{
  if (i < 0 || j < 0 || i >= y || j >= x) return(0);
  if (labyrinth[i][j] == '#') return(0);
  if (i == y - 1 && j == x - 1) return(1);

  int k;
  for (k = 0; k < 4; k ++)
  {
    labyrinth[i][j] = '#';
    if (findExit(i + dy[k], j + dx[k], x, y, labyrinth))
    {
      labyrinth[i][j] = '.';
      return(1);
    }
    labyrinth[i][j] = '.';
  }

  return(0);
}

int lose = 0, win = 0;
void createExit(int y, int x, char labyrinth[][x + 1])
{
  int i, j, wice = 0;
  while (wice < (y * x) / 5)
  {
    i = (rand() % y), j = (rand() % x);
    if ((i == 0 && j == 0) || (i == y - 1 && j == x - 1)) continue;
    labyrinth[i][j] = '#';
    if (!findExit(0, 0, x, y, labyrinth))
    {
      labyrinth[i][j] = '.';
      wice += 1;
    }
  }
  if (rand() - rand() >= 0)
  {
    labyrinth[i][j] = '.';
    win ++;
  }
  else
  {
    labyrinth[i][j] = '#';
    lose ++;
  }
}

int main()
{
  int tests, file = 1; scanf("%d", &tests);
  srand(time(NULL));
  while (file <= tests)
  {
    char name[10];
    sprintf(name, "%d.in", file);
    FILE *pFile = fopen(name, "wb");

    int y = (rand() % 5) + 4, x = (rand() % 5) + 4, i, j;

    char labyrinth[y][x + 1];
    fprintf(pFile, "%d %d\n", y, x);
    for (i = 0; i < y; i ++)
      for (j = 0; j < x; j ++)
      {
        labyrinth[i][j] = '.';
      }

    //printf("%d\n", file);
    createExit(y, x, labyrinth);

    for (i = 0; i < y; i ++)
    {
      for (j = 0; j < x; j ++)
        fprintf(pFile, "%c", labyrinth[i][j]);
      fprintf(pFile, "\n");
    }

    fclose(pFile);
    file ++;
  }
  printf("%d %d\n", win, lose);

  return(0);
}