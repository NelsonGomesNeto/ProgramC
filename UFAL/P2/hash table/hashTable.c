#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>

typedef struct _hashTable hashTable_t;
typedef struct _list list_t;
typedef struct _element element_t;

hashTable_t* createHashTable(int size);
element_t* newElement(int key, int value);

void put(hashTable_t *ht, int key, int value);
int get(hashTable_t *ht, int key);
bool containsKey(hashTable_t *ht, int key);

void remov(hashTable_t *ht, int key);
void destroy(hashTable_t *ht);

void printHashTable(hashTable_t *ht);

int main()
{
  hashTable_t *ht = createHashTable(11);

  int i;
  for (i = 0; i < 11 * 3; i ++)
  {
    put(ht, i, i);
    if (i % 11 == 0)
    {
      printHashTable(ht); printf("\n");
    }
  }

  printHashTable(ht); printf("\n");

  printf("Contains: %d? %s\n", 15, containsKey(ht, 15) == true ? "true" : "false");
  printf("Contains: %d? %s\n", -1, containsKey(ht, -1) == true ? "true" : "false");
  printf("Contains: %d? %s\n\n", 32, containsKey(ht, 32) == true ? "true" : "false");
  printf("Get: %d: %d\n", 15, get(ht, 15));
  printf("Get: %d: %d\n", -1, get(ht, -1));
  printf("Get: %d: %d\n\n", 32, get(ht, 32));

  for (i = 11 * 3; i >= 0; i --)
  {
    remov(ht, i);
    if (i % 11 == 0)
    {
      printHashTable(ht); printf("\n");
    }
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

void put(hashTable_t *ht, int key, int value)
{
  element_t *temp = newElement(key, value);

  int h = hashFunction(key, ht->size);
  if (ht->table[h]->head == NULL)
  {
    ht->table[h]->head = temp;
  }
  else
  {
    element_t *curr = ht->table[h]->head;
    while (curr->next != NULL)
      curr = curr->next;

    curr->next = temp;
  }
  ht->table[h]->size ++;
  ht->elements ++;
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
  int h = hashFunction(key, ht->size);

  element_t *curr = ht->table[h]->head;
  while (curr != NULL && curr->key != key)
    curr = curr->next;

  return(!(curr == NULL));
}

void remov(hashTable_t *ht, int key)
{
  int h = hashFunction(key, ht->size);
  if (ht->table[h] == NULL) return;

  element_t *curr = ht->table[h]->head;
  if (curr->key == key)
  {
    ht->table[h]->head = ht->table[h]->head->next;
    ht->table[h]->size --;
    ht->elements --;
    free(curr);
  }
  else
  {
    while (curr->next != NULL && curr->next->key != key)
      curr = curr->next;

    if (curr->next == NULL && curr->key == key)
    {
      ht->table[h]->size --;
      ht->elements --;
      free(curr);
    }
    else if (curr->next != NULL && curr->next->key == key)
    {
      element_t *temp = curr->next;
      curr->next = curr->next->next;
      ht->table[h]->size --;
      ht->elements --;
      free(temp);
    }
  }
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
