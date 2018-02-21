#include <bits/stdc++.h>
#define DEBUG if(0)
using namespace std;
int hasPath[2000][2000];

int dfs(vector<int> graph[], int u, int visited[], int target)
{
  if (visited[u]) return(0);
  if (hasPath[u][target]) return(1);
  visited[u] = 1;
  for (auto v: graph[u])
  {
    hasPath[u][v] = 1;
    if (dfs(graph, v, visited, target))
      hasPath[v][target] = hasPath[u][target] = 1;
  }
  return(hasPath[u][target]);
}

int main()
{
  int n, m;
  while (scanf("%d %d", &n, &m) && n)
  {
    memset(hasPath, 0, sizeof(hasPath));
    vector<int> graph[n]; int u, v, p;
    for (int i = 0; i < m; i ++)
    {
      scanf("%d %d %d", &u, &v, &p); u --; v --;
      if (p == 2)
      {
        graph[u].push_back(v);
        graph[v].push_back(u);
      }
      else
        graph[u].push_back(v);
    }

    int valid = 1, visited[n];
    for (int i = 0; i < n; i ++)
      for (int j = 0; j < n; j ++)
      {
        if (i != j)
        {
          memset(visited, 0, sizeof(visited));
          valid = dfs(graph, i, visited, j);
        }
      }
    printf("%d\n", valid);
  }
  return(0);
}