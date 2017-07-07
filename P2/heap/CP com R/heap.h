#ifndef HEAP_H
#define HEAP_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>
#include <time.h>

typedef struct _Heap Heap_t;

Heap_t* createHeap(int capacity, char heapType);

int enqueueHeap(Heap_t *heap, int item);

int getParentIndex(Heap_t *heap, int i);
int getLeftIndex(Heap_t *heap, int i);
int getRightIndex(Heap_t *heap, int i);
int frontHeap(Heap_t *heap);
bool isHeapEmpty(Heap_t *heap);

void heapify(Heap_t *heap, int i, int *compares);

int itemOf(Heap_t *heap, int i);

void heapSort(Heap_t *heap);

int dequeueHeap(Heap_t *heap);
void destroyHeap(Heap_t *heap);

void generateGraphHeap(int size, int precision);

#endif //HEAP_H
