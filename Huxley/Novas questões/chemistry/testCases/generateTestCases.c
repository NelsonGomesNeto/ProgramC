#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
  int atomicNumber, i; char element[10];
  srand(time(NULL));
  for (i = 0; i < 118; i ++)
  {
    char name[10];
    sprintf(name, "%d.in", i + 1);
    FILE *pFile = fopen(name, "wb");
    int y = (rand() % 10) + 1, x = (rand() % 10) + 1, now = 0, i, j;
    fprintf(pFile, "%d %d\n", y, x);

    scanf("%d %s", &atomicNumber, element);

    for (i = 0; i < y; i ++)
    {
      int limit = (rand() % x) + 1;
      fprintf(pFile, "%d ", limit);
      for (j = 0; j < limit; j ++)
      {
        int value = (rand() % y) + 1; char let = (rand() % 26) + 'a'; int toSum = (rand() % 14) + 1;
        if (i == y - 1 && j == limit - 1 && now + toSum < atomicNumber)
          toSum = atomicNumber - now + 1;
        fprintf(pFile, "%d%c(%d)%c", value, let, toSum, j < limit - 1 ? ' ' : '\n');
        now += toSum;
      }
    }

    fprintf(pFile, "%s %d\n", element, atomicNumber);

    fclose(pFile);
  }
  return(0);
}