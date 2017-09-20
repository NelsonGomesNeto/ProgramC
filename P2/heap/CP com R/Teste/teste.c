#include <stdio.h>

int main()
{
  int itens[100], i;
  for (i = 0; i < 100; i ++)
    itens[i] = i;

  double y[100];
  for (i = 0; i < 100; i ++)
    y[i] = (itens[i] * itens[i] * itens[i]);

  FILE *pFile = fopen("rPlot.R", "wb");

  fprintf(pFile, "itens <- c(");
  for (i = 0; i < 100 - 1; i ++)
    fprintf(pFile, "%d,", itens[i]);
  fprintf(pFile, "%d)\n", itens[i]);

  fprintf(pFile, "tempo <- c(");
  for (i = 0; i < 100 - 1; i ++)
    fprintf(pFile, "%g,", y[i]);
  fprintf(pFile, "%g)\n", y[i]);

  fprintf(pFile, "df <- data.frame(itens, tempo)\n");
  fprintf(pFile, "bonito <- rainbow(12, start = 0, end = 1)\n");
  fprintf(pFile, "plot(df, col = bonito, type = 'o', pch = 16, cex = 1)\n");

  fclose(pFile);
  return(0);
}
/*
y.loess <- loess(tempo~itens, span=0.8, data.frame(x=itens,y=tempo))
y.predict <- predict(y.loess, data.frame(x=itens))

lines(itens,y.predict, col=bonito, lwd=2)

*/
