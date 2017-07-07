#include "priorityQueue.h"

struct _PriorityQueue
{
  Node_t *head;
};

struct _Node
{
  int value;
  int priority;
  Node_t *next;
};

PriorityQueue_t* newPriorityQueue()
{
  PriorityQueue_t *temp = malloc(1 * sizeof(PriorityQueue_t));
  temp->head = NULL;
  return(temp);
}

Node_t* newNode(int value, int priority)
{
  Node_t *temp = malloc(1 * sizeof(Node_t));
  temp->value = value;
  temp->priority = priority;
  temp->next = NULL;
  return(temp);
}

bool isPriorityQueueEmpty(PriorityQueue_t *pq)
{
  return(pq->head == NULL);
}

Node_t* front(PriorityQueue_t *pq)
{
  if (isPriorityQueueEmpty(pq)) return(NULL);

  return(pq->head);
}

int maximum(PriorityQueue_t *pq)
{
  if (isPriorityQueueEmpty(pq)) return(INT_MIN);

  return(pq->head->value);
}

void printPriorityQueue(PriorityQueue_t *pq, char mode)
{
  if (isPriorityQueueEmpty(pq)) return;

  Node_t *curr = pq->head;
  while (curr->next != NULL)
  {
    printf("%d%c", curr->value, mode);
    curr = curr->next;
  } printf("%d\n", curr->value);
}

int enqueuePriorityQueue(PriorityQueue_t *pq, int value, int priority)
{
  Node_t *temp = newNode(value, priority);
  int compares = 1;
  if (isPriorityQueueEmpty(pq) || temp->priority > pq->head->priority)
  {
    temp->next = pq->head;
    pq->head = temp;
  }
  else
  {
    Node_t *curr = pq->head;
    while ((compares ++) && curr->next != NULL && temp->priority < curr->next->priority)
      curr = curr->next;

    temp->next = curr->next;
    curr->next = temp;
  }
  return(compares);
}

int dequeuePriorityQueue(PriorityQueue_t *pq)
{
  if (isPriorityQueueEmpty(pq)) return(1);

  Node_t *temp = pq->head;
  pq->head = pq->head->next;
  free(temp);

  return(1);
}

void destroyPriorityQueue(PriorityQueue_t *pq)
{
  while (!isPriorityQueueEmpty(pq))
    dequeuePriorityQueue(pq);

  free(pq);
}
