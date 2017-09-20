#include "progressBar.h"

void updateProgress(char string[], int porcentage, bool cleaning)
{
  printf("\r");
  printf("%s%3d%% [", string, porcentage);

  // Filling Progress Bar
  int progress = porcentage / 10;
  int i;
  for (i = 0; i < progress; i ++)
    printf("#");
  for (i = progress; i < 10; i ++)
    printf(" ");

  if (cleaning)
    printf("]\n\033[F\033[J");
  else
    printf("]\n\n");
}

long long int* createProgressBar(FILE *pFile)
{
  fseek(pFile, 0, SEEK_END);
  long double fileSize = ftell(pFile);
  rewind(pFile);

  long long int *porcentageBar = (long long int*) malloc(100 * sizeof(long long int)), fill;
  for (fill = 0; fill < 100; fill ++)
    porcentageBar[fill] = ((double) fill / 100) * fileSize;

  return(porcentageBar);
}
