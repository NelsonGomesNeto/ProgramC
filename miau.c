#include <stdio.h>
#include <string.h>

typedef struct miau miau_t;

struct miau
{
  char name[100];
  int value;
};

void printMiau(miau_t nyan[], int n)
{
  for (int i = 0; i < n; i ++)
    printf("%s %d\n", nyan[i].name, nyan[i].value);
}

void swap(miau_t *a, miau_t *b)
{
  miau_t aux = *a;
  *a = *b;
  *b = aux;
}

void sort(miau_t nyan[], int n)
{
  for (int i = 0; i < n; i ++)
    for (int j = i + 1; j < n; j ++)
      if (strcmp(nyan[i].name, nyan[j].name) > 0 || (strcmp(nyan[i].name, nyan[j].name) == 0 && nyan[i].value > nyan[j].value))
        swap(&nyan[i], &nyan[j]);
}

int main()
{
  int n; scanf("%d", &n);
  miau_t nyan[n];
  for (int i = 0; i < n; i ++)
    scanf("\n%s %d", nyan[i].name, &nyan[i].value);

  printf("\tBefore:\n"); printMiau(nyan, n);
  sort(nyan, n);
  printf("\n\tAfter:\n"); printMiau(nyan, n);
  return(0);
}