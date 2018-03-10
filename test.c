#include <stdio.h>

void function(int *b)
{
  int num;
  scanf("%d", &num);
  if (num == 0)
    return;

  if (num > (*b))
    (*b) = num;
  function(&(*b));
}

int main()
{
  int biggest = -999;
  function(&biggest);
  printf("%d\n", biggest);
  return(0);
}