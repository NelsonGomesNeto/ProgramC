#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int somaHorizontal (int matriz[][3])
{
  int j, i, soma = 0, aux, posi;
  for (i = 0; i < 3; i ++)
  {
    aux = 0;
    for (j = 0; j < 3; j ++)
    {
      aux += matriz[i][j];
    }
    if (aux > soma)
    {
      posi = i;
      soma = aux;
    }
  }
  return(posi);
}

int somaVertical (int matriz[][3])
{
  int j, i, soma = 0, aux, posi;
  for (j = 0; j < 3; j ++)
  {
    aux = 0;
    for (i = 0; i < 3; i ++)
    {
      aux += matriz[i][j];
    }
    if (aux > soma)
    {
      posi = j;
      soma = aux;
    }
  }
  return(posi);
}

int melhorHorizontal (int matriz[][3], int i)
{
  int j, aux = 0, posi;
  for (j = 0; j < 3; j ++)
  {
    if (matriz[i][j] > aux)
    {
      posi = j;
      aux = matriz[i][j];
    }
  }
  return(posi);
}

int melhorVertical (int matriz[][3], int j)
{
  int i, aux = 0, posi;
  for (i = 0; i < 3; i ++)
  {
    if (matriz[i][j] > aux)
    {
      posi = i;
      aux = matriz[i][j];
    }
  }
  return(posi);
}

int main()
{
  FILE *data;
  FILE *dados;
  data = fopen("dadosBrutos.txt", "rw");
  dados = fopen("dadosUteis.txt", "w");
  int num, totalUser = 0, totalUtil = 0; char eleva, peri;
  int apt[10000]; char ele[10000], per[10000];
  int matriz[3][3];
  int i = 0, j = 0;
  for (i = 0; i < 3; i ++)
  {
    for (j = 0; j < 3; j ++)
    {
      matriz[i][j] = 0;
    }
  } i = 0; j = 0;
  int usos = 0;
  int elevadorMaisUsado = 0;
  int turnoMaisUsado = 0;

  while (fscanf(data ,"%d %c %c", &num, &eleva, &peri) != EOF) //Lendo Bruto
  {
    int AA = num / 100, NN = num % 100, j, no = 0;
    totalUser ++;
    if (AA >= 1 && AA <= 20 && NN >= 1 && NN <= 10)
    {
      if (eleva >= 'A' && eleva <= 'C')
      {
        if (peri == 'M' || peri == 'V' || peri == 'N')
        {
          for (j = 0; j < i; j ++)
          {
            if (apt[j] == num)
            {
              no ++;
              break;
            }
          }
          if (no == 0)
          {
            fprintf(dados, "%04d %c %c\n", num, eleva, peri);
            if (eleva == 'A')
            {
              if (peri == 'M')
              {
                matriz[0][0] += 1;
              }
              else if (peri == 'V')
              {
                matriz[0][1] += 1;
              }
              else if (peri = 'N')
              {
                matriz[0][2] += 1;
              }
            }
            else if (eleva == 'B')
            {
              if (peri == 'M')
              {
                matriz[1][0] += 1;
              }
              else if (peri == 'V')
              {
                matriz[1][1] += 1;
              }
              else if (peri = 'N')
              {
                matriz[1][2] += 1;
              }
            }
            else if (eleva == 'C')
            {
              if (peri == 'M')
              {
                matriz[2][0] += 1;
              }
              else if (peri == 'V')
              {
                matriz[2][1] += 1;
              }
              else if (peri = 'N')
              {
                matriz[2][2] += 1;
              }
            }
            apt[i] = num;
            ele[i] = eleva;
            per[i] = peri;
            totalUtil ++;
          }
        }
      }
    }
    i ++;
  }

  printf("Dados encontrados: %d\n", totalUser);

  printf("Dados válidos: %d\n", totalUtil);

  printf("            Matut Vesp Notur\n");

  printf("Elevador A    %02d   %02d    %02d\n", matriz[0][0], matriz[0][1], matriz[0][2]);
  printf("Elevador B    %02d   %02d    %02d\n", matriz[1][0], matriz[1][1], matriz[1][2]);
  printf("Elevador C    %02d   %02d    %02d\n", matriz[2][0], matriz[2][1], matriz[2][2]);

  elevadorMaisUsado = somaHorizontal(matriz);
  printf("Elevador mais usado: %c\n", elevadorMaisUsado + 65);

  int bestTurno = melhorHorizontal(matriz, elevadorMaisUsado);
  char melhorTurno[20];
  if (bestTurno == 0)
  {
    strcpy(melhorTurno, "Matutino");
  }
  else if (bestTurno == 1)
  {
    strcpy(melhorTurno, "Vespertino");
  }
  else
  {
    strcpy(melhorTurno, "Noturno");
  }
  printf("  |- Melhor turno: %s\n", melhorTurno);

  turnoMaisUsado = somaVertical(matriz);
  if (turnoMaisUsado == 0)
  {
    strcpy(melhorTurno, "Matutino");
  }
  else if (turnoMaisUsado == 1)
  {
    strcpy(melhorTurno, "Vespertino");
  }
  else
  {
    strcpy(melhorTurno, "Noturno");
  }
  printf("Turno mais movimentado: %s\n", melhorTurno);

  char melhorElevador = melhorVertical(matriz, turnoMaisUsado) + 65;
  printf("  |- Melhor elevador: %c\n", melhorElevador);

  return(0);
}
