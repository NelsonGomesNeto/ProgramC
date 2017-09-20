#include "stack.h"

struct _NodeStack
{
  int value;
  NodeStack_t *bot;
};

struct _Stack
{
  int size;
  int cap;
  NodeStack_t *top;
};

NodeStack_t* newNodeStack(int value)
{
  NodeStack_t *temp = (NodeStack_t*) malloc(1 * sizeof(NodeStack_t));
  temp->value = value;
  temp->bot = NULL;
  return(temp);
}

Stack_t* newStack()
{
  Stack_t *temp = (Stack_t*) malloc(1 * sizeof(NodeStack_t));
  temp->size = 0;
  temp->cap = INT_MAX;
  return(temp);
}

bool isStackEmpty(Stack_t *stack)
{
  return(!stack->size);
}

bool isFull(Stack_t *stack)
{
  return(stack->size == stack->cap);
}

int peek(Stack_t *stack)
{
  if (isStackEmpty(stack)) return INT_MIN;
  return(stack->top->value);
}

int cap(Stack_t *stack)
{
  return(stack->cap);
}
int size(Stack_t *stack)
{
  return(stack->size);
}

void push(Stack_t *stack, int value)
{
  if (isFull(stack)) return;
  NodeStack_t *temp = newNodeStack(value);
  if (isStackEmpty(stack))
  {
    stack->top = temp;
  }
  else
  {
    temp->bot = stack->top;
    stack->top = temp;
  }
  stack->size ++;
}

void pop(Stack_t *stack)
{
  if (isStackEmpty(stack)) return;
  NodeStack_t *temp = stack->top->bot;
  free(stack->top);
  stack->top = temp;
  stack->size --;
}

bool destroyStack(Stack_t *stack)
{
  while (!isStackEmpty(stack))
    pop(stack);

  free(stack);
  return(true);
}
