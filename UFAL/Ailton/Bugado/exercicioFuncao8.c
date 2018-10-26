#include <stdio.h>

int check(int x)
{
  if (x > 0)
  {
    return(0);
  }
  else
  {
    return(1);
  }
}

int main()
{
  int a; scanf("%d", &a);
  printf("%d\n", check(a));
  return(0);
}
