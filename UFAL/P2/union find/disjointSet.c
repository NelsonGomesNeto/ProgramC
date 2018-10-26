#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>

typedef struct _disjointSet disjointSet_t;
//typedef struct _node node_t;
disjointSet_t* initializeDisjointSet(int size);

int root(disjointSet_t *dj, int p);
bool find(disjointSet_t *dj, int p, int q);

void unite(disjointSet_t *dj, int p, int q);

void destroy(disjointSet_t *dj);

int main()
{
  disjointSet_t *dj = initializeDisjointSet(10);

  int i;
  for (i = 0; i < 10; i ++)
    printf("Find(%d, %d) = %s\n", i, 9, find(dj, i, 9) == true ? "True" : "False");

  for (i = 0; i < 5; i ++)
    unite(dj, i, 9);

  for (i = 0; i < 10; i ++)
    printf("Find(%d, %d) = %s\n", i, 2, find(dj, i, 2) == true ? "True" : "False");

  destroy(dj);
}

struct _disjointSet
{
  //node_t *data;
  int *num;
  int *size;
};

disjointSet_t* initializeDisjointSet(int size)
{
  disjointSet_t *temp = malloc(1 * sizeof(disjointSet_t));
  temp->num = malloc(size * sizeof(int));
  temp->size = malloc(size * sizeof(int));
  int i;
  for (i = 0; i < size; i ++)
  {
    temp->num[i] = i;
    temp->size[i] = 1;
  }

  return(temp);
}

int root(disjointSet_t *dj, int p)
{
  while (p != dj->num[p])
  {
    dj->num[p] = dj->num[dj->num[p]];
    p = dj->num[p];
  }
  return(p);
}

bool find(disjointSet_t *dj, int p, int q)
{
  return(root(dj, p) == root(dj, q));
}

void unite(disjointSet_t *dj, int p, int q)
{
  int i = root(dj, p);
  int j = root(dj, q);
  if (i != j)
  {
    if (dj->size[i] < dj->size[j])
    {
      dj->num[i] = j;
      dj->size[j] += dj->size[i];
    }
    else /*(dj->size[j] < dj->size[i])*/
    {
      dj->num[i] = j;
      dj->size[j] += dj->size[i];
    }
  }
}

void destroy(disjointSet_t *dj)
{
  free(dj->num);
  free(dj->size);
  free(dj);
}

// struct _node
// {
//   int *num;
//   int *size;
// };
