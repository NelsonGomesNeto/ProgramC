#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct _Graph Graph_t;
typedef struct _AdjList AdjList_t;

Graph_t* createGraph(int quantityNodes);
AdjList_t* newAdjList(int vertex);

void addEdge(Graph_t *graph, int startVertex, int endVertex);

void dfs(Graph_t* graph, int source);
void bfs(Graph_t* graph, int source);

void printGraph(Graph_t *graph);

void destroyGraph(Graph_t *graph);

int main()
{
  return(0);
}

struct _Graph
{
  int size;
  vector<vector<AdjList_t>> vertices;
  vector<bool> visited;
};

struct _AdjList
{
  int item;
};

Graph_t* createGraph(int quantityNodes)
{
  Graph_t *temp = (Graph_t*) malloc(1 * sizeof(Graph_t));
  temp->size = quantityNodes;
  temp->vertices
}
