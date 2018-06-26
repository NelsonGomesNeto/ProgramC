#include <bits/stdc++.h>
#define DEBUG if(0)
using namespace std;

int dfs(vector<int> graph[], int visited[], int u, int color)
{
  if (visited[u]) return(visited[u] == 1 ? color : visited[u]);
  visited[u] = color;
  int minColor = color;
  for (auto v: graph[u])
    minColor = min(minColor, dfs(graph, visited, v, color));
  visited[u] = minColor;
  return(minColor);
}

int main()
{
  int n, m, s; scanf("%d %d %d", &n, &m, &s); s --;
  vector<int> graph[n]; int u, v;
  for (int i = 0; i < m; i ++)
  {
    scanf("%d %d", &u, &v); u --; v --;
    graph[u].push_back(v);
  }

  int visited[n]; memset(visited, 0, sizeof(visited));
  dfs(graph, visited, s, 1);
  int color = 2;
  for (int i = 0; i < n; i ++)
    if (!visited[i])
      color = dfs(graph, visited, i, color) + 1;

  DEBUG for (int i = 0; i < n; i ++) printf("%d%c", visited[i], i < n - 1 ? ' ' : '\n');
  printf("%d\n", color - 2);

  return(0);
}