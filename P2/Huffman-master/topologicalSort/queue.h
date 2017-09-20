#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>

/*
 * typedef of a queue struct: Queue_t
 * ----------------------------
 */
typedef struct _Queue Queue_t;

/*
 * typedef of a graph struct: NodeQueue_t
 * ----------------------------
 */
typedef struct _NodeQueue NodeQueue_t;

/*
 * Function: newQueue
 * ----------------------------
 *
 *  Create a new Queue
 *
 *   returns: Queue_t* of the created Queue.
 */
Queue_t* newQueue();

/*
 * Function: newNodeQueue
 * ----------------------------
 *
 *  Create a new node for the Queue
 *
 *  value: integer which will be the Node's value.
 *
 *   returns: Queue_t* of the created Node.
 */
NodeQueue_t* newNodeQueue(int value);

/*
 * Function: isQueueEmpty
 * ----------------------------
 *
 *  Check if the Queu is empty or not.
 *
 *   queue: Queue_t* queue to check if is empty.
 *
 *   returns: boolean wheter is empty or not.
 */
bool isQueueEmpty(Queue_t* queue);

/*
 * Function: front
 * ----------------------------
 *
 *  Get the first queue's value.
 *
 *  queue: Queue_t* queue to get the value.
 *
 *   returns: the first queue's value.
 */
int front(Queue_t* queue);

/*
 * Function: enqueue
 * ----------------------------
 *
 *  Enqueue a value.
 *
 *  value: integer to enqueue.
 *  queue: Queue_t* queue to enqueue the value.
 *
 *   returns: nothing.
 */
void enqueue(Queue_t* queue, int value);

/*
 * Function: dequeue
 * ----------------------------
 *
 *  Dequeue the first value.
 *
 *  queue: Queue_t* queue to dequeue.
 *
 *   returns: nothing.
 */
void dequeue(Queue_t* queue);

/*
 * Function: destroyQueue
 * ----------------------------
 *
 *  Free Queue's memory.
 *
 *  queue: Queue_t* queue to be destroyed.
 *
 *   returns: nothing.
 */
void destroyQueue(Queue_t* queue);
