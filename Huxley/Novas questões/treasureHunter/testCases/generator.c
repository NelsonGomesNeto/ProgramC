#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char blocks[10] = {'#', '#', '#', '.', 'b', 'p', 'o', 'd'};

char generateBlock()
{
  int value = rand() % 8;
  return(blocks[value]);
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

    int y = (rand() % 5) + 6, x = (rand() % 5) + 6;
    fprintf(pFile, "%d %d\n", y, x);
    char field[y][x], i, j;
    for (i = 0; i < y; i ++)
    {
      for (j = 0; j < x; j ++)
        fprintf(pFile, "%c", generateBlock());
      fprintf(pFile, "\n");
    }

    fclose(pFile);
    file ++;
  }
  return(0);
}