#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
typedef struct list_t list_t;
typedef struct node_t node_t;

node_t* newNode(int value);
list_t* newList();

void printarLista(list_t *list, char mode);
bool isEmpty(list_t *list);

void pushBack(list_t *list, int value);

void popFront(list_t *list);
void destroy(list_t *list);

void swap(int *a, int *b)
{
	int aux = (*a);
	(*a) = (*b);
	(*b) = aux;
}

node_t* partition(list_t *list, node_t *begin, node_t *end);
void quickSortRec(list_t *list, node_t *begin, node_t *end);
void quickSort(list_t *list);

int main()
{
  list_t *list = newList();
  int i = 0, value;
  while (scanf("%d", &value) != EOF)
  {
    pushBack(list, value);
    i ++;
  }
  printarLista(list, ' ');

  quickSort(list);
	printf("Ended Sorting\n");

  printarLista(list, ' ');
	
  destroy(list);
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


node_t* partition(list_t *list, node_t *begin, node_t *end)
{
	printarLista(list, ' ');
  node_t *i = begin;
	node_t *j = begin->next;
	
	while (j != NULL)
	{
		if (j->value < i->value)
		{
			int pivot = i->value;
			i->value = j->value;
			j->value = i->next->value;
			i->next->value = pivot;
			i = i->next;
		}
		j = j->next;
	}
	return(i);
}

void quickSortRec(list_t *list, node_t *begin, node_t *end)
{
	if(begin != end)
	{
		node_t *pivot = partition(list, begin, end);
		printf("Pivot: %d\n\n", pivot->value);
		quickSortRec(list, begin, pivot);
		if (pivot->next != NULL)
			quickSortRec(list, pivot->next, end);
	}
}

void quickSort(list_t *list)
{
	quickSortRec(list, list->head, list->tail);
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
