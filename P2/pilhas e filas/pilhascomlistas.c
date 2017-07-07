#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

typedef struct stack_t stack_t;
typedef struct list_t list_t;
typedef struct node_t node_t;

stack_t* newStack();
list_t* newList();
node_t* newNode(int value);

//Stack
bool isStackEmpty(stack_t *stack);
bool isFull(stack_t *stack);
int cap(stack_t *stack);
int size(stack_t *stack);
list_t* peek(stack_t *stack);
void push(stack_t *stack, list_t *list);
void pop(stack_t *stack);
void destroyStack(stack_t *stack);

//List
void printarLista(list_t *list);
bool isListEmpty(list_t *list);
void insertBack(list_t *list, int value);
void remov(list_t *list);
void destroyList(list_t *list);

int main()
{
  char comando[30];
  stack_t *stack = newStack();
  while (scanf("%[^\n]", comando) != EOF)
  {
    getchar();
    if (strcmp(comando, "PUSH") == 0)
    {
      list_t *temp = newList(); //Lê a lista
      push(stack, temp);
    }
    else
    {
      if (isStackEmpty(stack))
      {
        printf("EMPTY STACK\n");
      }
      else
      {
        list_t *temp = peek(stack);
        printarLista(temp);
        pop(stack);
      }
    }
    strcpy(comando, "");
  }
  destroyStack(stack);
  return(0);
}

struct stack_t
{
  int cap;
  int size;
  list_t *top;
};

struct node_t
{
  int value;
  node_t *next;
};

struct list_t
{
  int size;
  node_t *head;
  node_t *tail;
  list_t *bot;
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
  temp->next = NULL;
  return(temp);
}

bool isStackEmpty(stack_t *stack)
{
  return(!stack->size);
}

bool isFull(stack_t *stack)
{
  return(stack->size == stack->cap);
}

int cap(stack_t *stack)
{
  return(stack->cap);
}

int size(stack_t *stack)
{
  return(stack->size);
}

list_t* peek(stack_t *stack)
{
  return(stack->top);
}

void push(stack_t *stack, list_t *list)
{
  if (isFull(stack)) return;
  if (isStackEmpty(stack))
  {
    stack->top = list;
  }
  else
  {
    list->bot = stack->top;
    stack->top = list;
  }
  stack->size ++;
}

void pop(stack_t *stack)
{
  if (isStackEmpty(stack)) return;

  list_t *temp = stack->top;
  stack->top = stack->top->bot;
  destroyList(temp);
  stack->size --;
}

void destroyStack(stack_t *stack)
{
  while (!isStackEmpty(stack))
    pop(stack);

  free(stack);
}

//List
list_t* newList() //Lê e cria uma nova lista
{
  list_t *temp = malloc(1 * sizeof(list_t));
  temp->size = 0;

  int value; char end;
  while (scanf("%d%c", &value, &end) != EOF && end != '\n')
  {
    insertBack(temp, value);
  } insertBack(temp, value);

  return(temp);
}

void printarLista(list_t *list)
{
  int i; node_t *curr = list->head;
  for (i = 0; i < list->size - 1; i ++)
  {
    printf("%d ", curr->value);
    curr = curr->next;
  } printf("%d\n", curr->value);
}

bool isListEmpty(list_t *list)
{
  return(!list->size);
}

void insertBack(list_t *list, int value)
{
  node_t *temp = newNode(value);
  if (isListEmpty(list))
  {
    list->head = temp;
    list->tail = temp;
  }
  else
  {
    list->tail->next = temp;
    list->tail = temp;
  }
  list->size ++;
}

void remov(list_t *list)
{
  if (isListEmpty(list)) return;
  node_t *temp = list->head;
  list->head = list->head->next;
  free(temp);
  list->size --;
}

void destroyList(list_t *list)
{
  while (!isListEmpty(list))
    remov(list);

  free(list);
}
