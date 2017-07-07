#include <stdio.h>

int steps;

void swap(int *a, int *b)
{
  int aux = (*a);
  (*a) = (*b);
  (*b) = aux;
}

void printStep(int v[], int start, int end)
{
  int i;
  printf("%d ~~ ", (end - start));
  for (i = start; i < end; i ++)
  {
    printf("%d ", v[i]);
  } printf("\n");
}

void quickSort(int a[], int start, int end)
{
  if (end - start < 1)
  {
    return;
  }
  else
  {
    printStep(a, start, end); steps ++;
    int mid = (start + end) / 2;
    int pivor = a[mid];
    int first = start, last = end;
    while (first <= last)
    {
      while (first < end && a[first] < pivor) first ++;
      while (last > start && a[last] > pivor) last --;
      if (first <= last)
      {
        swap(&a[first], &a[last]); first ++; last --;
      }
    }
    quickSort(a, start, last);
    quickSort(a, first, end);
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
  quickSort(array, 0, tam - 1);
  printf("%d ~~ ", tam);
  for (i = 0; i < tam; i ++)
  {
    printf("%d ", array[i]);
  } printf("\n");
  printf("%d steps\n", steps);
  return(0);
}
