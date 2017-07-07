#include <stdio.h>

void printarPar(int numeros[], int tam)
{
  int print;
  for (print = 0; print < tam; print ++)
  {
    if (numeros[print] % 2 == 0)
    {
      printf("%d\n", numeros[print]);
    }
  }
}

int main()
{
  int ler, tamanho; scanf("%d", &tamanho);
  int array[tamanho];
  for (ler = 0; ler < tamanho; ler ++)
  {
    scanf("%d", &array[ler]);
  }
  printarPar(array, tamanho);
  return(0);
}
