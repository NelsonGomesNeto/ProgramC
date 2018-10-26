#include <stdio.h>

int steps;

void swap(int *a, int *b)
{
  int aux = (*a);
  (*a) = (*b);
  (*b) = aux;
}

void printStep(int *v, int size)
{
  int i;
  printf("%d ~~ ", size);
  for (i = 0; i < size; i ++)
  {
    printf("%d ", v[i]);
  } printf("\n");
}

void marcioQuick(int *a, int size)
{
  if (size < 1) //size devia ser < 1
  {
    return;
  }
  else
  {
    printStep(a, size); steps ++;
    int pivor = a[size / 2]; //Correto
    int start = 0, end = size; //"end = size" e não "end = size - 1"

    while (start <= end) //Correto
    {
      //Foi necessário limitar ambos os whiles
      //Primeiro: start < size
      //Segundo: end > 0
      while (start < size && a[start] < pivor) start ++;
      while (end > 0 && a[end] > pivor) end --;
      if (start <= end)
      {
        //Foi necessário o start ++; end --;
        //Do contrário, iria ficar preso no while
        swap(&a[start], &a[end]); start ++; end --;
      }
    }
    marcioQuick(a, end); //Correto
    marcioQuick(a + start, size - start); //Correto
  }
}

int main()
{
  int i, tam = 0, array[1000];
  while (scanf("%d", &array[tam]) != EOF)
  {
    tam ++;
  }
  steps = 0;
  marcioQuick(array, tam - 1);
  printf("%d ~~ ", tam);
  for (i = 0; i < tam; i ++)
  {
    printf("%d ", array[i]);
  } printf("\n");
  printf("%d steps\n", steps);
  return(0);
}
