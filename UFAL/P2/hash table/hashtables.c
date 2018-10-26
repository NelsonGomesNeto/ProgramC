#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>

typedef struct _hashTable hashTable_t;
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
  int tests, run; scanf("%d", &tests);
  for (run = 0; run < tests; run ++)
  {
    if (run > 0) printf("\n");

    int size, elementos; scanf("%d %d", &size, &elementos);
    hashTable_t *ht = createHashTable(size);

    int i, elemento;
    for (i = 0; i < elementos; i ++)
    {
      scanf("%d", &elemento);
      put(ht, elemento, elemento);
    }

    printHashTable(ht);
    
    destroy(ht);
  }
  return(0);
}

struct _hashTable
{
  int size;
  element_t **table;
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
  int i;
  temp->table = (element_t**) malloc(size * sizeof(element_t*));
  temp->size = size;
  for (i = 0; i < size; i ++)
    temp->table[i] = NULL;

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
  if (ht->table[h] == NULL)
  {
    ht->table[h] = temp;
  }
  else
  {
    element_t *curr = ht->table[h];
    while (curr->next != NULL)
      curr = curr->next;

    curr->next = temp;
  }
}

int get(hashTable_t *ht, int key)
{
  int h = hashFunction(key, ht->size);

  element_t *curr = ht->table[h];
  while (curr != NULL && curr->key != key)
    curr = curr->next;

  return(curr == NULL ? INT_MIN : curr->value);
}

bool containsKey(hashTable_t *ht, int key)
{
  int h = hashFunction(key, ht->size);

  element_t *curr = ht->table[h];
  while (curr != NULL && curr->key != key)
    curr = curr->next;

  return(!(curr == NULL));
}

void remov(hashTable_t *ht, int key)
{
  int h = hashFunction(key, ht->size);
  if (ht->table[h] == NULL) return;

  element_t *curr = ht->table[h];
  if (curr->key == key)
  {
    ht->table[h] = ht->table[h]->next;
    free(curr);
  }
  else
  {
    while (curr->next != NULL && curr->next->key != key)
      curr = curr->next;

    if (curr->next == NULL && curr->key == key)
    {
      free(curr);
    }
    else if (curr->next != NULL && curr->next->key == key)
    {
      element_t *temp = curr->next;
      curr->next = curr->next->next;
      free(temp);
    }
  }
}

void destroy(hashTable_t *ht)
{
  int i;
  for (i = 0; i < ht->size; i ++)
  {
    while (ht->table[i] != NULL)
      remov(ht, ht->table[i]->key);

    free(ht->table[i]);
  }
  free(ht->table);
  free(ht);
}

void printHashTable(hashTable_t *ht)
{
  int i;
  for (i = 0; i < ht->size; i ++)
  {
    printf("%d -> ", i);
    element_t *curr = ht->table[i];
    while (curr != NULL)
    {
      printf("%d -> ", curr->value);
      curr = curr->next;
    } printf("\\\n");
  }
}
