#include <stdio.h>

void printStep(int v[], int start, int end)
{
  int i;
  printf("%d ~~ ", (end - start));
  for (i = start; i < end; i ++)
  {
    printf("%d ", v[i]);
  } printf("\n");
}

int main()
{
  int tam = 0, array[1000];
  while (scanf("%d", &array[tam]) != EOF)
  {
    tam ++;
  }
  printf("Pundim!!!\n");
  int i, j, k, add, aux;
  for (i = 0; i < tam;)
  {
    k = i + 1;
    for (j = k; j < tam; j ++)
    {
      if (array[i] > array[j])
      {
        add = k;
        aux = array[j];
        array[j] = array[i];
        array[i] = aux;
        printf("%d # ", i);
        printStep(array, 0, tam);
      }
      else
      {
        k ++;
      }
    }
    i = add;
    printf("%d %d %d\n", i, k, add);
  }
  printf("%d ~~ ", tam);
  for (i = 0; i < tam; i ++)
  {
    printf("%d ", array[i]);
  } printf("\n");
  //printf("%d steps\n", steps);
  return(0);
}
