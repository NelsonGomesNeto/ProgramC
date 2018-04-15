#include <stdio.h>

void escreveVetor(int v[], int t)
{
  if (t != 0)
  {
    escreveVetor(v, t - 1);
  }
  printf("Vetor[%d] = %d\n", t, v[t]);
}

int main()
{
  printf("Digite o tamanho do vetor: ");
  int tamanho; scanf("%d", &tamanho);
  int ler, vetor[tamanho];
  for (ler = 0; ler < tamanho; ler ++)
  {
    printf("Vetor[%d] = ", ler + 1);
    scanf("%d", &vetor[ler]);
  }
  escreveVetor(vetor, tamanho - 1);
  return(0);
}
