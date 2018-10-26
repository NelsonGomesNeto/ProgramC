#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int matriz[7][7];

int tempoPercurso(char trip[])
{
  int i, tempo = 0;
  for (i = 0; trip[i + 1] != '\0'; i ++)
  {
    if (matriz[trip[i + 1] - 65][trip[i] - 65] == 0)
    {
      tempo += matriz[trip[i] - 65][trip[i + 1] - 65];
    }
    else
    {
      tempo += matriz[trip[i + 1] - 65][trip[i] - 65];
    }
  }
  return(tempo);
}

int pesquisaDescanso(int metadeTempo, char trip[])
{
  int i, tempo = 0, best = 99999, posi;
  for (i = 0; trip[i + 1] != '\0'; i ++)
  {
    if (matriz[trip[i + 1] - 65][trip[i] - 65] == 0)
    {
      tempo += matriz[trip[i] - 65][trip[i + 1] - 65];
    }
    else
    {
      tempo += matriz[trip[i + 1] - 65][trip[i] - 65];
    }
    //printf("%d\n", (int) abs(metadeTempo - tempo));
    if (i == 0 || (int) abs(metadeTempo - tempo) <= best)
    {
      posi = i;
      best = abs(metadeTempo - tempo);
    }
  }
  return(posi);
}

int main()
{
  FILE *percursos = fopen("percursos.txt", "r");
  FILE *tempos = fopen("tempos.txt", "r");
  int fim = 1, i = 1, j = 0;
  for (i = 0; i < 7; i ++)
  {
    for (j = 0; j < 7; j ++)
    {
      matriz[i][j] = 0;
    }
  }
  i = 1; j = 0;
  while (fscanf(tempos, "%d", &matriz[i][j]) != EOF)
  {
    for (j = 1; j < fim; j ++)
    {
      fscanf(tempos, "%d", &matriz[i][j]);
    }
    i ++; j = 0; fim ++;
  }
  i = 0;
  char percurso[1000];
  while (fscanf(percursos, "%s", percurso) != EOF)
  {
    int tempo = tempoPercurso(percurso);
    printf("Percurso: '%s', tempo %dh", percurso, tempo);
    if (strlen(percurso) > 2)
    {
      int where = pesquisaDescanso(tempo / 2, percurso) + 1;
      printf(", opcao de descanso: Cidade '%c'", percurso[where]);
    }
    printf("\n");
    i ++;
  }
  return(0);
}
