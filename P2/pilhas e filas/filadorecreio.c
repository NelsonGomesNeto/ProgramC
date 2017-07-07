#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>
#define QUEUE_SIZE 1001

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

int checkPosition(priorityQueue_t *pq);

int main()
{

  int tests; scanf("%d", &tests);
  while (tests > 0)
  {
    priorityQueue_t *pq = newPriorityQueue();

    int alunos; scanf("%d", &alunos);
    int changes, i;
    for (i = 0; i < alunos; i ++)
    {
      int nota; scanf("%d", &nota);
      enqueue(pq, i, nota);
    }
    changes = alunos - checkPosition(pq);

    printf("%d\n", changes);

    tests --;
    destroy(pq);
  }

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
  if (pq->currentSize == QUEUE_SIZE) return;

  if (isEmpty(pq) || priority > pq->items[pq->head].priority)
  {
    pq->head --;
    if (pq->head < 0) pq->head = QUEUE_SIZE - 1;
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
        added = true;
        break;
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
}

void dequeue(priorityQueue_t *pq)
{
  if (isEmpty(pq)) return;
  pq->head = (pq->head + 1) % QUEUE_SIZE;
  pq->currentSize --;
}

void destroy(priorityQueue_t *pq)
{
  while (!isEmpty(pq))
    dequeue(pq);

  free(pq);
}

int checkPosition(priorityQueue_t *pq)
{
  int i, atual = (pq->head) % QUEUE_SIZE;
  int differentPosition = 0;
  for (i = 0; i < pq->currentSize; i ++)
  {
    atual = (pq->head + i) % QUEUE_SIZE;

    if (pq->items[atual].value != i)
      differentPosition ++;
  }
  return(differentPosition);
}
