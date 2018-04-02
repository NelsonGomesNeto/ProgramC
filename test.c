#include <stdio.h>

void printToR(double a[], int size, char name[])
{
  printf("%s = c(", name);
  for (int i = 0; i < size; i ++)
    printf("%lf%s", a[i], i < size - 1 ? ", " : ")\n");
}

int main()
{
  double u[1000], t[1000]; int i = 0;
  while (scanf("%lf%lf", &u[i], &t[i]) != EOF) i ++;

  printToR(u, i, "ddp");
  printToR(t, i, "time");

  return(0);
}