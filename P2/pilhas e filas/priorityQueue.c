#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>

typedef struct priorityQueue_t priorityQueue_t;
typedef struct node_t node_t;

priorityQueue_t* newPriorityQueue();
node_t* newNode(int value, int priority);

bool isEmpty(priorityQueue_t *pq);

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

  destroy(pq);

  return(0);
}

struct priorityQueue_t
{
  node_t *head;
};

struct node_t
{
  int value;
  int priority;
  node_t *next;
};

priorityQueue_t* newPriorityQueue()
{
  priorityQueue_t *temp = malloc(1 * sizeof(priorityQueue_t));
  temp->head = NULL;
  return(temp);
}

node_t* newNode(int value, int priority)
{
  node_t *temp = malloc(1 * sizeof(node_t));
  temp->value = value;
  temp->priority = priority;
  temp->next = NULL;
  return(temp);
}

bool isEmpty(priorityQueue_t *pq)
{
  return(pq->head == NULL);
}

node_t* front(priorityQueue_t *pq)
{
  return(pq->head);
}

int maximum(priorityQueue_t *pq)
{
  return(pq->head->value);
}

void printPriorityQueue(priorityQueue_t *pq, char mode)
{
  node_t *curr = pq->head;
  while (curr->next != NULL)
  {
    printf("%d%c", curr->value, mode);
    curr = curr->next;
  } printf("%d\n", curr->value);
}

void enqueue(priorityQueue_t *pq, int value, int priority)
{
  node_t *temp = newNode(value, priority);
  if (isEmpty(pq) || temp->priority > pq->head->priority)
  {
    temp->next = pq->head;
    pq->head = temp;
  }
  else
  {
    node_t *curr = pq->head;
    while (curr->next != NULL && temp->priority < curr->next->priority)
    {
      curr = curr->next;
    }
    temp->next = curr->next;
    curr->next = temp;
  }
}

void dequeue(priorityQueue_t *pq)
{
  if (isEmpty(pq)) return;
  node_t *temp = pq->head;
  pq->head = pq->head->next;
  free(temp);
}

void destroy(priorityQueue_t *pq)
{
  while (!isEmpty(pq))
    dequeue(pq);

  free(pq);
}
