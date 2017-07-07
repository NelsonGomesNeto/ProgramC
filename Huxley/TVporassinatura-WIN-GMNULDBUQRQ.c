#include <stdio.h>
#include <string.h>

int main()
{
  char tipoass[99], pago[99];
  int convert, canais;
  float preco;
  scanf("%s\n%[^\n]s", &*tipoass, &*pago);
  for (convert = 0; convert < 99; convert ++)
  {
    tipoass[convert] = tolower(tipoass[convert]);
    pago[convert] = tolower(pago[convert]);
  }
  if ((strcmp(tipoass,"básico") == 0) || strcmp(tipoass,"bÁsico") == 0)
  {
    canais = 32;
    if (strcmp(pago,"débito automático") == 0 || strcmp(pago,"dÉbito automático") == 0 || strcmp(pago,"débito automÁtico") == 0 || strcmp(pago,"dÉbito automÁtico") == 0)
    {
      canais += 6;
      preco = 80.8 * 0.95;
    }
    else { preco = 80.8; }
  }
  else if (strcmp(tipoass,"entretenimento") == 0)
  {
    canais = 55;
    if (strcmp(pago,"débito automático") == 0 || strcmp(pago,"dÉbito automático") == 0 || strcmp(pago,"débito automÁtico") == 0 || strcmp(pago,"dÉbito automÁtico") == 0)
    {
      canais += 6;
      preco = 100.4 * 0.95;
    }
    else { preco = 100.4; }
  }
  else
  {
    canais = 112;
    if (strcmp(pago,"débito automático") == 0 || strcmp(pago,"dÉbito automático") == 0 || strcmp(pago,"débito automÁtico") == 0 || strcmp(pago,"dÉbito automÁtico") == 0)
    {
      canais += 11;
      preco = 215.5 * 0.90;
    }
    else { preco = 215.5; }
  }
  printf("%.2f\n%i\n", preco, canais);
  return(0);
}
//Qualquer 112 canais 215.5
//Entretenimento 55 canais 100.4
//Básico 32 canais 80.8
