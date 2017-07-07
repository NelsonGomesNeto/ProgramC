#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#define list_t struct list_t
#define node_t struct node_t

node_t* newNode(int value);
list_t* newList();

int findBiggestSequence(list_t *list);

bool isEmpty(list_t *list);

void pushBack(list_t *list, int value);

void popFront(list_t *list);
void destroy(list_t *list);

int main()
{
  char value;
  do
  {
    list_t *list = newList();
    while (scanf("%c", &value) != EOF && value != '\n')
    {
      value = value - '0';
      pushBack(list, value);
    }

    int ans = findBiggestSequence(list);
    if (ans == INT_MIN)
    {
      destroy(list);
      break;
    }

    destroy(list);
  } while(true);
}

node_t
{ //node_t
  int value;
  node_t *next;
};

list_t
{ //list_t
  int size;
  node_t *head;
  node_t *tail;
};

int findBiggestSequence(list_t *list)
{
  if (list->size == 1 && list->head->value == 0)
  {
    return(INT_MIN);
  }
  node_t *curr = list->head;
  int bestStart = 0, bestEnd = -1, start = 0, end = -1, pos = 0, teve = 0;
  while (curr != NULL)
  {
    if (curr->value == 0) { start = pos; }
    while (curr != NULL && curr->value == 0)
    {
      curr = curr->next; pos ++; teve = 1;
    }
    if (teve == 1)
    {
      end = pos - 1;
      teve = 0;
    }
    if (end - start > bestEnd - bestStart)
    {
      bestEnd = end; bestStart = start;
    }
    curr = curr == NULL ? curr : curr->next; pos ++;
  }
  printf("%d %d\n", bestStart, bestEnd);
  return(bestEnd - bestStart);
}

node_t* newNode(int value)
{ //Novo node_t
  node_t *temp = (node_t*) malloc(1 * sizeof(node_t));
  temp->value = value;
  temp->next = NULL;
  return(temp);
}

list_t* newList()
{ //Nova list_t
  list_t *temp = (list_t*) malloc(1 * sizeof(list_t));
  temp->head = NULL; temp->tail = NULL;
  temp->size = 0;
  return(temp);
}

bool isEmpty(list_t *list)
{ //Verifica se a list_t está vazia
  return(!list->size);
}

void pushBack(list_t *list, int value)
{
  node_t *temp = newNode(value);
  if (isEmpty(list))
  { //Se estiver vazia, o final e começo apontam para o mesmo lugar
    list->tail = temp; list->head = temp;
  }
  else
  {
    list->tail->next = temp; //node_t final aponta para o novo último
    list->tail = temp; //Fim da list_t aponta para o novo último
  }
  list->size ++; //Aumenta o tamanho da list_t
}

void popFront(list_t *list)
{
  if (isEmpty(list)) return;

  if (list->size == 1)
  {
    free(list->head);
    list->head = NULL; list->tail = NULL;
  }
  else
  {
    node_t *curr = list->head->next;
    free(list->head);
    list->head = curr;
  }
  list->size --;
}

void destroy(list_t *list)
{
  while (!isEmpty(list))
  {
    popFront(list);
  }
  free (list);
}
