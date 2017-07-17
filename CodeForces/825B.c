#include <stdio.h>

int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {0, -1, 1, -1, 1, -1, 1, 0};

int tryflood(char t[][12], int i, int j)
{
  int k, m, y, x;
  for (k = 0; k < 8; k ++)
  {
    y = i; x = j;
    int win = 0, freeSpaces = 0;
    for (m = 0; m < 5; m ++)
      if (y + dy[k] >= 0 && y + dy[k] <= 11
        && x + dx[k] >= 0 && x + dx[k] <= 11)
      {
        if (t[y][x] == 'X')
          win ++;
        if (t[y][x] == '.')
          freeSpaces ++;

        y += dy[k]; x += dx[k];
      }

    if (win == 4 && freeSpaces == 1)
      return(1);
  }
  return(0);
}

int main()
{
  char table[12][12];
  int i, j;
  for (i = 1; i < 11; i ++)
  {
    for (j = 1; j < 11; j ++)
      scanf("%c", &table[i][j]);
    getchar();
  }

  for (i = 1; i < 11; i ++)
    for (j = 1; j < 11; j ++)
      if (table[i][j] == 'X')
        if (tryflood(table, i, j))
        {
          printf("YES\n");
          return(0);
        }

  printf("NO\n");
  return(0);
}
