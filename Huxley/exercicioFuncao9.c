#include <stdio.h>
#include <string.h>

int convert(char x)
{
  return(x - 32);
}

int main()
{
  char letra; scanf("%c", &letra);
  printf("%c\n", convert(letra));
  return(0);
}
