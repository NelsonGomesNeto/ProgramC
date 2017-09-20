#ifndef GRAPH_H
#define GRAPH_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>
#include "stack.h"
#include "queue.h"

/*
 * typedef of a graph struct: Graph_t
 * ----------------------------
 */
typedef struct _Graph Graph_t;

/*
 * typedef of an adjacent list struct: AdjList_t
 * ----------------------------
 */
typedef struct _AdjList AdjList_t;

/*
 * Function: createGraph
 * ----------------------------
 *   quantityNodes: integer with how many nodes the graph will have
 *
 *   returns: Graph_t* of the created graph.
 */
Graph_t* createGraph(int quantityNodes);

/*
 * Function: newAdjList
 * ----------------------------
 *   Create a vertex
 *
 *   vertex: integer to have a vertex created
 *
 *   returns: AdjList_t* of the created vertex
 */
AdjList_t* newAdjList(int vertex);

/*
 * Function: addEdge
 * ----------------------------
 *   Adds a Edge to the graph
 *
 *   graph: Graph_t *graph to have a edge added
 *   startVertex: integer which starts the edge
 *   endVertex: integer which ends the edge
 *
 *   returns: nothing
 */
void addEdge(Graph_t *graph, int startVertex, int endVertex);

/*
 * Function: dfs
 * ----------------------------
 *   Do a depth-first search
 *
 *   graph: Graph_t *graph to do dfs
 *   source: integer that is the vertex on which start the dfs
 *
 *   returns: nothing
 */
void dfs(Graph_t *graph, int source);

/*
 * Function: topologicalSortDFS
 * ----------------------------
 *   Do a Topological Sort on graph with dfs
 *
 *   graph: Graph_t *graph to do a  Topological Sort
 *
 *   returns: nothing
 */
void topologicalSortDFS(Graph_t *graph);

/*
 * Function: topologicalSortBFS
 * ----------------------------
 *   Do a Topological Sort on graph with bfs
 *
 *   graph: Graph_t *graph to do a  Topological Sort
 *
 *   returns: nothing
 */
void topologicalSortBFS(Graph_t *graph); // aka Kahn's algorithm

/*
 * Function: printGraph
 * ----------------------------
 *   Print a graph
 *
 *   graph: Graph_t *graph to be printed
 *
 *   returns: nothing
 */
void printGraph(Graph_t *graph);

/*
 * Function: destroyGraph
 * ----------------------------
 *   Free memory
 *
 *   graph: Graph_t *graph to be destroyed
 *
 *   returns: nothing
 */
void destroyGraph(Graph_t *graph);

#endif //GRAPH_H
