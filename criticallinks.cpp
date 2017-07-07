#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

typedef struct _graph graph_t;
typedef struct _node node_t;

struct _graph
{
  int size;
  vector<vector<node_t>> vertices;
  vector<bool> visited;
};

struct _node
{
  int item;
};

int main()
{
  graph_t *graph = new graph_t;
  graph->size = 0;
  graph->vertices
  return(0);
}
