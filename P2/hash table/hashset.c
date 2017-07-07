#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>

int compares;

typedef struct _hashTable hashTable_t;
typedef struct _list list_t;
typedef struct _element element_t;

hashTable_t* createHashTable(int size);
element_t* newElement(int key, int value);

bool put(hashTable_t **ht, int key, int value);
int get(hashTable_t *ht, int key);
bool containsKey(hashTable_t *ht, int key);
void resizeHash(hashTable_t **ht);

bool remov(hashTable_t *ht, int key);
void destroy(hashTable_t *ht);

void printHashTable(hashTable_t *ht);
void PRT(hashTable_t *ht);

int main()
{
  hashTable_t *ht = createHashTable(7);
  char oper[10]; int operacoes = 0;
  while (scanf("%s", oper) != EOF)
  {
    int element;
    printf("%d ", operacoes);
    if (strcmp(oper, "ADD") == 0)
    {
      scanf("%d", &element);
      printf("%d ", put(&ht, element, element));
      printf("%d\n", compares);
    }
    if (strcmp(oper, "DEL") == 0)
    {
      scanf("%d", &element);
      printf("%d ", remov(ht, element));
      printf("%d\n", compares);
    }
    if (strcmp(oper, "HAS") == 0)
    {
      scanf("%d", &element);
      printf("%d ", containsKey(ht, element));
      printf("%d\n", compares);
    }
    if (strcmp(oper, "PRT") == 0)
    {
      PRT(ht);
    }
    operacoes ++;
  }
  destroy(ht);

  return(0);
}

struct _hashTable
{
  int elements;
  int size;
  list_t **table;
};

struct _list
{
  int size;
  element_t *head;
};

struct _element
{
  int key;
  int value;
  element_t *next;
};

hashTable_t* createHashTable(int size)
{
  hashTable_t *temp = (hashTable_t*) malloc(1 * sizeof(hashTable_t));
  temp->table = (list_t**) malloc(size * sizeof(list_t*));
  temp->elements = 0;
  temp->size = size;
  int i;
  for (i = 0; i < size; i ++)
  {
    temp->table[i] = (list_t*) malloc(1 * sizeof(list_t));
    temp->table[i]->head = NULL;
    temp->table[i]->size = 0;
  }
  return(temp);
}

element_t* newElement(int key, int value)
{
  element_t *temp = (element_t*) malloc(1 * sizeof(element_t));
  temp->key = key;
  temp->value = value;
  temp->next = NULL;
  return(temp);
}

int hashFunction(int key, int size)
{
  int h = key % size;
  if (h < 0) h = size + h;

  return(h);
}

bool put(hashTable_t **ht, int key, int value)
{
  compares = 0;
  hashTable_t *atual = (*ht);
  element_t *temp = newElement(key, value);

  int h = hashFunction(key, atual->size);
  if (atual->table[h]->head == NULL)
  {
    atual->table[h]->head = temp;
  }
  else
  {
    element_t *curr = atual->table[h]->head;
    while (curr != NULL)
    {
      compares ++;
      if (curr->value == value)
        return(false);

      curr = curr->next;
    }
    curr = atual->table[h]->head;
    atual->table[h]->head = temp;
    temp->next = curr;
  }
  atual->table[h]->size ++;
  atual->elements ++;

  if ((double) atual->elements / atual->size >= 0.75)
  {
    int aux = compares;
    resizeHash(ht);
    compares = aux;
  }
  return(true);
}

int get(hashTable_t *ht, int key)
{
  int h = hashFunction(key, ht->size);

  element_t *curr = ht->table[h]->head;
  while (curr != NULL && curr->key != key)
    curr = curr->next;

  return(curr == NULL ? INT_MIN : curr->value);
}

bool containsKey(hashTable_t *ht, int key)
{
  compares = 0;
  int h = hashFunction(key, ht->size);

  element_t *curr = ht->table[h]->head;
  while (curr != NULL)
  {
    if (curr->key == key)
    {
      compares ++;
      break;
    }
    curr = curr->next;
    compares ++;
  }

  return(!(curr == NULL));
}

void resizeHash(hashTable_t **ht)
{
  hashTable_t *atual = (*ht);
  int newSize = (atual->size * 2) - 1;
  hashTable_t *temp = createHashTable(newSize);
  int i;
  for (i = 0; i < atual->size; i ++)
  {
    while (atual->table[i]->head != NULL)
    {
      put(&temp, atual->table[i]->head->key, atual->table[i]->head->value);
      remov(atual, atual->table[i]->head->key);
    }
    free(atual->table[i]);
  }
  free(atual->table);
  free(atual);
  (*ht) = temp;
}

bool remov(hashTable_t *ht, int key)
{
  compares = 0;
  int h = hashFunction(key, ht->size);
  if (ht->table[h]->head == NULL) return(false);

  element_t *curr = ht->table[h]->head;
  if (curr->key == key)
  {
    compares ++;
    ht->table[h]->head = ht->table[h]->head->next;
    ht->table[h]->size --;
    ht->elements --;
    free(curr);
    return(true);
  }
  else
  {
    compares ++;
    while (curr->next != NULL && curr->next->key != key)
    {
      compares ++;
      curr = curr->next;
    }

    if (curr->next == NULL && curr->key == key)
    {
      compares ++;
      ht->table[h]->size --;
      ht->elements --;
      free(curr);
      return(true);
    }
    else if (curr->next != NULL && curr->next->key == key)
    {
      compares ++;
      element_t *temp = curr->next;
      curr->next = curr->next->next;
      ht->table[h]->size --;
      ht->elements --;
      free(temp);
      return(true);
    }
  }
  return(false);
}

void destroy(hashTable_t *ht)
{
  int i;
  for (i = 0; i < ht->size; i ++)
  {
    while (ht->table[i]->head != NULL)
      remov(ht, ht->table[i]->head->key);

    free(ht->table[i]);
  }
  free(ht->table);
  free(ht);
}

void printHashTable(hashTable_t *ht)
{
  int i;
  printf("Hash Table (Elements: %d) (Size: %d)\n", ht->elements, ht->size);
  for (i = 0; i < ht->size; i ++)
  {
    printf("%d -> ", i);
    element_t *curr = ht->table[i]->head;
    while (curr != NULL)
    {
      printf("%d -> ", curr->value);
      curr = curr->next;
    } printf("\\\n");
  }
}

void PRT(hashTable_t *ht)
{
  int i, big;
  for (i = 0; i < ht->size; i ++)
    if (i == 0 || ht->table[i]->size > big)
      big = ht->table[i]->size;

  printf("%d %d %d\n", ht->size, ht->elements, big);
}
