#include <stdio.h>

int main()
{
  int atomicNumber, i; char element[10];
  for (i = 0; i < 118; i ++)
  {
    char name[10];
    sprintf(name, "%d.in", i + 1);
    FILE *pFile = fopen(name, "wb");

    scanf("%d %s\n", &atomicNumber, element);
    fprintf(pFile, "%s %d\n", element, atomicNumber);

    fclose(pFile);
  }
  return(0);
}