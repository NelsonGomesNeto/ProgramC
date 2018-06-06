#include <bits/stdc++.h>
using namespace std;

void dfs(vector<int> graph[], vector<int>& leaf, int visited[], int u, int level)
{
  visited[u] = 1; int end = 1;
  for (auto v: graph[u])
  {
    if (visited[v]) continue;
    dfs(graph, leaf, visited, v, level + 1);
    end = 0;
  }
  if (end) leaf.push_back(level);
}

int main()
{
  int n; scanf("%d", &n);
  vector<int> graph[n]; int u, v;
  for (int i = 0; i < n - 1; i ++)
  {
    scanf("%d %d", &u, &v); u --; v --;
    graph[u].push_back(v);
  }

  vector<int> leaf; int visited[n]; memset(visited, 0, sizeof(visited));
  dfs(graph, leaf, visited, 0, 0);

  double total = 0;
  for (auto i: leaf)
    total += i;
  printf("%.12lf\n", total / leaf.size());

  return(0);
}
