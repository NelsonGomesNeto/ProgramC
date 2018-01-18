#include <stdio.h>


int main()
{
  double phi = 1.61803398875, b; int i;
  b = phi;
  for (i = 0; i < 8; i ++)
  {
    printf("%d %lf\n", i + 1, phi);
    phi *= b;
  }
}