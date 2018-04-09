#include <stdio.h>

void read(int array[], int size)
{
  if (size == 0) return;
  read(array, size - 1);
  scanf("%d", &array[size - 1]);
}

void print(int array[], int size)
{
  if (size == 0) return;
  printf("%d%c", array[size - 1], size - 1 ? ' ' : '\n');
  print(array, size - 1);
}

void swap(int *a, int *b)
{
  int aux = *a;
  *a = *b;
  *b = aux;
}

void sort(int array[], int i, int j, int size)
{
  if (i >= size) return;
  if (j >= size) return(sort(array, i + 1, i + 2, size));
  if (array[i] < array[j]) swap(&array[i], &array[j]);
  sort(array, i, j + 1, size);
}

int main()
{
  int size; scanf("%d", &size);
  int array[size];
  read(array, size);
  print(array, size);

  sort(array, 0, 0, size);

  print(array, size);

  return(0);
}