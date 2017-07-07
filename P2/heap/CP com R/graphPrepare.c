#include "graphPrepare.h"
#include "priorityQueue.h"
#include "heap.h"

void putAbscissaInFile(FILE *pFile, int itens, int precision)
{
  fprintf(pFile, "Itens <- c(");
  int i;
  for (i = 0; i < itens - precision; i += precision)
  {
    fprintf(pFile, "%d,", i);
  } fprintf(pFile, "%d)\n", i);
}

void putRcomands(FILE *pFile, char title[], bool withLimits, int xlim[], int ylim[])
{
  fprintf(pFile, "df <- data.frame(Itens, Comparisons)\n");
  fprintf(pFile, "lo <- loess(Comparisons~Itens)\n");
  fprintf(pFile, "bonito <- rainbow(130, start = 0.4, end = 1)\n");
  if (withLimits)
    fprintf(pFile, "plot(xlim=c(%d,%d), ylim=c(%d,%d), df, col = bonito, type = 'p', pch = 16, cex = .7)\n", xlim[0], xlim[1], ylim[0], ylim[1]);
  else
    fprintf(pFile, "plot(df, col = bonito, type = 'p', pch = 16, cex = .7)\n");
  fprintf(pFile, "lines(Itens, predict(lo), col = \"red\", lwd = 3)\n");
  fprintf(pFile, "title(main=\"%s\")\n", title);
}

void generateGraph(int size, int precision)
{
  PriorityQueue_t *pq = newPriorityQueue();
  Heap_t *heap = createHeap(size, '+');
  srand(time(NULL));

  FILE *enqueuePriorityQueueFile = fopen("rPlotEnqueuePriorityQueue.R", "wb"); // Arquivo do plot
  fprintf(enqueuePriorityQueueFile, "pdf(\"R-EnqueuePriorityQueue.pdf\")\n");
  FILE *dequeuePriorityQueueFile = fopen("rPlotDequeuePriorityQueue.R", "wb"); // Arquivo do plot
  fprintf(dequeuePriorityQueueFile, "pdf(\"R-DequeuePriorityQueue.pdf\")\n");

  FILE *enqueueHeapFile = fopen("rPlotEnqueueHeap.R", "wb"); // Arquivo do plot
  fprintf(enqueueHeapFile, "pdf(\"R-EnqueueHeap.pdf\")\n");
  FILE *dequeueHeapFile = fopen("rPlotDequeueHeap.R", "wb"); // Arquivo do plot
  fprintf(dequeueHeapFile, "pdf(\"R-DequeueHeap.pdf\")\n");

  // Geração do x do gráfico
  putAbscissaInFile(enqueuePriorityQueueFile, size, precision);
  putAbscissaInFile(dequeuePriorityQueueFile, size, precision);
  putAbscissaInFile(enqueueHeapFile, size, precision);
  putAbscissaInFile(dequeueHeapFile, size, precision);

  // Geração do y do gráfico
  fprintf(enqueuePriorityQueueFile, "Comparisons <- c(");
  fprintf(dequeuePriorityQueueFile, "Comparisons <- c(");
  fprintf(enqueueHeapFile, "Comparisons <- c(");
  fprintf(dequeueHeapFile, "Comparisons <- c(");
  int i, j, k = 1;
  int comparesEnqueue = 0, comparesDequeue = 0;
  for (i = 0; i < size; i ++)
  {
    int added = rand();
    enqueuePriorityQueue(pq, added, added); // Enqueues normais
    enqueueHeap(heap, added);

    if (i == k)
    {
      // Testa 20 enqueues e tira a média de comparações
      int mediaEnqueue = 0, mediaDequeue = 0;
      for (j = 0; j < 20; j ++)
      {
        int added = rand();
        comparesEnqueue = enqueuePriorityQueue(pq, added, added);
        comparesDequeue = dequeuePriorityQueue(pq);

        mediaEnqueue += comparesEnqueue;
        mediaDequeue += comparesDequeue;
      }
      mediaEnqueue /= 20;
      mediaDequeue /= 20;

      if (i == size + 1 - precision)
      {
        fprintf(enqueuePriorityQueueFile, "%d)\n", mediaEnqueue);
        fprintf(dequeuePriorityQueueFile, "%d)\n", mediaDequeue);
      }
      else
      {
        fprintf(enqueuePriorityQueueFile, "%d,", mediaEnqueue);
        fprintf(dequeuePriorityQueueFile, "%d,", mediaDequeue);
      }

      mediaEnqueue = 0, mediaDequeue = 0;
      for (j = 0; j < 1000; j ++)
      {
        int added = rand();
        comparesEnqueue = enqueueHeap(heap, added);
        comparesDequeue = dequeueHeap(heap);

        mediaEnqueue += comparesEnqueue;
        mediaDequeue += comparesDequeue;
      }
      mediaEnqueue /= 1000;
      mediaDequeue /= 1000;

      if (i == size + 1 - precision)
      {
        fprintf(enqueueHeapFile, "%d)\n", mediaEnqueue);
        fprintf(dequeueHeapFile, "%d)\n", mediaDequeue);
      }
      else
      {
        fprintf(enqueueHeapFile, "%d,", mediaEnqueue);
        fprintf(dequeueHeapFile, "%d,", mediaDequeue);
      }

      k += precision; // Apenas para não fazer muitas verificações
    }
  }

  destroyPriorityQueue(pq); // Limpando memória
  destroyHeap(heap); // Limpando memória

  // Comandos para gerar gráfico em R
  putRcomands(enqueuePriorityQueueFile, "Enqueue Priority Queue", false, NULL, NULL);
  putRcomands(dequeuePriorityQueueFile, "Dequeue Priority Queue", false, NULL, NULL);
  putRcomands(enqueueHeapFile, "Enqueue Heap", false, NULL, NULL);
  putRcomands(dequeueHeapFile, "Dequeue Heap", false, NULL, NULL);

  fclose(enqueuePriorityQueueFile); // Fechando os arquivos
  fclose(dequeuePriorityQueueFile); // Fechando os arquivos
  fclose(enqueueHeapFile); // Fechando os arquivos
  fclose(dequeueHeapFile); // Fechando os arquivos

  enqueuePriorityQueueFile = fopen("rPlotEnqueuePriorityQueue.R", "rb"); // Abre para gerar a união de gráficos
  dequeuePriorityQueueFile = fopen("rPlotDequeuePriorityQueue.R", "rb"); // Abre para gerar a união de gráficos
  enqueueHeapFile = fopen("rPlotEnqueueHeap.R", "rb"); // Abre para gerar a união de gráficos
  dequeueHeapFile = fopen("rPlotDequeueHeap.R", "rb"); // Abre para gerar a união de gráficos

  // Geração da união de gráficos
  int xlim[2], ylim[2];
  xlim[0] = 0; xlim[1] = size; ylim[0] = 0; ylim[1] = size;
  unifyGraphs(enqueueHeapFile, enqueuePriorityQueueFile, "rPlotEnqueue.R", "R-Enqueue.pdf", "Enqueue", xlim, ylim);
  xlim[0] = 0; xlim[1] = size; ylim[0] = 0; ylim[1] = 20;
  unifyGraphs(dequeueHeapFile, dequeuePriorityQueueFile, "rPlotDequeue.R", "R-Dequeue.pdf", "Dequeue", xlim, ylim);

  fclose(enqueuePriorityQueueFile); // Fechando os arquivos
  fclose(dequeuePriorityQueueFile); // Fechando os arquivos
  fclose(enqueueHeapFile); // Fechando os arquivos
  fclose(dequeueHeapFile); // Fechando os arquivos
}

void unifyGraphs(FILE *heap, FILE *priority, char plotR[], char plotPDF[], char plotTitle[], int xlim[], int ylim[])
{
  FILE *graphFile = fopen(plotR, "wb"); // Arquivo do plot
  fprintf(graphFile, "pdf(\"%s\")\n", plotPDF);

  char trash, jump[1000], itens[100000], compares[100000];
  fscanf(heap, "%[^\n]%c", jump, &trash); // File name
  fscanf(priority, "%[^\n]%c", jump, &trash); // File name

  // Primeiro gráfico
  fscanf(heap, "%[^\n]%c", itens, &trash);
  fprintf(graphFile, "%s\n", itens);
  fscanf(heap, "%[^\n]%c", compares, &trash);
  fprintf(graphFile, "%s\n", compares);

  putRcomands(graphFile, plotTitle, true, xlim, ylim);
  fprintf(graphFile, "par(new=TRUE)\n");


  // Segundo gráfico
  fscanf(priority, "%[^\n]%c", itens, &trash);
  fprintf(graphFile, "%s\n", itens);
  fscanf(priority, "%[^\n]%c", compares, &trash);
  fprintf(graphFile, "%s\n", compares);

  putRcomands(graphFile, plotTitle, true, xlim, ylim);

  fclose(graphFile);
}
