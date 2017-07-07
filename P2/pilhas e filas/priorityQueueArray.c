#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>
#define QUEUE_SIZE 15

typedef struct _priorityQueue priorityQueue_t;
typedef struct _node node_t;

priorityQueue_t* newPriorityQueue();
node_t* newNode(int value, int priority);

bool isEmpty(priorityQueue_t *pq);
int size(priorityQueue_t *pq);

node_t* front(priorityQueue_t *pq);
int maximum(priorityQueue_t *pq);
void printPriorityQueue(priorityQueue_t *pq, char mode);
void enqueue(priorityQueue_t *pq, int value, int priority);

void dequeue(priorityQueue_t *pq);
void destroy(priorityQueue_t *pq);

int main()
{
  priorityQueue_t *pq = newPriorityQueue();
  printf("%s\n", isEmpty(pq) == true ? "true" : false);

  enqueue(pq, 1, 1); printPriorityQueue(pq, ' ');
  enqueue(pq, 2, 3); printPriorityQueue(pq, ' ');
  enqueue(pq, 3, 2); printPriorityQueue(pq, ' ');
  enqueue(pq, 4, 5); printPriorityQueue(pq, ' ');
  enqueue(pq, 5, 4); printPriorityQueue(pq, ' ');
  enqueue(pq, 6, 0); printPriorityQueue(pq, ' ');
  enqueue(pq, 7, 6); printPriorityQueue(pq, ' ');
  dequeue(pq); printPriorityQueue(pq, ' ');
  printf("Max: %d\n", maximum(pq));

  int i = 0, j = 0;
  while (size(pq) < QUEUE_SIZE)
  {
    i ++; j = (j + 1) % 10;
    enqueue(pq, i, j);
  } enqueue(pq, i, j);
  printPriorityQueue(pq, ' ');

  destroy(pq);

  return(0);
}

struct _node
{
  int value;
  int priority;
};

struct _priorityQueue
{
  int currentSize;
  int head;
  int tail;
  node_t items[QUEUE_SIZE];
};

priorityQueue_t* newPriorityQueue()
{
  priorityQueue_t *temp = malloc(1 * sizeof(priorityQueue_t));
  temp->currentSize = 0;
  temp->head = 1;
  temp->tail = 0;
  return(temp);
}

bool isEmpty(priorityQueue_t *pq)
{
  return(!pq->currentSize);
}

int size(priorityQueue_t *pq)
{
  return(pq->currentSize);
}

int maximum(priorityQueue_t *pq)
{
  return(pq->items[pq->head].value);
}

void printPriorityQueue(priorityQueue_t *pq, char mode)
{
  printf("Printing (Size: %d) (Starting at: %d):\n", pq->currentSize, pq->head);
  int i, atual = (pq->head) % QUEUE_SIZE;
  for (i = 0; i < pq->currentSize - 1; i ++)
  {
    atual = (pq->head + i) % QUEUE_SIZE;
    printf("%d%c(Position: %d)\n", pq->items[atual].value, mode, atual);
  }
  atual = (pq->head + i) % QUEUE_SIZE;
  printf("%d (Position: %d)\n", pq->items[atual].value, atual);
  printf("Printed\n\n");
}

void enqueue(priorityQueue_t *pq, int value, int priority)
{
  printf("Enqueuing (%d, %d):\n", value, priority);
  if (pq->currentSize == QUEUE_SIZE) return;

  if (isEmpty(pq) || priority > pq->items[pq->head].priority)
  {
    pq->head --;
    if (pq->head < 0) pq->head = QUEUE_SIZE - 1;
    printf("At the head %d\n", pq->head);
    pq->items[pq->head].value = value;
    pq->items[pq->head].priority = priority;
  }
  else
  {
    int i, atual; bool added = false;
    for (i = 0; i < pq->currentSize; i ++)
    {
      atual = (pq->head + i) % QUEUE_SIZE;
      if (priority > pq->items[atual].priority)
      {
        int j;
        for (j = -1; j < i; j ++)
        {
          atual = (pq->head + j) % QUEUE_SIZE;
          if (atual < 0) atual = QUEUE_SIZE - 1;

          pq->items[atual] = pq->items[(atual + 1) % QUEUE_SIZE];
        }

        atual = (pq->head + i - 1) % QUEUE_SIZE;
        if (atual < 0) atual = QUEUE_SIZE - 1;
        pq->items[atual].value = value;
        pq->items[atual].priority = priority;
        added = true; break;
      }
    }
    if (added == false)
    {
      pq->tail ++;
      pq->items[pq->tail].value = value;
      pq->items[pq->tail].priority = priority;
    }
    else
    {
      pq->head --;
      if (pq->head < 0) pq->head = QUEUE_SIZE - 1;
    }
  }
  pq->currentSize ++;
  printf("Enqueued\n\n");
}

void dequeue(priorityQueue_t *pq)
{
  printf("Dequeuing (%d, %d)\n", pq->items[pq->head].value, pq->items[pq->head].priority);
  if (isEmpty(pq)) return;
  pq->head = (pq->head + 1) % QUEUE_SIZE;
  pq->currentSize --;
  printf("Dequeued\n\n");
}

void destroy(priorityQueue_t *pq)
{
  while (!isEmpty(pq))
    dequeue(pq);

  free(pq);
}
