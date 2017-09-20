#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#define list_t struct list_t
#define node_t struct node_t

node_t* newNode(int value);
list_t* newList();

void printarLista(list_t *list, char mode);
bool isEmpty(list_t *list);

void pushBack(list_t *list, int value);
void pushOrdered(list_t *list, int value);

void swap(node_t *a, node_t *b);
void sort(list_t *list);

void popFront(list_t *list);
void destroy(list_t *list);

int main()
{
  int valor;
  list_t *myList = newList();
  while (scanf("%d", &valor) != EOF)
  {
    pushBack(myList, valor);
    //pushOrdered(myList, valor);
  }
  sort(myList);
  printarLista(myList, ' ');
  destroy(myList);
  return(0);
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

void printarLista(list_t *list, char mode)
{
  node_t *head = list->head;
  while (head != NULL)
  {
    printf("%d", head->value);
    head = head->next;
    if (head != NULL)
      printf("%c", mode);
  } printf("\n");
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

void pushOrdered(list_t *list, int value)
{
  node_t *temp = newNode(value);
  if (isEmpty(list))
  {
    list->head = temp; list->tail = temp;
  }
  else
  {
    node_t *curr = list->head, *prev = NULL;
    while (curr->next != NULL && curr->value < value)
    {
      prev = curr;
      curr = curr->next;
    }
    if (curr->value < value)
    {
      curr->next = temp;
    }
    else if (prev != NULL)
    {
      temp->next = prev->next;
      prev->next = temp;
    }
    else
    {
      temp->next = curr;
      list->head = temp;
    }
  }
  list->size ++;
}

void swap(node_t *a, node_t *b)
{
  int aux = a->value;
  a->value = b->value;
  b->value = aux;
}

void sort(list_t *list)
{
  int i, j; node_t *currI = list->head;
  for (i = 0; i < list->size; i ++)
  {
    node_t *currJ = currI->next;
    for(j = i + 1; j < list->size; j ++)
    {
      if (currJ->value < currI->value)
      {
        swap(currI, currJ);
      }
      currJ = currJ->next;
    }
    currI = currI->next;
  }
}

int search(list_t *list, int target)
{
  node_t *curr = list->head; int pos = 0;
  while (curr != NULL && curr->value != target)
  {
    curr = curr->next; pos ++;
  }
  if (curr == NULL) return(-1);

  return(pos);
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
