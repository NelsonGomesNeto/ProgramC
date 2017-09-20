#include "list.h"

struct _List
{
  int size;
  HuffTree_t *head;
  HuffTree_t *tail;
};

List_t* createList()
{
  List_t *temp = (List_t*) malloc(1 * sizeof(List_t));
  temp->size = 0;
  temp->head = NULL;
  temp->tail = NULL;
  return(temp);
}

List_t* createListFromArray(long long int array[])
{
  List_t *list = createList();
  int i;
  for (i = 0; i < 256; i ++)
  {
    if (array[i] != 0)
    {
      HuffTree_t *temp;
      temp = createNode(i, array[i]);

      addNode(list, temp);
    }
  }
  return(list);
}

HuffTree_t* createTreeFromList(List_t *list)
{
  HuffTree_t *curr = list->head;
  do
  {
    int sumOfFrequencies = getFrequency(curr) + getFrequency(getNext(curr));

    list->head = getNext(getNext(curr));

    HuffTree_t *newTree = createTree('*', sumOfFrequencies, curr, getNext(curr));

    addTreeSorted(list, newTree);

    curr = list->head;
    list->size -= 2;
  } while (list->size > 1);
  list->head = list->tail;

  return(list->head);
}

void sortList(List_t *list)
{
  if (list->size <= 1) return;

  void *o = list->head, *b;
  while (o != NULL)
  {
    b = getNext(o);
    while (b != NULL)
    {
      if (isMoreFrequent(o, b))
        swapHuffTrees(o, b);

      b = getNext(b);
    }
    o = getNext(o);
  }
}

void addNode(List_t *list, HuffTree_t *newNode)
{
  if (list->size == 0)
  {
    list->head = newNode;
    list->tail = newNode;
  }
  else
  {
    setNext(list->tail, newNode);
    list->tail = newNode;
  }
  list->size ++;
}

void addTreeSorted(List_t *list, HuffTree_t *newTree)
{
  HuffTree_t *temp = newTree;
  if (list->size == 0)
  {
    list->head = temp; list->tail = temp;
  }
  else
  {
    HuffTree_t *curr = list->head, *prev = NULL;
    while (getNext(curr) != NULL && getFrequency(curr) < getFrequency(temp))
    {
      prev = curr;
      curr = getNext(curr);
    }
    if (getFrequency(curr) < getFrequency(temp))
    {
      setNext(curr, temp);
      list->tail = temp;
    }
    else if (prev != NULL)
    {
      setNext(temp, getNext(prev)); //temp->next = prev->next;
      setNext(prev, temp); //prev->next = temp;
    }
    else
    {
      setNext(temp, curr); //temp->next = curr;
      list->head = temp;
    }
  }
  list->size ++;
}

void printList(List_t *list)
{
  void *curr = list->head;
  while (!isHuffTreeEmpty(curr))
  {
    printNode(curr);
    curr = getNext(curr);
  }
}

void destroyList(List_t *list)
{
  void *curr = list->head, *toRemove;
  while (list->size > 1)
  {
    toRemove = curr;
    curr = getNext(curr);
    free(toRemove);
    list->size --;
  }
  free(list);
}
