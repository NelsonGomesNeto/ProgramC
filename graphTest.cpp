#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void cleanVisits(int visited[], int size)
{
  int i;
  for (i = 0; i < size; i ++)
    visited[i] = 0;
}

void dfs(vector<int> graph[], int visited[], int from)
{
  visited[from] = 1; // true
  printf("%d\n", from);

  int i = 0, end = graph[from].size();

  while (i < end)
  {
    if (!visited[graph[from][i]])
      dfs(graph, visited, graph[from][i]);

    i ++;
  }
}

int main()
{
  int tam; scanf("%d", &tam);
  int links; scanf("%d", &links);

  int visited[tam];
  vector<int> graph[tam];

  cleanVisits(visited, tam);

  int i, j;
  for (i = 0; i < links; i ++)
  {
    int from, to; scanf("%d %d", &from, &to);
    graph[from].push_back(to);
  }


  for (i = 0; i < links; i ++)
  {
    int size = graph[i].size();
    printf("%d: ", i);
    for (j = 0; j < size; j ++)
    {
      printf("%d -> ", graph[i][j]);
    } printf("¬\n");
  }

  printf("DFS:\n");
  dfs(graph, visited, 0);

  return(0);
}
