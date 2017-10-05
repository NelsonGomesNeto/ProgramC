#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define valid i + dy[k] >= 0 && i + dy[k] < y && j + dx[k] >= 0 && j + dx[k] < x

int dx[8] = {0, 0, 1, 1, 1, -1, -1, -1};
int dy[8] = {1, -1, 0, 1, -1, 0, 1, -1};

int hasNeighboors(int i, int j, int x, int y, char labyrinth[][x + 1], int visited[][x])
{
  int k;
  for (k = 0; k < 8; k ++)
    if (valid)
      if (!visited[i + dy[k]][j + dx[k]])
        return(1);
  return(0);
}

void createExit(int i, int j, int x, int y, char labyrinth[][x + 1], int visited[][x])
{
  int done = 1;
  visited[i][j] = 1;
  int currI = i, currJ = j;
  int istack[x*y], jstack[x*y], now = 0;
  do
  {
    int tries = 0;
    if (hasNeighboors(currI, currJ, x, y, labyrinth, visited))
    {
      int k;
      do
      {
        k = rand() % 8;
        if (valid)
          if (!visited[currI + dy[k]][currJ + dx[k]])
            break;
        tries ++;
      } while(tries < 100);
      if (tries == 100) break;
      now ++;
      istack[now] = currI;
      jstack[now] = currJ;
      labyrinth[currI][currJ] = '.';
      visited[currI + dy[k]][currJ + dx[k]] = 1;
      currI = currI + dy[k];
      currJ = currJ + dx[k];
      labyrinth[currI][currJ] = '.';
      done += 2;
    }
    else if (now != 0 && tries != 100)
    {
      currI = istack[now];
      currJ = istack[now];
      now --;
    }
  } while (done < x*y);//now != 0);
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

    int y = (rand() % 5) + 6, x = (rand() % 5) + 6, i, j;

    char labyrinth[y][x + 1]; int visited[y][x];
    fprintf(pFile, "%d %d\n", y, x);
    for (i = 0; i < y; i ++)
      for (j = 0; j < x; j ++)
      {
        labyrinth[i][j] = '#';
        visited[i][j] = 0;
      }

    createExit(0, 0, x, y, labyrinth, visited);

    for (i = 0; i < y; i ++)
    {
      for (j = 0; j < x; j ++)
        fprintf(pFile, "%c", labyrinth[i][j]);
      fprintf(pFile, "\n");
    }

    fclose(pFile);
    file ++;
  }
  return(0);
}