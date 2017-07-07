#ifndef LIST_H
#define LIST_H
#include "huffTree.h"

/*
 * typedef of a list of huffman trees struct: List_t
 * ----------------------------
 */
typedef struct _List List_t;

/*
 * Function: createList
 * ----------------------------
 *   returns: List_t* of a list
 */
List_t* createList();

/*
 * Function: createListFromArray
 * ----------------------------
 *   array: long long integer array to create a list of
 *
 *   returns: List_t* of a list from a array
 */
List_t* createListFromArray(long long int array[]);

/*
 * Function: createTreeSorted
 * ----------------------------
 *   list: List_t* list to create a tree with
 *
 *   returns: void* of a huffman tree
 */
HuffTree_t* createTreeFromList(List_t *list);

/*
 * Function: addNode
 * ----------------------------
 *   Adds a node to a list
 *
 *   list: List_t* list to have a node added
 *   newNode: void* of the node to add
 *
 *   returns: nothing
 */
void addNode(List_t *list, HuffTree_t *newNode);

/*
 * Function: mergeTreeSorted
 * ----------------------------
 *   Adds a tree to a list in a sorted way
 *
 *   list: List_t* list to have a node added
 *   newNode: void* of the node to add
 *
 *   returns: nothing
 */
void addTreeSorted(List_t *list, HuffTree_t *newTree);

/*
 * Function: addTreeSorted
 * ----------------------------
 *   Sorts a list according to the frequency each node's char (byte) occurs
 *
 *   list: List_t* list to sort
 *
 *   returns: nothing
 */
void sortList(List_t *list);

/*
 * Function: addTreeSorted
 * ----------------------------
 *   Prints a list with printNode function
 *
 *   list: List_t* list to print
 *
 *   returns: nothing
 */
void printList(List_t *list);

/*
 * Function: destroyList
 * ----------------------------
 *   Destroys a list
 *
 *   list: List_t* list to destroy
 *
 *   returns: nothing
 */
void destroyList(List_t *list);

#endif //LIST_H
