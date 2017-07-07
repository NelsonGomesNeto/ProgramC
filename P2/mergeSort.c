#include <stdio.h>
#include <stdlib.h>

int steps;

void printStep(int v[], int start, int end)
{
  int i;
  printf("%d ~~ ", (end - start));
  for (i = start; i < end; i ++)
  {
    printf("%d ", v[i]);
  } printf("\n");
}

void merge(int v[], int start, int mid, int end)
{
  steps ++;
  int sizeA = mid - start + 1;
  int sizeB = end - mid;
  int i, j;
  int *A = malloc((sizeA + 1) * sizeof(int));
  int *B = malloc((sizeB + 1) * sizeof(int));

  for (i = start, j = 0; j < sizeA; i ++, j ++)
  {
    A[j] = v[i];
  } A[j] = 9999999;
  for (i = mid + 1, j = 0; j < sizeB; i ++, j ++)
  {
    B[j] = v[i];
  } B[j] = 9999999;

  printStep(A, 0, sizeA);
  printStep(B, 0, sizeB);

  int k; i = 0; j = 0;
  for (k = start; k <= end; k ++)
  {
    if (A[i] <= B[j])
    {
      v[k] = A[i]; i ++;
    }
    else
    {
      v[k] = B[j]; j ++;
    }
  }
  printStep(v, start, end + 1);
  printf("\n");
  free(A); free(B);
}

void mergeSort(int a[], int start, int end)
{
  if (start < end)
  {
    int mid = (end + start) / 2;
    mergeSort(a, start, mid);
    mergeSort(a, mid + 1, end);
    merge(a, start, mid, end);
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
  mergeSort(array, 0, tam - 1);

  printf("%d ~~ ", tam);
  for (i = 0; i < tam; i ++)
  {
    printf("%d ", array[i]);
  } printf("\n");
  printf("%d steps\n", steps);
  return(0);
}
