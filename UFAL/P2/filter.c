#include <stdio.h>
#include <stdlib.h>

int tam = 10; //Tamanho do array

int * filter(int (*check)(int), int a[])
{
  int i, j = 1, *newArray = malloc(2 * sizeof(int)), new;
  newArray[0] = 1; //Tamanho do array
  for (i = 0; i < tam; i ++)
  {
    new = (*check)(a[i]);
    if (new != -1)
    {
      newArray[j] = new;
      newArray[0] ++; j ++;
      newArray = realloc(newArray, (j + 1) * sizeof(int));
    }
  }
  return(newArray);
}

int even(int num)
{
  if (!(num & 1 == 1))
    return(num);
  return(-1);
}

int odd(int num)
{
  if (num & 1 == 1)
    return(num);
  return(-1);
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
  int *pares = filter(even, array);
  int *impares = filter(odd, array);
  printar(pares);
  printar(impares);
  return(0);
}
