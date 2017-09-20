#include <stdio.h>

int candidatos(int a[], int cand[], int fim, int *ncand)
{
  int quantidade = 0, i;
  for (i = 1; i <= fim; i ++)
  {
    if (a[i] == 0)
    {
      cand[quantidade] = i;
      quantidade ++;
    }
  }
  (*ncand) = quantidade;
}

void backtrack(int a[], int array[], int i, int fim)
{
  if (i == fim)
  {
    int j;
    for (j = 0; j < fim; j ++)
    {
      printf("%d", a[j]);
    } printf("\n");
    return;
  }
  int numeros, cand[fim], ncand;
  candidatos(a, cand, fim, &ncand);
  for (numeros = 0; numeros < ncand; numeros ++)
  {
    a[cand[i]] = 1;
    array[i] = a[i];
    backtrack(a, array, i + 1, fim);
    a[cand[i]] = 0;
  }
}

int main()
{
  int num; scanf("%d", &num);
  int array[num + 1], a[num + 1];
  memset(a, 0, sizeof, a);
  backtrack(a, array, 0, num);
  return(0);
}
