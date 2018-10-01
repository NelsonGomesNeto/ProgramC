#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
  int tests, file = 1; scanf("%d", &tests);
  srand(time(NULL));
  while (file <= tests)
  {
    char name[10];
    sprintf(name, "%d.in", file);
    FILE *pFile = fopen(name, "wb");

    int dim = rand() % 6 + 4;
    fprintf(pFile, "%d\n", dim);
    int matrix[dim][dim], i, j;
    for (i = 0; i < dim; i ++)
    {
      for (j = 0; j < dim - 1; j ++)
        fprintf(pFile, "%d ", (rand() - rand()) % 10);
      fprintf(pFile, "%d\n", (rand() - rand()) % 10);
    }

    fclose(pFile);
    file ++;
  }
  return(0);
}