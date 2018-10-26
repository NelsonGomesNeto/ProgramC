#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>

typedef struct stack Stack;

Stack* createStack();

void push(Stack *stack, int item);

int pop(Stack *stack);

int peek(Stack *stack);

bool isEmpty(Stack *stack);
bool isPalindrome(char string[]);
char* decimalToBinary(int num);
bool balanceStuff(char string[]);

int main()
{
  Stack *stack = createStack();
  //printf("Cap: %d; Size: %d; Peek: %d\n", cap(stack), size(stack), peek(stack));
  int i;
  for (i = 1; i <= 10; i ++)
    push(stack, i * 2);

  for (i = 0; i < 3; i ++)
  {
    printf("%d\n", pop(stack));
  }

  printf("%d\n", isPalindrome("nelson"));
  printf("%d\n", isPalindrome("natan"));
  printf("%d\n", isPalindrome("ele"));
  printf("%d\n", isPalindrome("ovo"));
  printf("%d\n", isPalindrome("pundim"));
  printf("%d\n", isPalindrome("elelele"));
  printf("%d\n", isPalindrome("miau"));

  printf("%s\n", decimalToBinary(10));
  printf("%s\n", decimalToBinary(2));
  printf("%s\n", decimalToBinary(8));
  printf("%s\n", decimalToBinary(5));
  printf("%s\n", decimalToBinary(7));

  printf("%d\n", balanceStuff("[[]]()"));
  printf("%d\n", balanceStuff("[[[)]]"));
  printf("%d\n", balanceStuff("[[[[(({{({})}}))]]]]"));
  printf("%d\n", balanceStuff("["));
  printf("%d\n", balanceStuff("]]"));
  printf("%d\n", balanceStuff("[][][][][]((([{}]))){{}}"));

  return(0);
}

typedef struct node Node;

struct stack
{
  int size;
  int capacity;
  Node *top;
};

struct node
{
  int item;
  Node *bot;
};

Stack* createStack()
{
  Stack *temp = (Stack*) malloc(1 * sizeof(Stack));
  temp->size = 0;
  temp->capacity = 1000;
  temp->top = NULL;
  return(temp);
}

Node* newNode(int item)
{
  Node *temp = (Node*) malloc(1 * sizeof(Node));
  temp->item = item;
  temp->bot = NULL;
  return(temp);
}

void push(Stack *stack, int item)
{
  if (stack->size == stack->capacity) return;

  Node *temp = newNode(item);
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

int pop(Stack *stack)
{
  if (isEmpty(stack)) return(INT_MIN);

  Node *temp = stack->top;
  int ret = temp->item;
  stack->top = stack->top->bot;
  free(temp);
  stack->size --;
  return(ret);
}

int peek(Stack *stack)
{
  if (isEmpty(stack)) return(INT_MIN);

  return(stack->top->item);
}

bool isEmpty(Stack *stack)
{
  return(!stack->size);
}

bool isPalindrome(char string[])
{
  Stack *stack = createStack();
  int i;
  for (i = 0; string[i] != '\0'; i ++)
  {
    push(stack, string[i]);
  }
  for (i = 0; string[i] != '\0'; i ++)
  {
    if (string[i] != pop(stack))
      return(0);
  }
  return(1);
}

char* decimalToBinary(int num)
{
  Stack *stack = createStack();
  while (num > 0)
  {
    push(stack, (num % 2) + '0');
    num /= 2;
  }
  int tam = stack->size, i;
  char *binary = malloc(tam * sizeof(char));
  for (i = 0; i < tam; i ++)
    binary[i] = pop(stack);

  return(binary);
}

char sameClose(char star)
{
  if (star == '(') return(')');
  if (star == '[') return(']');
  return('}'); // From '{'
}

bool balanceStuff(char string[])
{
  Stack *stack = createStack();
  int i;
  for (i = 0; string[i] != '\0'; i ++)
  {
    if (string[i] == '(' || string[i] == '[' || string[i] == '{')
    {
      push(stack, string[i]);
    }
    else
    {
      if (sameClose(pop(stack)) != string[i])
      {
        return(0);
      }
    }
  }
  if (isEmpty(stack))
    return(1);

  return(0);
}
