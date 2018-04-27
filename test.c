#include <stdio.h>

void printArrayToR(char name[], double array[], int size)
{
  printf("%s = c(", name);
  for (int i = 0; i < size; i ++)
    printf("%lf%c", array[i], i < size - 1 ? ',' : ')');
  printf("\n");
}

int main()
{
  double a[100], mt[100]; int i = 0;
  while (scanf("%lf %lf", &a[i], &mt[i]) != EOF) i ++;

  printArrayToR("mA", a, i);
  printArrayToR("degrees", mt, i);
  return(0);
}