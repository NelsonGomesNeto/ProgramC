#include <stdio.h>
#include <stdlib.h>

int tam = 10; //Tamanho do array

int * map(int (*change)(int), int a[])
{
  int i, j = 1, *newArray = malloc(2 * sizeof(int));
  newArray[0] = 1; //Tamanho do array
  for (i = 0; i < tam; i ++)
  {
    newArray[j] = (*change)(a[i]);
    newArray[0] ++; j ++;
    newArray = realloc(newArray, (j + 1) * sizeof(int));
  }
  return(newArray);
}

int square(int num)
{
  return(num * num);
}

int factorial(int num)
{
  if (num < 1) { return(1); }
  num *= factorial(num - 1);
  return(num);
}

void printar(int a[])
{
  int i;
  for (i = 1; i < a[0]; i ++)
  {
    printf("%d ", a[i]);
  } printf("\n");
  return;
}

int main()
{
  int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int *quadrado = map(square, array);
  int *fatorial = map(factorial, array);
  printar(quadrado);
  printar(fatorial);
  return(0);
}
