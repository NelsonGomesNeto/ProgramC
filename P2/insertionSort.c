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
  int i, j, key;
  for (i = 1; i < tam; i ++)
  {
    key = array[i]; j = i - 1;
    while (j >= 0 && key > array[j])
    {
      array[j + 1] = array[j]; j --;
    }
    array[j + 1] = key;
    printStep(array, 0, tam);
  }
  printf("%d ~~ ", tam);
  for (i = 0; i < tam; i ++)
  {
    printf("%d ", array[i]);
  } printf("\n");
  //printf("%d steps\n", steps);
  return(0);
}
