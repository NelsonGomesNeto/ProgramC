#include <stdio.h>
#include <string.h>

#define x tolower(palavra[print])

void printarVogais(char palavra[], int tam)
{
  int print;
  for (print = 0; print < tam; print ++)
  {
    if (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u')
    {
      printf("%c", palavra[print]);
    }
  }
  printf("\n");
}

int main()
{
  int tamanho; scanf("%d", &tamanho);
  char string[tamanho];
  getchar();
  scanf("%[^\n]", string);
  printarVogais(string, tamanho);
  return(0);
}
