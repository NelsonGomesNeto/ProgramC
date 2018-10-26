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

void enqueue(queue_t* queue, int value);

void dequeue(queue_t* queue);
void destroyQueue(queue_t* queue);

graph_t* createGraph(int quantityNodes);
adjList_t* newAdjList(int vertex);

void addEdge(graph_t *graph, int startVertex, int endVertex);

void dfs(graph_t *graph, int source);
void bfs(graph_t *graph, int source);
void calculateDistance(graph_t *graph, int source);
void shortPath(graph_t *graph, int source, int destination);

void printGraphStates(graph_t *graph);

void destroyGraph(graph_t *graph);

int main()
{
  int vertices, arestas, testes, i;
  scanf("%d %d %d", &vertices, &arestas, &testes);
  graph_t *graph = createGraph(vertices);
  int start, end;
  for (i = 0; i < arestas; i ++)
  {
    scanf("%d %d", &start, &end);
    addEdge(graph, start, end);
  }

  for (i = 1; i <= testes; i ++)
  {
    printf("--------\n\n");
    scanf("%d %d", &start, &end);
    printf("Caso de Teste #%d - BFS(%d)\n\n", i, start);

    bfs(graph, start);
    calculateDistance(graph, start);
    printGraphStates(graph);
    shortPath(graph, start, end);

  } printf("--------\n\n");

  destroyGraph(graph);
  return(0);
}

struct _graph
{
  int size;
  adjList_t **vertices;
  bool *visited;
  int *distance;
  int *previous;
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

void destroyQueue(queue_t* queue)
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
  temp->distance = (int*) malloc(quantityNodes * sizeof(int));
  temp->previous = (int*) malloc(quantityNodes * sizeof(int));
  int i;
  for (i = 0; i < quantityNodes; i ++)
  {
    temp->vertices[i] = NULL;
    temp->visited[i] = false;
    temp->distance[i] = -1;
    temp->previous[i] = i;
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
  {
    graph->visited[i] = false;
    graph->distance[i] = -1;
    graph->previous[i] = i;
  }
}

void addEdge(graph_t *graph, int startVertex, int endVertex)
{
  adjList_t *vertex = newAdjList(endVertex);
  vertex->next = graph->vertices[startVertex];
  graph->vertices[startVertex] = vertex;

  //Undirected graph has an Edge to the other direction as well.
  /*vertex = newAdjList(startVertex);
  vertex->next = graph->vertices[endVertex];
  graph->vertices[endVertex] = vertex;*/
}

void swap(int *a, int *b)
{
  int aux = *a;
  *a = *b;
  *b = aux;
}

void sortArray(int array[], int size)
{
  int i, j;
  for (i = 0; i < size; i ++)
    for (j = i + 1; j < size; j ++)
      if (array[i] > array[j])
        swap(&array[i], &array[j]);
}

void enqueueArray(queue_t *queue, int array[], int size)
{
  int i;
  for (i = 0; i < size; i ++)
    enqueue(queue, array[i]);
}

void bfs(graph_t *graph, int source)
{
  cleanVisits(graph);
  queue_t *queue = newQueue();
  int dequeued;
  adjList_t *curr = graph->vertices[source];
  graph->visited[source] = true;
  graph->previous[source] = source;
  enqueue(queue, source);

  while (!isEmpty(queue))
  {
    dequeued = queue->head->value;
    dequeue(queue);
    printf("Iniciando busca em largura a partir de %d\n", dequeued);
    curr = graph->vertices[dequeued];
    int sortedNext[graph->size], next = 0;
    while (curr != NULL)
    {
      if (!graph->visited[curr->item])
      {
        graph->visited[curr->item] = true;
        graph->previous[curr->item] = dequeued;

        sortedNext[next ++] = curr->item;
      }
      curr = curr->next;
    }
    sortArray(sortedNext, next);
    enqueueArray(queue, sortedNext, next);
  }
  destroyQueue(queue);
  printf("\n");
}

void printGraphStates(graph_t *graph)
{
  if (graph == NULL) return;
  int i;
  for (i = 0; i < graph->size; i ++)
  {
    printf("%d | ", i);
    if (graph->distance[i] != -1)
    {
      printf("%d | ", graph->distance[i]);
    }
    else
    {
      printf("- | ");
    }
    if (graph->previous[i] != i)
    {
      printf("%d\n", graph->previous[i]);
    }
    else
    {
      printf("-\n");
    }
  }
  printf("\n");
}

void calculateDistance(graph_t *graph, int source)
{
  int i;
  for (i = 0; i < graph->size; i ++)
  {
    int atual = i, distance = 0;
    while (atual != source)
    {
      atual = graph->previous[atual];
      if (atual == i)
      {
        distance = -1; break;
      }
      distance ++;
    }
    graph->distance[i] = distance;
  }
}

void shortPath(graph_t *graph, int source, int destination)
{
  if (graph->distance[destination] != -1)
  {
    printf("Caminho entre %d e %d:", source, destination);
    int path[graph->distance[destination]], i = 0;
    int atual = destination;
    while (atual != source)
    {
      path[i ++] = atual;
      atual = graph->previous[atual];
    } path[i ++] = atual;

    int j;
    for (j = i - 1; j > 0; j --)
      printf(" %d =>", path[j]);
    printf(" %d\n", path[j]);
  }
  else
  {
    printf("Sem caminho entre %d e %d\n", source, destination);
  }
  printf("\n");
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
  free(graph->distance);
  free(graph->previous);
  free(graph);
}
