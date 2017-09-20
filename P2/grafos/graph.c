#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>

typedef struct _graph graph_t;
typedef struct _adjList adjList_t;
typedef struct _queue queue_t;
typedef struct _node node_t;

queue_t* newQueue();
node_t* newNode(int value);

bool isEmpty(queue_t* queue);

int front(queue_t* queue);
void enqueue(queue_t* queue, int value);

void dequeue(queue_t* queue);
void destroy(queue_t* queue);

graph_t* createGraph(int quantityNodes);
adjList_t* newAdjList(int vertex);

void addEdge(graph_t *graph, int startVertex, int endVertex);

void dfs(graph_t* graph, int source);
void bfs(graph_t* graph, int source);

void printGraph(graph_t *graph);

void destroyGraph(graph_t *graph);

int main()
{
  graph_t *graph = createGraph(6);

  addEdge(graph, 1, 2);
  addEdge(graph, 1, 5);
  addEdge(graph, 2, 5);
  addEdge(graph, 2, 3); printGraph(graph);
  addEdge(graph, 2, 4);
  addEdge(graph, 3, 4);
  addEdge(graph, 4, 5); printGraph(graph);

  printf("DFS: \n"); dfs(graph, 1);
  printf("\nBFS: \n"); bfs(graph, 1);

  destroyGraph(graph);
  return(0);
}

struct _graph
{
  int size;
  adjList_t **vertices;
  bool *visited;
};

struct _adjList
{
  int item;
  adjList_t *next;
};

struct _queue
{
  node_t *head;
  node_t *tail;
};

struct _node
{
  int value;
  node_t *next;
};

queue_t* newQueue()
{
  queue_t *temp = malloc(1 * sizeof(queue_t));
  temp->head = NULL;
  temp->tail = NULL;
  return(temp);
}

node_t* newNode(int value)
{
  node_t *temp = malloc(1 * sizeof(node_t));
  temp->value = value;
  temp->next = NULL;
  return(temp);
}

bool isEmpty(queue_t* queue)
{
  return(queue->head == NULL);
}

int front(queue_t* queue)
{
  return(queue->head->value);
}

void enqueue(queue_t* queue, int value)
{
  node_t *temp = newNode(value);
  if (isEmpty(queue))
  {
    queue->head = temp;
    queue->tail = temp;
  }
  else
  {
    queue->tail->next = temp;
    queue->tail = temp;
  }
}

void dequeue(queue_t* queue)
{
  if (isEmpty(queue)) return;
  node_t *temp = queue->head;
  queue->head = queue->head->next;
  free(temp);
}

void destroy(queue_t* queue)
{
  while (!isEmpty(queue))
    dequeue(queue);

  free(queue);
}

graph_t* createGraph(int quantityNodes)
{
  graph_t *temp = (graph_t*) malloc(1 * sizeof(graph_t));
  temp->size = quantityNodes;
  temp->vertices = (adjList_t**) malloc(quantityNodes * sizeof(adjList_t*));
  temp->visited = (bool*) malloc(quantityNodes * sizeof(bool));
  int i;
  for (i = 0; i < quantityNodes; i ++)
  {
    temp->vertices[i] = NULL;
    temp->visited[i] = false;
  }
  return(temp);
}

adjList_t* newAdjList(int vertex)
{
  adjList_t *temp = (adjList_t*) malloc(1 * sizeof(adjList_t));
  temp->item = vertex;
  temp->next = NULL;
  return(temp);
}

void cleanVisits(graph_t *graph)
{
  int i;
  for (i = 0; i < graph->size; i ++)
    graph->visited[i] = false;
}

void addEdge(graph_t *graph, int startVertex, int endVertex)
{
  adjList_t *vertex = newAdjList(endVertex);
  vertex->next = graph->vertices[startVertex];
  graph->vertices[startVertex] = vertex;

  //Undirected graph has an Edge to the other direction as well.
  vertex = newAdjList(startVertex);
  vertex->next = graph->vertices[endVertex];
  graph->vertices[endVertex] = vertex;
}

void sub_dfs(graph_t *graph, int source)
{
  graph->visited[source] = true;
  printf("%d\n", source);

  adjList_t *curr = graph->vertices[source];

  while (curr != NULL)
  {
    if (!graph->visited[curr->item])
      sub_dfs(graph, curr->item);

    curr = curr->next;
  }
}

void dfs(graph_t *graph, int source)
{
  sub_dfs(graph, source);
  cleanVisits(graph);
}

void bfs(graph_t *graph, int source)
{
  queue_t *queue = newQueue();
  int dequeued;
  adjList_t *curr = graph->vertices[source];
  printf("%d\n", source);
  graph->visited[source] = true;
  enqueue(queue, source);

  while (!isEmpty(queue))
  {
    dequeued = queue->head->value;
    dequeue(queue);
    curr = graph->vertices[dequeued];
    while (curr != NULL)
    {
      if (!graph->visited[curr->item])
      {
        printf("%d\n", curr->item);
        graph->visited[curr->item] = true;
        enqueue(queue, curr->item);
      }
      curr = curr->next;
    }
  }

  cleanVisits(graph);
}

void printGraph(graph_t *graph)
{
  if (graph == NULL) return;
  printf("Graph (%d nodes):\n", graph->size);
  int i;
  for (i = 0; i < graph->size; i ++)
  {
    printf("%d ~>", i);
    adjList_t *curr = graph->vertices[i];
    while (curr != NULL)
    {
      printf(" %d", curr->item);
      curr = curr->next;
    } printf("\n");
  }
}

void destroyGraph(graph_t *graph)
{
  int i;
  for (i = 0; i < graph->size; i ++)
  {
    adjList_t *curr = graph->vertices[i];
    while (curr != NULL)
    {
      graph->vertices[i] = graph->vertices[i]->next;
      free(curr);
      curr = graph->vertices[i];
    }
    free(curr);
    free(graph->vertices[i]);
  }
  free(graph->vertices);
  free(graph->visited);
  free(graph);
}
