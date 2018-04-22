#include <stdio.h>
#include <string.h>

int factorial(int x)
{
  if (x > 1)
  {
    x *= factorial(x - 1);
  }
  return(x);
}

int main()
{
  int num; scanf("%d", &num);
  printf("%d\n", factorial(num));
  return(0);
}
