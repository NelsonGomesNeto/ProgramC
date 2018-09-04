#include <bits/stdc++.h>
using namespace std;
map<string, int> stringToInt;
map<int, string> intToString;

int dfs(vector<vector<int> > graph, int u, int prev, int depth)
{
  if (!graph[u].size()) return(depth);
  int ans = 0;
  for (auto v: graph[u])
    if (v != prev)
      ans = max(ans, dfs(graph, v, prev, depth + 1));
  return(ans);
}

int leafPerLevel(vector<vector<int> > graph, int u, int prev, set<int>& level, int visited[])
{
  int some = 0;
  for (auto v: graph[u])
    if (prev != v && !visited[u])
    {
      leafPerLevel(graph, v, prev, level, visited);
      some = 1;
    }
  if (!some)
  {
    level.insert(u);
    visited[u] = 1;
  }
  return(0);
}

int main()
{
  int lines;
  while (scanf("%d", &lines) != EOF)
  {
    vector<vector<int> > graph;
    char u[100], v[100];
    for (int i = 0; i < lines; i ++)
    {
      scanf("\n%s %s", u, v);
      if (!stringToInt.count(u))
      {
        intToString[stringToInt.size()] = u;
        stringToInt[u] = stringToInt.size();
      }
      if (!stringToInt.count(v))
      {
        intToString[stringToInt.size()] = v;
        stringToInt[v] = stringToInt.size();
      }
      while (graph.size() < stringToInt.size()) graph.push_back(vector<int>());
      graph[stringToInt[u]].push_back(stringToInt[v]);
      graph[stringToInt[u]].push_back(stringToInt[v]);
    }
    int depth = dfs(graph, 0, 0, 0);
    set<int> level[depth + 1]; int visited[(int) stringToInt.size()]; memset(visited, 0, sizeof(visited));
    for (int i = 0; i <= depth; i ++)
      leafPerLevel(graph, 0, 0, level[i], visited);
    set<string> ans[depth + 1];
    for (int i = 0; i <= depth; i ++)
      for (auto j: level[i])
        ans[i].insert(intToString[j]);
    for (int i = depth; i >= 0; i --)
      for (auto j: ans[i])
        printf("%s\n", j.c_str());
  }

  return(0);
}