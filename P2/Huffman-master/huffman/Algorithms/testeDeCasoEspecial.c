#include <stdio.h>

int main()
{
  int i; unsigned long long int n = 1;
  for (i = 65; i < 92; i ++)
  {
    unsigned long long int x;
    for (x = 0; x < n; x ++)
    {
      printf("%c", i);
    }
    n *= 2;
  }
  return(0);
}
