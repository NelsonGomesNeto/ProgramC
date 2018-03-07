#include <stdio.h>

int main()
{
  int ddp[100], at = 0; double i[100];
  while (scanf("%dV ->%lf", &ddp[at], &i[at]) != EOF)
    at ++;

  printf("ddp = c(");
  for (int j = 0; j < at; j ++)
    printf("%c%d", j ? ',' : ' ', ddp[j]);
  printf(")\n");
  printf("i = c(");
  for (int j = 0; j < at; j ++)
    printf("%c%lf", j ? ',' : ' ', i[j]);
  printf(")\n");
  return(0);
}