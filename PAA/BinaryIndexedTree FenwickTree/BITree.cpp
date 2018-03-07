#include <bits/stdc++.h>
using namespace std;
int bitree[(int) 1e6 + 1];

int query(int i)
{
  int sum = 0;
  for (i = i + 1; i > 0; i += i & (-i))
    sum += bitree[i];
  return(sum);
}

void update(int size, int i, int value)
{
  for (i = i + 1; i <= size; i += i & (-i))
    bitree[i] += value;
}

void build(int array[], int size)
{
  memset(bitree, 0, sizeof(bitree));
  for (int i = 0; i < size; i ++)
    update(size, i, array[i]);
}

int main()
{
  int size; scanf("%d", &size);
  int array[size];
  for (int i = 0; i < size; i ++)
    scanf("%d", &array[i]);
  printf("Array = ");
  for (int i = 0; i < size; i ++)
    printf("%d%c", array[i], i < size - 1 ? ' ' : '\n');

  build(array, size);

  int queries; scanf("%d", &queries);
  while (queries -- > 0)
  {
    int a, b, c; scanf("%d %d %d", &a, &b, &c);
    if (a == 1)
      printf("Sum %d to %d = %d\n", b, c, query(c - 1) - query(b - 1 - 1));
    else
    {
      printf("Added %d to %d\n", c, b);
      array[b - 1] += c;
      update(size, b - 1, c);
    }
  }
  return(0);
}