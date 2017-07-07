#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>

typedef struct _heap heap_t;

heap_t* createHeap(int capacity, char heapType);

void enqueueHeap(heap_t *heap, int item);

int getParentIndex(heap_t *heap, int i);
int getLeftIndex(heap_t *heap, int i);
int getRightIndex(heap_t *heap, int i);
int frontHeap(heap_t *heap);
bool isHeapEmpty(heap_t *heap);

void heapify(heap_t *heap, int i);

int itemOf(heap_t *heap, int i);

void heapSort(heap_t *heap);

int dequeue(heap_t *heap);
void destroy(heap_t *heap);

int main()
{
  heap_t *heap = createHeap(10, '+');

  int i;
  for (i = 0; i < 10; i ++)
    enqueueHeap(heap, i);

  heapify(heap, 1);
  for (i = 1; i <= 10; i ++)
  {
    printf("%d ", itemOf(heap, i));
  } printf("\n");
  //heapify(heap, 1);

  for (i = 0; i < 10; i ++)
    printf("%d ", dequeue(heap));
  printf("\n");

  destroy(heap);
  return(0);
}

struct _heap
{
  int size;
  int capacity;
  char heapType;
  int *data;
};

heap_t* createHeap(int capacity, char heapType)
{
  heap_t *temp = (heap_t*) malloc(1 * sizeof(heap_t));
  temp->size = 0;
  temp->capacity = capacity;
  temp->heapType = heapType;
  temp->data = (int*) malloc((capacity + 1) * sizeof(int));
  return(temp);
}

void swap(int *a, int *b)
{
  int aux = *a;
  *a = *b;
  *b = aux;
}

bool compareHeapWithType(int a, int b, char heapType)
{
  if (heapType == '+')
    return(a > b);
  else // (heapType == '-')
    return(a < b);
}

void enqueueHeap(heap_t *heap, int item)
{
  if (heap->size >= heap->capacity)
    printf("Heap Overflow\n");
  else
  {
    heap->data[++ heap->size] = item;

    int keyIndex = heap->size;
    int parentIndex = getParentIndex(heap, heap->size);

    while (parentIndex >= 1 && compareHeapWithType(heap->data[keyIndex], heap->data[parentIndex], heap->heapType))
    {
      swap(&heap->data[keyIndex], &heap->data[parentIndex]);

      keyIndex = parentIndex;
      parentIndex = getParentIndex(heap, keyIndex);
    }
  }
}

int dequeue(heap_t *heap)
{
  if (isHeapEmpty(heap))
  {
    printf("Heap underflow\n");
    return(INT_MIN);
  }
  else
  {
    int item = heap->data[1];

    heap->data[1] = heap->data[heap->size];
    heap->size --;

    heapify(heap, 1);
    return(item);
  }
}

int getParentIndex(heap_t *heap, int i)
{
  return(i >> 1); // Dividido por 2
}

int getLeftIndex(heap_t *heap, int i)
{
  return(i << 1); // Multiplicado por 2
}

int getRightIndex(heap_t *heap, int i)
{
  return((i << 1) + 1); // Multiplicado por 2 e added 1
}

int frontHeap(heap_t *heap)
{
  if (isHeapEmpty(heap)) return(INT_MIN);

  return(heap->data[1]);
}

bool isHeapEmpty(heap_t *heap)
{
  return(!heap->size);
}

void heapify(heap_t *heap, int i)
{
  int largest;
  int leftIndex = getLeftIndex(heap, i);
  int rightIndex = getRightIndex(heap, i);

  if (leftIndex <= heap->size && compareHeapWithType(heap->data[leftIndex], heap->data[i], heap->heapType))
    largest = leftIndex;
  else
    largest = i;

  if (rightIndex <= heap->size && compareHeapWithType(heap->data[rightIndex], heap->data[largest], heap->heapType))
    largest = rightIndex;

  if (heap->data[i] != heap->data[largest])
  {
    swap(&heap->data[i], &heap->data[largest]);
    heapify(heap, largest);
  }
}

int itemOf(heap_t *heap, int i)
{
  return(heap->data[i]);
}

void heapSort(heap_t *heap)
{
  int i;
  for (i = heap->size; i >= 2; i --)
  {
    swap(&heap->data[1], &heap->data[i]);

    heap->size --;
    heapify(heap, 1);
  }
}

void destroy(heap_t *heap)
{
  free(heap->data);
  free(heap);
}
