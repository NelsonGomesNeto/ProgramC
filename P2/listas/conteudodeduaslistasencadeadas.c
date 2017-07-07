#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#define list_t struct list_t
#define node_t struct node_t

node_t* newNode(int value);
list_t* newList();

bool isSubConjunto(list_t *A, list_t *B);

void printarLista(list_t *list, char mode);
bool isEmpty(list_t *list);

void pushBack(list_t *list, int value);

int search(list_t *list, int target);

void popFront(list_t *list);
void destroy(list_t *list);

int main()
{
  int tamA, i, valor; scanf("%d", &tamA);
  list_t *A = newList();
  for (i = 0; i < tamA; i ++)
  {
    scanf("%d", &valor);
    pushBack(A, valor);
  }

  int tamB; scanf("%d", &tamB);
  list_t *B = newList();
  for (i = 0; i < tamB; i ++)
  {
    scanf("%d", &valor);
    pushBack(B, valor);
  }

  int ans = isSubConjunto(A, B);
  printf("%d\n", ans);

  destroy(A); destroy(B);
  return(0);
}

struct node_t
{ //node_t
  int value;
  node_t *next;
};

struct list_t
{ //list_t
  int size;
  node_t *head;
  node_t *tail;
};

bool isSubConjunto(list_t *A, list_t *B)
{
  node_t *curr = B->head;
  while (curr != NULL)
  {
    if (search(A, curr->value) == -1)
    {
      return(0);
    }
    curr = curr->next;
  }
  return(1);
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
