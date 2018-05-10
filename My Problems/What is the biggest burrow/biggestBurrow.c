#include <stdio.h>
#include <string.h>

int dig(int hole[], int visited[], int now, int origin)
{
  printf("%d -> ", now);
  visited[now] = 1;
  if (hole[now] == origin)
  {
    printf("||\n");
    return(1);
  }
  return(1 + dig(hole, visited, hole[now], origin));
}

int main()
{
  int n; scanf("%d", &n);
  int hole[n], i; for (i = 0; i < n; i ++) scanf("%d", &hole[i]);
  int visited[n]; memset(visited, 0, sizeof(visited));
  int best = 0;
  for (i = 0; i < n; i ++)
  {
    if (!visited[i])
    {
      int now = dig(hole, visited, i, i);
      if (now > best)
        best = now;
    }
  }
  printf("%d\n", best);
  return(0);
}