#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>

typedef struct _hashTable hashTable_t;

hashTable_t* createHashTable();

void put(hashTable_t *ht, int key, int item);

int get(hashTable_t *ht, int key);

void remov(hashTable_t *ht, int key);

bool containsKey(hashTable_t *ht, int key);

void printHashTable(hashTable_t *ht);

int main()
{
  int i;
  hashTable_t *ht = createHashTable();

  printHashTable(ht);

  for (i = 0; i < 13; i ++)
  {
    put(ht, i, i);
    put(ht, i, i * 2);
  }

  printHashTable(ht);

  for (i = 0; i < 13; i ++)
  {
    remov(ht, i);
    remov(ht, i);
  }

  return(0);
}

typedef struct _element element_t;

struct _element
{
  int key;
  int item;
  element_t *next;
};

element_t* newElement(int key, int item)
{
  element_t *temp = (element_t*) malloc(1 * sizeof(element_t));
  temp->key = key;
  temp->item = item;
  temp->next = NULL;
  return(temp);
}

struct _hashTable
{
  int currentSize;
  int size;
  element_t **table;
};

hashTable_t* createHashTable()
{
  hashTable_t *temp = (hashTable_t*) malloc(1 * sizeof(hashTable_t));
  temp->currentSize = 0;
  temp->size = 13;
  temp->table = (element_t**) malloc(1 * sizeof(element_t*));
  int i;
  for (i = 0; i < temp->size; i ++)
  {
    temp->table[i] = NULL;
  }

  return(temp);
}

int hashFunction(hashTable_t *ht, int key)
{
  return(key % ht->size);
}

void put(hashTable_t *ht, int key, int item)
{
  int position = hashFunction(ht, key);

  element_t *temp = newElement(key, item);

  temp->next = ht->table[position];
  ht->table[position] = temp;

  ht->currentSize ++;
}

int get(hashTable_t *ht, int key)
{
  int position = hashFunction(ht, key);

  element_t *curr = ht->table[position];

  while (curr != NULL && curr->key != key)
    curr = curr->next;

  if (curr != NULL && curr->key == key)
    return(curr->item);

  return(INT_MIN);
}

void remov(hashTable_t *ht, int key)
{
  int position = hashFunction(ht, key);

  element_t *curr = ht->table[position];

  if (curr != NULL && curr->key == key)
  {
    ht->table[position]->next = curr->next->next;
    free(curr);
    ht->currentSize --;
    return;
  }

  while (curr->next != NULL && curr->next->key != key)
    curr = curr->next;

  if (curr != NULL && curr->key == key)
  {
    element_t *temp = curr->next;
    curr->next = curr->next->next;
    free(temp);
    ht->currentSize --;
    return;
  }
}

bool containsKey(hashTable_t *ht, int key)
{
  int position = hashFunction(ht, key);

  element_t *curr = ht->table[position];

  while (curr != NULL && curr->key != key)
    curr = curr->next;

  if (curr != NULL && curr->key == key)
    return(true);

  return(false);
}

void printHashTable(hashTable_t *ht)
{
  int i;
  for (i = 0; i < ht->size; i ++)
  {
    printf("%d ~~> ", i);
    element_t *curr = ht->table[i];
    while (curr != NULL)
    {
      printf("%d -> ", curr->item);
      curr = curr->next;
    }
    printf("/\n");
  }
}
