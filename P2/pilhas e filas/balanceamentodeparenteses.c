#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

typedef struct stack_t stack_t;
typedef struct node_t node_t;

stack_t* newStack();
node_t* newNode(int value);
bool isEmpty(stack_t *stack);
bool isFull(stack_t *stack);
int size(stack_t *stack);
int cap(stack_t *stack);

int peek(stack_t *stack);
void push(stack_t *stack, int value);

void pop(stack_t *stack);
void destroy(stack_t *stack);

char sameOpen(char close)
{
  if (close == ')') return('(');
  if (close == ']') return('[');
  return('\0');
}

int main()
{
  int tests; scanf("%d\n", &tests); //getchar();
  while (tests > 0)
  {
    stack_t *stack = newStack();
    char caractere; bool ans = true;
    while (scanf("%c", &caractere) != EOF && caractere != '\n')
    {
      if (caractere == '(' || caractere == '[')
        push(stack, caractere);

      if (caractere == ')' || caractere == ']')
      {
        if (sameOpen(caractere) == peek(stack))
        {
          pop(stack);
        }
        else
        {
          ans = false;
        }
      }
    }
    if (size(stack) > 0)
      ans = false;

    if (ans == true)
      printf("Yes\n");
    if (ans == false)
      printf("No\n");

    destroy(stack);
    tests --;
  }
  return(0);
}

struct stack_t
{
  int size;
  int cap;
  node_t *top;
};

struct node_t
{
  int value;
  node_t *bot;
};

stack_t* newStack()
{
  stack_t *temp = malloc(1 * sizeof(stack_t));
  temp->cap = INT_MAX;
  temp->size = 0;
  return(temp);
}

node_t* newNode(int value)
{
  node_t *temp = malloc(1 * sizeof(node_t));
  temp->value = value;
  temp->bot = NULL;
  return(temp);
}

bool isEmpty(stack_t *stack)
{
  return(!stack->size);
}

bool isFull(stack_t *stack)
{
  return(stack->size == stack->cap);
}

int size(stack_t *stack)
{
  return(stack->size);
}

int cap(stack_t *stack)
{
  return(stack->cap);
}

int peek(stack_t *stack)
{
  if (isEmpty(stack)) return(INT_MIN);
  return(stack->top->value);
}

void push(stack_t *stack, int value)
{
  if (isFull(stack)) return;
  node_t *temp = newNode(value);
  if (isEmpty(stack))
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

void pop(stack_t *stack)
{
  if (isEmpty(stack)) return;
  node_t *temp = stack->top;
  stack->top = stack->top->bot;
  free(temp);
  stack->size --;
}

void destroy(stack_t *stack)
{
  while (!isEmpty(stack))
    pop(stack);
  free(stack);
}
