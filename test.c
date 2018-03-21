#include <stdio.h>

void fpri(double num)
{
  printf("%lf\n", num);
  if (((int)(num*100)) % 10 == 0)
    printf("%.1lf\n", num);
  else
    printf("%.2lf\n", num);
}

int main()
{
  while (1)
  {
    double num; scanf("%lf", &num);
    fpri(num);
  }
  return(0);
}