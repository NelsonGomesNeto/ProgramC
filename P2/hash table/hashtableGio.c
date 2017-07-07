#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct _hash hash_t;
typedef struct _list list_t;
typedef struct _data data_t;

hash_t* newHash(int capacity);
list_t* newList();
data_t* newData(int key, int value);
list_t initList();

void insert(hash_t *hash, int key, int value);
list_t search(hash_t *hash, int key);
void remov(hash_t *hash, int key);

int main()
{
  return(0);
}

typedef struct _data data_t;

struct _data
{
  int key;
  int data;
  data_t *next;
};

struct _list
{
  data_t *head;
  data_t *tail;
  size_t size;
};

struct _hash
{
  list_t **data;
  size_t size;
  size_t capacity;
};

data_t* newData(int key, int value)
{
  data_t *temp = malloc(1 * sizeof(data_t));
  temp->data = value;
  temp->key = key;
  temp->next = NULL;
  return(temp);
}

hash_t* newHash(int capacity)
{
  hash_t *temp = (hash_t*) malloc(1 * sizeof(hash_t));

  temp->data = (list_t**) malloc(capacity * sizeof(list_t*));
  /*int i; FUNCIONA, mas, em C, memset é melhor;
  for (i = 0; i < capacity; i ++)
    temp->data[i] = NULL;*/
  memset(temp->data, NULL, capacity);
  temp->capacity = capacity;
  temp->size = 0;

  return(temp);
}

int hashCode(hash_t *hash, int key)
{
  return(key % hash->capacity);
}

void insert(hash_t *hash, int key, int value)
{
  int index = hashCode(hash, key);
  data_t *temp = newData(key, value);

  if (hash->data[index] == NULL)
  {
    hash->data[index] = newList();
    pushBack(hash->data[index], temp);
  }
  else
  {
    pushBack(hash->data[index], temp);
  }
  hash->size ++;
}

list_t initList()
{
  list_t temp;
  temp.size = 0;
  temp.head = NULL;
  temp.tail = NULL;
  return(temp);
}

list_t* newList()
{
  list_t *temp = malloc(1 * sizeof(list_t));
  temp->head = NULL;
  temp->tail = NULL;
  temp->size = 0;
  return(temp);
}

list_t search(hash_t *hash, int key)
{
  if (hash->data[ hashCode(hash, key) ] != NULL)
    return( *(hash->data[ hashCode(hash, key) ]) );

  return(initList());
}

void remov(hash_t *hash, int key)
{
  int index = hashCode(hash, key);
  if (hash->data[index] == NULL)
    return;

  popP(hash->data[index], contains(hash->data[index], key));

  hash->size --;
}
