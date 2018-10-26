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

void revertNode(node_t *comeco);
void revert(list_t *list);

void popFront(list_t *list);
void destroy(list_t *list);

int main()
{
  list_t *list = newList();
  int value;
  while (scanf("%d", &value) != EOF)
  {
    pushBack(list, value);
  }
  revert(list);
  printarLista(list, ' ');
  destroy(list);
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

bool isEmpty(list_t *list)
{ //Verifica se a list_t está vazia
  return(!list->size);
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

void revertNode(node_t *comeco)
{
  node_t *curr = comeco, *prev = NULL, *prox = comeco->next;
  while (prox != NULL)
  {
    curr->next = prev;
    prev = curr;
    curr = prox;
    prox = prox->next;
  }
  curr->next = prev;
}

void revert(list_t *list)
{
  revertNode(list->head);
  node_t *aux = list->head;
  list->head = list->tail;
  list->tail = aux;
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
