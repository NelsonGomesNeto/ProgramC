#ifndef COMPRESSFILE_H
#define COMPRESSFILE_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>
#include "huffTree.h"
#include "list.h"
#include "binaryOperations.h"
#include "progressBar.h"

/*
 * Function: createHeader
 * ----------------------------
 *   trashSize: integer to put in header
 *   treeSize: integer to put in header
 *
 *   returns: unsigned char* where position 0 holds header first byte and position 1 holds header second byte
 */
unsigned char* createHeader(int trashSize, int treeSize);

/*
 * Function: countFutureFileSize
 * ----------------------------
 *   bitsQuantity: integer array with how many bits are needed to represent a char (byte) in the file to compress
 *   frequency: long long integer array with how many times a char (byte) occurred in the file to compress
 *
 *   returns: long long integer of the size of the file that will be made
 */
long long int countFutureFileSize(int bitsQuantity[], long long int frequency[]);

/*
 * Function: getFileSize
 * ----------------------------
 *   pathFile: char array (string) with the file path
 *
 *   returns: long long int of the size of the file
 */
long long int getFileSize(char pathFile[]);

/*
 * Function: compress
 * ----------------------------
 *   Compresses a file
 *
 *   pathFile: char array (string) with the file path
 *   preventLoss: bool enabling or not the prevention of bigger files then original
 *
 *   returns: bool wheter the compression was successfull or not
 */
bool compress(char pathFile[], bool preventLoss);

/*
 * Function: multipleCompress
 * ----------------------------
 *   Compresses a file multiple times
 *
 *   quantityString: char array (string) with how many compressions will be made
 *   pathFile: char array (string) with the file path
 *
 *   returns: nothing
 */
void multipleCompress(char quantityString[], char pathFile[]);

/*
 * Function: maxCompress
 * ----------------------------
 *   Compresses a file while it will be smalled
 *
 *   pathFile: char array (string) with the file path
 *
 *   returns: nothing
 */
void maxCompress(char pathFile[]);

/*
 * Function: compressFile
 * ----------------------------
 *   Compresses a file
 *
 *   pathFile: char array (string) with the file path
 *   header: unsigned char* of the header
 *   dictionary: boolean bidimensional array of the representation of a char (byte) in the file to compress
 *   bitsQuantity: integer array with how many bits are needed to represent a char in the file to compress
 *   tree: HuffTree_t* tree of the representation of a char in the file to compress
 *
 *   returns: nothing
 */
void compressFile(char pathFile[], unsigned char *header, bool dictionary[][256], int bitsQuantity[], HuffTree_t *tree);

/*
 * Function: createDictionary
 * ----------------------------
 *   Creates a dictionary with a huffman tree
 *
 *   tree: HuffTree_t* huffman tree to create a dictionary with
 *   dictionary: boolean bidimensional array to be filled with the representation of a char (byte)
 *   bitsQuantity: integer array to be filled with how many bits are needed to represent a char (byte)
 *   frequency: long long integer array to be fille with how many times a char (byte) occurred in the file to compress
 *   bits: boolean array to store the new representation of the char (byte)
 *   depth: integer with the the actual height in which the recursion is
 *
 *   returns: nothing
 */
void createDictionary(HuffTree_t *tree, bool dictionary[][256], int bitsQuantity[], long long int frequency[], bool bits[], int depth);

/*
 * Function: createCompressedFileName
 * ----------------------------
 *   pathFile: char array (string) with the file path
 *
 *   returns: char* (string) of the compressed file name
 */
char* createCompressedFileName(char pathFile[]);

/*
 * Function: fixCompressExtension
 * ----------------------------
 *   Fixes the compressed file extension by forcing only one .huff
 *
 *   pathFile: char array (string) with the file path
 *
 *   returns: nothing
 */
void fixCompressExtension(char pathFile[]);

#endif //COMPRESSFILE_H
