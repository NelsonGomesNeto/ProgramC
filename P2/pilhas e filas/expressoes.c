#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#define stack_t struct stack_t
#define node_t struct node_t

node_t* newNode(int value); //Novo nó
stack_t* newStack(); //Nova pilha
bool isEmpty(stack_t *stack); //Está vazia?
bool isFull(stack_t *stack); //Está cheia?
int peek(stack_t *stack); //Olhar o do topo
int cap(stack_t *stack); //Capacidade
int size(stack_t *stack); //Tamanho atual
void push(stack_t *stack, int value); //Adiciona
void pop(stack_t *stack); //Remove
bool destroy(stack_t *stack); //Destrói

char sameClose(char a)
{
  if (a == '}') return('{');
  if (a == ']') return('[');
  if (a == ')') return('(');
}

int main()
{
  int tests; scanf("%d\n", &tests);
  while (tests > 0)
  {
    stack_t *comandos = newStack();
    char car; bool valido = true;
    while (scanf("%c", &car) != EOF && car != '\n')
    {
      if (car == '{' || car == '[' || car == '(')
      {
        push(comandos, car);
      }
      else
      {
        if (sameClose(car) == peek(comandos))
        {
          pop(comandos);
        }
        else
        {
          valido = false;
        }
      }
    }
    if (size(comandos) > 0)
    {
      valido = false;
    }
    if (valido == true)
      printf("S\n");
    if (valido == false)
      printf("N\n");
    destroy(comandos);
    tests --;
  }
  return(0);
}

node_t
{
  int value;
  node_t *bot;
};

stack_t
{
  int size;
  int cap;
  node_t *top;
};

node_t* newNode(int value)
{
  node_t *temp = (node_t*) malloc(1 * sizeof(node_t));
  temp->value = value;
  temp->bot = NULL;
  return(temp);
}

stack_t* newStack()
{
  stack_t *temp = (stack_t*) malloc(1 * sizeof(node_t));
  temp->size = 0;
  temp->cap = INT_MAX;
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

int peek(stack_t *stack)
{
  if (isEmpty(stack)) return INT_MIN;
  return(stack->top->value);
}

int cap(stack_t *stack)
{
  return(stack->cap);
}
int size(stack_t *stack)
{
  return(stack->size);
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
  node_t *temp = stack->top->bot;
  free(stack->top);
  stack->top = temp;
  stack->size --;
}

bool destroy(stack_t *stack)
{
  while (!isEmpty(stack))
    pop(stack);
  free(stack);
}
