#include <stdio.h>

int conta = 1;

int digitos(int numero)
{
  if (numero > 9)
  {
    conta ++;
    digitos(numero/10);
  }
  return(conta);
}

int main()
{
  int num;
  while (scanf("%d", &num) && ((char) num != 110 || (char) num != 78))
  {
    conta = 1;
    printf("%d\n", digitos(num));
  }
  return(0);
}
