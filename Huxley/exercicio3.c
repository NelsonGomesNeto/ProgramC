#include <stdio.h>
#include <string.h>

void printarInverso(char palavra[], int tam)
{
  int print;
  for (print = tam - 1; print >= 0; print --)
  {
    printf("%c", palavra[print]);
  }
  printf("\n");
}

int main()
{
  int tamanho; scanf("%d", &tamanho);
  char string[tamanho];
  getchar();
  scanf("%[^\n]", string);
  printarInverso(string, tamanho);
  return(0);
}
