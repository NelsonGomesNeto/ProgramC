#ifndef GRAPHPREPARE_H
#define GRAPHPREPARE_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void putAbscissaInFile(FILE *pFile, int itens, int precision);
void putRcomands(FILE *pFile, char title[], bool withLimits, int xlim[], int ylim[]);

void generateGraph(int size, int precision);

void unifyGraphs(FILE *heap, FILE *priority, char plotR[], char plotPDF[], char plotTitle[], int xlim[], int ylim[]);

#endif //GRAPHPREPARE_H
