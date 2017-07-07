#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>

typedef struct queue Queue;

Queue* createQueue();

void enqueue(Queue *queue, int item);

int dequeue(Queue *queue);

bool isEmpty(Queue *queue);

int main()
{
  Queue *queue = createQueue();

  dequeue(queue);
  printf("Is it empty: %s\n", isEmpty(queue) == 1 ? "true" : "false");

  int i;
  for (i = 0; i < 10; i ++)
  {
    enqueue(queue, i);
  }
  for (i = 0; i < 10; i ++)
  {
    printf("First: %d\n", dequeue(queue));
  }
  
  return(0);
}

typedef struct node Node;

struct queue
{
  Node *head;
  Node *tail;
};

struct node
{
  int item;
  Node *next;
};

Queue* createQueue()
{
  Queue *temp = (Queue*) malloc(1 * sizeof(Queue));
  temp->head = NULL;
  temp->tail = NULL;
  return(temp);
}

Node* createNode(int item)
{
  Node *temp = (Node*) malloc(1 * sizeof(Node));
  temp->item = item;
  temp->next = NULL;
  return(temp);
}

void enqueue(Queue *queue, int item)
{
  Node *temp = createNode(item);
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

int dequeue(Queue *queue)
{
  if (isEmpty(queue)) return(INT_MIN);

  Node *temp = queue->head;
  int ret = temp->item;
  queue->head = queue->head->next;
  free(temp);
  return(ret);
}

bool isEmpty(Queue *queue)
{
  return(queue->head == NULL);
}
