#include <stdio.h>
#include <string.h>

struct caminhao
{
  long int peso, atual, itens;
  long int cargas[10000];
};

struct galpao
{
  long int item;
};

int main()
{
  int caminhoes; int running = 0, run;
  scanf("%d", &caminhoes);
  do
  {
    run = 0;
    if (running > 0)
    {
      printf("\n");
    }
    running ++;
    int ler;
    struct caminhao c[caminhoes + 10];
    int j[caminhoes + 10];
    struct galpao g[10000];
    for (ler = 0; ler < caminhoes; ler ++)
    {
      c[ler].atual = 0; c[ler].itens = 0;
      j[ler] = 0;
      scanf("%ld", &c[ler].peso);
    }
    char comando[99]; long int num; int i = 0;
    long int pesoAtual = 0;
    while (getchar() && scanf("%s", comando) != EOF && comando[0] >= 'A')
    {
      scanf("%ld", &num);
      if (strcmp(comando, "ADD") == 0)
      {
        g[i].item = num; i ++;
        pesoAtual += num;
        printf("%d %ld\n", i, pesoAtual);
      }
      else if (strcmp(comando, "LOA") == 0)
      {
        int ga = 0;
        while (c[num].atual + g[ga].item <= c[num].peso && ga < i)
        {
          c[num].atual += g[ga].item;
          c[num].itens += 1;
          c[num].cargas[j[num]] = g[ga].item;
          pesoAtual -= g[ga].item;
          g[ga].item = 0;
          j[num] ++;
          ga ++;
        }
        if (pesoAtual < 0 || ga >= i)
        {
          pesoAtual = 0;
        }
        else
        {
          int p, aux = ga;
          for (p = aux, ga = 0; ga < aux; ga ++, p ++)
          {
            g[ga].item = g[p].item;
          }
          for (p = 0; p < i; p ++)
          {
            //printf("%ld\n", g[p].item);
          }
        }
        i -= ga;
        if (i < 0)
        {
          i = 0;
        }
        printf("%ld %ld\n", num, c[num].itens);
      }
      else if (strcmp(comando, "DEL") == 0)
      {
        j[num] --;
        c[num].atual = c[num].atual - c[num].cargas[j[num]];
        c[num].cargas[j[num]] = 0;
        c[num].itens -= 1;
        printf("%ld %ld\n", num, c[num].itens);
      }
      else if (strcmp(comando, "INF") == 0)
      {
        int ja = 0, total = 0;
        for (ja = 0; ja < j[num]; ja ++)
        {
          total += c[num].cargas[ja];
        }
        //printf("%d\n", total);
        printf("%ld %ld %ld\n", num, c[num].itens, c[num].atual);
      }
      int k;
      for (k = 0; k < 4; k ++)
      {
        comando[k] = '\0';
      }
    }
    if (atoi(comando) > 0)
    {
      run = 1;
    }
    else
    {
      run = 0;
    }
    caminhoes = atoi(comando);
  } while(run == 1);
  return(0);
}
