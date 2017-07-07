#ifndef STACK_H
#define STACK_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

/*
 * typedef of a stack struct: Stack_t
 * ----------------------------
 */
typedef struct _Stack Stack_t;

/*
 * typedef of a stack struct: NodeStack_t
 * ----------------------------
 */
typedef struct _NodeStack NodeStack_t;

/*
 * Function: newNodeStack
 * ----------------------------
 *
 *  Create a new stack's node.
 *
 *  value: integer to put on the stack.
 *
 *  returns: NodeStack_t* of the created node.
 */
NodeStack_t* newNodeStack(int value);

/*
 * Function: newStack
 * ----------------------------
 *
 *  Create a new stack.
 *
 *   returns: Stack_t* of the created stack.
 */
Stack_t* newStack();

/*
 * Function: isStackEmpty
 * ----------------------------
 *
 *  Check if the stack is empty or not.
 *
 *   stack: Stack_t* stack to check if is empty.
 *
 *   returns: boolean wheter is empty or not.
 */
bool isStackEmpty(Stack_t *stack);

/*
 * Function: isFull
 * ----------------------------
 *
 *  Check if the stack is full or not.
 *
 *   stack: Stack_t* stack to check if is full.
 *
 *   returns: boolean wheter is full or not.
 */
bool isFull(Stack_t *stack);

/*
 * Function: peek
 * ----------------------------
 *
 *  Get the top's value of the stack.
 *
 *  stack: Stack_t* stack to get the top.
 *
 *   returns: the top stack's value.
 */
int peek(Stack_t *stack);

/*
 * Function: cap
 * ----------------------------
 *
 *  Get the stack's capacity.
 *
 *  stack: Stack_t* stack to get the capacity.
 *
 *   returns: the stack's capacity.
 */
int cap(Stack_t *stack);

/*
 * Function: size
 * ----------------------------
 *
 *  Get the stack's size.
 *
 *  stack: Stack_t* stack to get the size.
 *
 *   returns: the stack's size.
 */
int size(Stack_t *stack);

/*
 * Function: push
 * ----------------------------
 *
 *  Put on the stack.
 *
 *  stack: Stack_t* stack to put on.
 *  value: integer to put on the stack.
 *
 *   returns: nothing.
 */
void push(Stack_t *stack, int value); //Adiciona

/*
 * Function: pop
 * ----------------------------
 *
 *  Free the stack's top.
 *
 *  stack: Stack_t* stack to pop.
 *
 *   returns: nothing.
 */
void pop(Stack_t *stack);

/*
 * Function: destroyQueue
 * ----------------------------
 *
 *  Free Stack's memory.
 *
 *  stack: Stack_t* stack to be destroyed.
 *
 *   returns: nothing.
 */
bool destroyStack(Stack_t *stack); //Destrói

#endif //STACK_H
