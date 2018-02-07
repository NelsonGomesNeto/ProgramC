#include <bits/stdc++.h>
using namespace std;

int topSortDFSsub(vector<int> graph[], int u, int color[], deque<int>& stack)
{
  if (color[u]) return(color[u] == 1);
  color[u] = 1;
  for (auto v: graph[u])
    if (topSortDFSsub(graph, v, color, stack) == 1) return(1);
  color[u] = 2;
  stack.push_front(u);
  return(0);
}

void topSortDFS(vector<int> graph[], int vertices)
{
  deque<int> stack;
  int color[vertices]; memset(color, 0, sizeof(color));
  for (int i = 0; i < vertices; i ++)
    if (!color[i] && topSortDFSsub(graph, i, color, stack))
    {
      printf("Has Cycle!\n");
      return;
    }
  while (!stack.empty())
  {
    printf("%d -> ", stack.front());
    stack.pop_front();
  }
  printf("¬\n");
}

int main()
{
  int vertices, edges; scanf("%d %d", &vertices, &edges);

  vector<int> graph[vertices]; int u, v;
  for (int i = 0; i < edges; i ++)
  {
    scanf("%d %d", &u, &v);
    graph[u].push_back(v);
  }

  topSortDFS(graph, vertices);
  return(0);
}