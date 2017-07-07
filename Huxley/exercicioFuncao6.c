#include <stdio.h>

int maiorDe3(int num1, int num2, int num3)
{
    if (num1 >= num2 && num1 >= num3)
    {
      return(num1);
    }
    else if (num2 >= num1 && num2 >= num3)
    {
      return(num2);
    }
    else
    {
      return(num3);
    }
}

int main()
{
  int a, b, c; scanf("%d%d%d", &a, &b, &c);
  printf("%d\n", maiorDe3(a, b, c));
  return(0);
}
