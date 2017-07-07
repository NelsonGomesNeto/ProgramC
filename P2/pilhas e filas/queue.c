#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>

typedef struct queue_t queue_t;
typedef struct node_t node_t;

queue_t* newQueue();
node_t* newNode(int value);

bool isEmpty(queue_t* queue);

int front(queue_t* queue);
void enqueue(queue_t* queue, int value);

void dequeue(queue_t* queue);
void destroy(queue_t* queue);

int main()
{
  queue_t *queue = newQueue();

  dequeue(queue);
  printf("Is it empty: %s\n", isEmpty(queue) == 1 ? "true" : "false");

  int i;
  for (i = 0; i < 10; i ++)
  {
    enqueue(queue, i);
    printf("Added: %d\n", front(queue));
  }
  for (i = 0; i < 10; i ++)
  {
    printf("First: %d\n", front(queue));
    dequeue(queue);
  }

  destroy(queue);
  return(0);
}

struct queue_t
{
  node_t *head;
  node_t *tail;
};

struct node_t
{
  int value;
  node_t *next;
};

queue_t* newQueue()
{
  queue_t *temp = malloc(1 * sizeof(queue_t));
  temp->head = NULL;
  temp->tail = NULL;
  return(temp);
}

node_t* newNode(int value)
{
  node_t *temp = malloc(1 * sizeof(node_t));
  temp->value = value;
  temp->next = NULL;
  return(temp);
}

bool isEmpty(queue_t* queue)
{
  return(queue->head == NULL);
}

int front(queue_t* queue)
{
  return(queue->head->value);
}

void enqueue(queue_t* queue, int value)
{
  node_t *temp = newNode(value);
  if (isEmpty(queue))
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

void dequeue(queue_t* queue)
{
  if (isEmpty(queue)) return;
  node_t *temp = queue->head;
  queue->head = queue->head->next;
  free(temp);
}

void destroy(queue_t* queue)
{
  while (!isEmpty(queue))
    dequeue(queue);

  free(queue);
}
