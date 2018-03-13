#include <stdio.h>

int function(int i)
{
  if (i == 0)
    return(0);
  return(i + function(i - 1));
}

int main()
{
  printf("%d\n", function(3));
  return(0);
}