#include <stdio.h>

int main()
{
  int jogos, run = 1;
  while (scanf("%d", &jogos) && jogos != 0)
  {
    if (run > 1)
    {
      printf("\n");
    }
    int saldo[jogos], a, b, ler;
    for (ler = 0; ler < jogos; ler ++)
    {
      scanf("%d %d", &a, &b);
      saldo[ler] = a - b;
    }
    int Xi = 1, from = 1, Xf = 1, to = 1, atual = 0, prev = 0;
    for (ler = 0; ler < jogos; ler ++)
    {
      if (atual + saldo[ler] >= 0)
      {
        atual += saldo[ler];66
      }
    }
    printf("Teste %d\n", run);
    if (Xi > Xf)
    {
      printf("nenhum\n");
    }
    else
    {
      printf("%d %d\n", Xi, Xf);
    }
    run ++;
  }
  return(0);
}
