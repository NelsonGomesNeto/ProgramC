#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>

typedef struct _node node_t;
typedef struct _doublyList doublyList_t;

doublyList_t* createDoublyLinkedList();

void circulateDoublyLinkedList(doublyList_t *list);

void insertNode(doublyList_t *list, int item);
void insertSorted(doublyList_t *list, int item);

void printDoublyLinkedListForward(doublyList_t *first);
void printDoublyLinkedListBackward(doublyList_t *last);

bool isEmpty(doublyList_t *first);

node_t* search(doublyList_t *first, int item);
void remov(doublyList_t *first, int item);

int main()
{
  doublyList_t *list = createDoublyLinkedList();
  int value; char end;
  while (scanf("%d%c", &value, &end) && end != '\n')
    insertSorted(list, value);
  insertSorted(list, value);

  printDoublyLinkedListForward(list);
  return(0);
}

struct _node
{
  int item;
  node_t *next;
  node_t *prev;
};

struct _doublyList
{
  node_t *head;
  node_t *tail;
};

doublyList_t* createDoublyLinkedList()
{
  doublyList_t *temp = (doublyList_t*) malloc(1 * sizeof(doublyList_t));
  temp->head = NULL;
  temp->tail = NULL;
  return(temp);
}

node_t* createNode(int item)
{
  node_t *temp = (node_t*) malloc(1 * sizeof(node_t));
  temp->item = item;
  temp->next = NULL;
  temp->prev = NULL;
  return(temp);
}

void circulateDoublyLinkedList(doublyList_t *list)
{
  list->head->prev = list->tail;
  list->tail->next = list->head;
}

void insertNode(doublyList_t *list, int item)
{
  node_t *temp = createNode(item);
  if (isEmpty(list))
  {
    list->head = temp;
    list->tail = temp;
  }
  else
  {
    list->tail->next = temp;
    temp->prev = list->tail;
    list->tail = temp;
  }
}

void insertSorted(doublyList_t *list, int item)
{
  node_t *temp = createNode(item);
  if (isEmpty(list))
  {
    list->head = temp;
    list->tail = temp;
  }
  else
  {
    node_t *curr = list->head, *prev = NULL;
    while (curr != NULL && curr->item < item)
    {
      prev = curr;
      curr = curr->next;
    }

    if (curr == NULL)
    {
      temp->prev = prev;
      prev->next = temp;

      list->tail = temp;
    }
    else
    {
      if (curr == list->head)
      {
        list->head = temp;
        temp->next = curr;
        curr->prev = temp;
      }
      else
      {
        temp->next = curr;
        temp->prev = curr->prev->prev;
        curr->prev->next = temp;
        curr->prev = temp;
      }
    }
  }
  printf("Added\n"); fflush(stdout);
}

void printDoublyLinkedListForward(doublyList_t *first)
{
  node_t *curr = first->head;
  while (curr != NULL)
  {
    printf("%d ", curr->item);
    curr = curr->next;
  } printf("\n");
}

void printDoublyLinkedListBackward(doublyList_t *last)
{
  node_t *curr = last->tail;
  while (curr != NULL)
  {
    printf("%d ", curr->item);
    curr = curr->prev;
  } printf("\n");
}

bool isEmpty(doublyList_t *first)
{
  return(first->head == NULL);
}

node_t* search(doublyList_t *first, int item)
{
  node_t *curr = first->head;
  while (curr != NULL)
  {
    if (curr->item == item)
      return(curr);

    curr = curr->next;
  }
  return(NULL);
}

void remov(doublyList_t *first, int item)
{
  node_t *curr = first->head;
  while (curr != NULL)
  {
    if (curr->item == item)
    {
      curr->prev->next = curr->next;
      curr->next->prev = curr->prev;
      free(curr);
      return;
    }

    curr = curr->next;
  }
}
