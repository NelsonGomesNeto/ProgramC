#include "queue.h"

struct _Queue
{
  NodeQueue_t *head;
  NodeQueue_t *tail;
};

struct _NodeQueue
{
  int value;
  NodeQueue_t *next;
};

Queue_t* newQueue()
{
  Queue_t *temp = malloc(1 * sizeof(Queue_t));
  temp->head = NULL;
  temp->tail = NULL;
  return(temp);
}

NodeQueue_t* newNodeQueue(int value)
{
  NodeQueue_t *temp = malloc(1 * sizeof(NodeQueue_t));
  temp->value = value;
  temp->next = NULL;
  return(temp);
}

bool isQueueEmpty(Queue_t* queue)
{
  return(queue->head == NULL);
}

int front(Queue_t* queue)
{
  return(queue->head->value);
}

void enqueue(Queue_t* queue, int value)
{
  NodeQueue_t *temp = newNodeQueue(value);
  if (isQueueEmpty(queue))
  {
    queue->head = temp;
    queue->tail = temp;
  }
  else
  {
    queue->tail->next = temp;
    queue->tail = temp;
  }
}

void dequeue(Queue_t* queue)
{
  if (isQueueEmpty(queue)) return;
  NodeQueue_t *temp = queue->head;
  queue->head = queue->head->next;
  free(temp);
}

void destroyQueue(Queue_t* queue)
{
  while (!isQueueEmpty(queue))
    dequeue(queue);

  free(queue);
}
