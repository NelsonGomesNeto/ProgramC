#ifndef HUFFTREE_H
#define HUFFTREE_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>
#include "binaryOperations.h"
#include "progressBar.h"

/*
 * typedef of a huffman tree struct: HuffTree_t
 * ----------------------------
 */
typedef struct _HuffTree HuffTree_t;

/*
 * Function: createNode
 * ----------------------------
 *   byte: unsigned char of the char (byte) to create a node
 *   frequency: long long integer with how many times the char (byte) occurred in the file
 *
 *   returns: HuffTree_t* of the created node.
 */
HuffTree_t* createNode(unsigned char byte, long long int frequency);

/*
 * Function: createTree
 * ----------------------------
 *   byte: unsigned char of the char (byte) to create a tree
 *   frequency: long long integer with how many times the char (byte) occurred in the file
 *   left: HuffTree_t* left node of the tree to create
 *   right: HuffTree_t* right node of the tree to create
 *
 *   returns: HuffTree_t* of the created tree.
 */
HuffTree_t* createTree(unsigned char byte, long long int frequency, HuffTree_t *left, HuffTree_t *right);

/*
 * Function: createTreeFromPreFix
 * ----------------------------
 *   Creates a tree by heading a prefixed print of a tree
 *
 *   pFile: FILE* of the file to get the header
 *   newTree: HuffTree_t** of a tree where the tree will be created from a pre fix print of a tree
 *   end: integer of how many nodes the tree will have
 *   i: integer* to keep track of how many nodes where read
 *
 *   returns: nothing
 */
void createTreeFromPreFix(FILE *pFile, HuffTree_t **newTree, int end, int *i);

/*
 * Function: createTreeFromFile
 * ----------------------------
 *   Creates a tree by analysing a file
 *
 *   pathFile: array of char (string) of the file path
 *
 *   returns: HuffTree_t* to a huffman tree
 */
HuffTree_t* createTreeFromFile(char pathFile[]);

/*
 * Function: isHuffTreeEmpty
 * ----------------------------
 *   hm: HuffTree_t* huffman tree
 *
 *   returns: boolean wheter the tree is empty or not
 */
bool isHuffTreeEmpty(HuffTree_t *hm);

/*
 * Function: isMoreFrequent
 * ----------------------------
 *   a: HuffTree_t* huffman tree to compare with tree b
 *   b: HuffTree_t* huffman tree to compare with tree a
 *
 *   returns: boolean wheter the tree a's char (byte) occurs more frequently then tree b's char
 */
bool isMoreFrequent(HuffTree_t *a, HuffTree_t *b);

/*
 * Function: swapHuffTrees
 * ----------------------------
 *   Swaps the content of tree a with tree b
 *
 *   a: HuffTree_t* huffman tree to swap with tree b
 *   b: HuffTree_t* huffman tree to swap with tree a
 *
 *   returns: nothing
 */
void swapHuffTrees(HuffTree_t *a, HuffTree_t *b);

/*
 * Function: getLeft
 * ----------------------------
 *   tree: HuffTree_t* huffman tree to get the it's next tree
 *
 *   returns: HuffTree_t* of the left huffman tree
 */
HuffTree_t* getLeft(HuffTree_t *tree);

/*
 * Function: getRight
 * ----------------------------
 *   tree: HuffTree_t* huffman tree to get the it's next tree
 *
 *   returns: HuffTree_t* of the right huffman tree
 */
HuffTree_t* getRight(HuffTree_t *tree);

/*
 * Function: getNext
 * ----------------------------
 *   tree: HuffTree_t* huffman tree to get the it's next tree
 *
 *   returns: unsigned character (byte) of the tree huffman tree
 */
unsigned char getByte(HuffTree_t *tree);

/*
 * Function: getFrequency
 * ----------------------------
 *   tree: HuffTree_t* huffman tree to get the it's char (byte) frequency
 *
 *   returns: long long int of the tree's char (byte) frequency
 */
long long int getFrequency(HuffTree_t *tree);

/*
 * Function: getNext
 * ----------------------------
 *   tree: HuffTree_t* huffman tree to get the it's next tree
 *
 *   returns: HuffTree_t* of the next tree
 */
HuffTree_t* getNext(HuffTree_t *tree);

/*
 * Function: setNext
 * ----------------------------
 *   Sets the tree tree's next tree to be the given next
 *
 *   tree: HuffTree_t* huffman tree to set the it's next tree
 *   next: HuffTree_t* huffman tree to be the next tree of the given tree
 *
 *   returns: nothing
 */
void setNext(HuffTree_t *tree, HuffTree_t *next);

/*
 * Function: printNode
 * ----------------------------
 *   Prints a tree's char (byte) and it's frequency
 *
 *   tree: HuffTree_t* a huffman tree/node to print
 *
 *   returns: nothing
 */
void printNode(HuffTree_t *tree);

/*
 * Function: printTreeInFile
 * ----------------------------
 *   Prints a tree with pre order in a file
 *
 *   newFile: FILE* the file to be printed in
 *   tree: HuffTree_t* huffman tree to print
 *
 *   returns: nothing
 */
void printTreeInFile(FILE *newFile, HuffTree_t *tree);

/*
 * Function: countTrashSize
 * ----------------------------
 *   bitsQuantity: integer array with how many bits are needed to represent a char (byte)
 *   frequency: long long integer array with how many times a char (byte) occurred
 *
 *   returns: integer of the trash size
 */
int countTrashSize(int bitsQuantity[], long long int frequency[]);

/*
 * Function: countTreeSize
 * ----------------------------
 *   tree: HuffTree_t* huffman tree to count it's size
 *
 *   returns: integer of the amount of chars needed to print the tree
 */
int countTreeSize(HuffTree_t *tree);

/*
 * Function: destroyHuffTree
 * ----------------------------
 *   Destroys a huffman tree
 *
 *   tree: HuffTree_t* huffman tree to destroy
 *
 *   returns: nothing
 */
void destroyHuffTree(HuffTree_t *tree);

#endif //HUFFTREE_H
