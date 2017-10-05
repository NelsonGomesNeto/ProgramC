#include <stdio.h>

void dig(int con[], int vis[], int start, int curr)
{
  if (start == curr) return;

  vis[curr] = 1;
  return(dig(con, vis, start, con[curr]));
}

int main()
{
  int size; scanf("%d", &size);
  int connections[size], visited[size], i;
  for (i = 0; i < size; i ++)
  {
    scanf("%d", &connections[i]);
    visited[i] = 0;
  }

  int holes = 0;
  for (i = 0; i < size; i ++)
  {
    if (!visited[i])
    {
      dig(connections, visited, i, connections[i]);
      holes ++;
    }
  }

  printf("%d\n", holes);

  return(0);
}
