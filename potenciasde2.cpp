#include <stdio.h>

int main()
{
  int num;
  while (scanf("%d", &num) != EOF)
  {
    printf("%d\n", (num & (num - 1)));
    if ((num & (num - 1)) == 0 && num != 0)
    {
      printf("Yep\n");
    }
    else
    {
      printf("Nope\n");
    }
  }
  return(0);
}
