#include <stdio.h>
long int pivor[9999];
void Quick(long int vetor[], int inicio, int fim){
  int pivo, aux, i, j, meio, c = 0;
  i = inicio;
  j = fim;
  meio = (int) ((i + j) / 2);
  pivo = vetor[meio];
  pivor[c] = pivo;
  do{
    while (vetor[i] < pivo) i = i + 1;
    while (vetor[j] > pivo) j = j - 1;
    if(i <= j){
      aux = vetor[i];
      vetor[i] = vetor[j];
      vetor[j] = aux;
      i = i + 1;
      j = j - 1;
    }
  }while(j > i);
  c ++;
  if(inicio < j) {Quick(vetor, inicio, j);}
  if(i < fim) {Quick(vetor, i, fim);}
}

int main()
{
  long int tam, seed, a, c, m, put;
  scanf("%ld %ld %ld %ld %ld", &tam, &seed, &a, &c, &m);
  long int array[tam];// pivor[tam];
  array[0] = seed;
  for (put = 1; put < tam; put ++)
  {
    array[put] = (a * array[put - 1] + c) % m;
  }
  Quick(array, 0, tam - 1);
  for (put = 0; put < tam; put ++)
  {
    printf("%ld ", pivor[put]);
  }
  printf("\n");
  for (put = 0; put < tam; put ++)
  {
    printf("%ld ", array[put]);
  }
  printf("\n");
  /*for (put = 0; put < tam; put ++)
  {
    printf("%ld\n", pivor[put]);
  }*/
  return(0);
}
