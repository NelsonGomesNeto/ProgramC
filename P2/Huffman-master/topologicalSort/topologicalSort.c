#include "graph.h"

int main()
{
  int size; scanf("%d", &size);
  Graph_t *graph = createGraph(size);

  int ini, fim;
  while (scanf("%d %d", &ini, &fim) != EOF)
    addEdge(graph, ini, fim);

  //printGraph(graph);
  //printf("\nDFS:\n"); dfs(graph, 1);

  printf("\nTopological Sort with DFS:\n"); topologicalSortDFS(graph);
  printf("\nTopological Sort with BFS:\n"); topologicalSortBFS(graph);

  destroyGraph(graph);
  return(0);
}
