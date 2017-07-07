#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>
#include <time.h>

typedef struct _PriorityQueue PriorityQueue_t;
typedef struct _Node Node_t;

PriorityQueue_t* newPriorityQueue();
Node_t* newNode(int value, int priority);

bool isPriorityQueueEmpty(PriorityQueue_t *pq);

Node_t* front(PriorityQueue_t *pq);
int maximum(PriorityQueue_t *pq);
void printPriorityQueue(PriorityQueue_t *pq, char mode);
int enqueuePriorityQueue(PriorityQueue_t *pq, int value, int priority);

int dequeuePriorityQueue(PriorityQueue_t *pq);
void destroyPriorityQueue(PriorityQueue_t *pq);

void generateGraphPriorityQueue(int size, int precision);

#endif //PRIORITYQUEUE_H
