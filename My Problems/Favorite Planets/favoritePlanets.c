#include <stdio.h>
#include <string.h>

struct planet
{
  int next, value;
};

int max(int a, int b)
{
  return(a > b ? a : b);
}

int go(struct planet p[], int start, int i)
{
  if (start == i) return(0);
  return(p[i].value + go(p, start, p[i].next));
}

int main()
{
  int n; scanf("%d", &n);
  struct planet p[n];
  for (int i = 0; i < n; i ++) scanf("%d", &p[i].next);
  for (int i = 0; i < n; i ++) scanf("%d", &p[i].value);
  int visited[n]; memset(visited, 0, sizeof(visited));
  int best = 0;
  for (int i = 0; i < n; i ++)
    if (!visited[i]) best = max(best, p[i].value + go(p, i, p[i].next));
  printf("%d\n", best);

  return(0);
}
