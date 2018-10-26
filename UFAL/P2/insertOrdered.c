#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int atual, fim = 10;

void insert(int ar[], int pos, int num)
{
  printf("~~%d\n", pos);
  if (ar[pos] == 0)
  {
    ar[pos] = num;
  }
  else if (ar[pos] > num)
  {
    memmove(ar + pos + 1, ar + pos, sizeof(int) * (atual + 1));
    ar[pos] = num;
  }
  else //if (ar[pos] < num)
  {
    pos ++;
    memmove(ar + pos + 1, ar + pos, sizeof(int) * (atual + 1));
    ar[pos --] = num;
  }
}

void binS(int a[], int start, int end, int target)
{
  //printf("##%d %d\n", end, start);
  int mid = (end + start) / 2;
  if (end < start)
  {
    insert(a, mid, target);
    return;
  }
  if (target < a[mid])
  {
    return(binS(a, start, mid - 1, target));
  }
  if (target > a[mid])
  {
    return(binS(a, mid + 1, end, target));
  }
  insert(a, mid, target);
  return;
}

int main()
{
  int i, *array = calloc(fim, sizeof(int)), num;
  for (i = 0; i < fim; i ++)
  {
    scanf("%d", &num);
    atual = i;
    binS(array, 0, i, num);
  }
  return(0);
}
