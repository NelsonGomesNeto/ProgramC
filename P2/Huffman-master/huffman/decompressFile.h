#ifndef DECOMPRESSFILE_H
#define DECOMPRESSFILE_H
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
 * Function: getHeader
 * ----------------------------
 *   pFile: FILE* of the file to get the header
 *
 *   returns: int* where position 0 holds the trash size and position 1 holds the tree size
 */
int* getHeader(FILE *pFile);

/*
 * Function: decompress
 * ----------------------------
 *   Decompresses a file
 *
 *   pathFile: char array (string) with the file path
 *
 *   returns: nothing
 */
void decompress(char pathFile[]);

/*
 * Function: multipleDecompress
 * ----------------------------
 *   Decompresses a file multiple times
 *
 *   quantityString: char array (string) with how many decommpressions will be made
 *   pathFile: char array (string) with the file path
 *
 *   returns: nothing
 */
void multipleDecompress(char quantityString[], char pathFile[]);

/*
 * Function: decompressBytes
 * ----------------------------
 *   Descompresses the chars (bytes) of a compressed file to form a new file
 *
 *   pFile: FILE* to be read and extracted the compressed chars (bytes)
 *   newFile: FILE* to print in the decompressed bytes
 *   tree: HuffTree_t* huffman tree to know find correspondent char (byte)
 *   trashSize: integer of the trash size
 *   progressBar: long long integer of the progress bar
 *
 *   returns: nothing
 */
void decompressBytes(FILE *pFile, FILE *newFile, HuffTree_t *tree, int trashSize, long long int progressBar[]);

/*
 * Function: createDecompressedFileName
 * ----------------------------
 *   pathFile: char array (string) with the file path
 *
 *   returns: char* (string) of the decompressed file name
 */
char* createDecompressedFileName(char pathFile[]);

/*
 * Function: fixDecompressExtension
 * ----------------------------
 *   Fixes the decompressed file extension by replacing the .huff
 *
 *   pathFile: char array (string) with the file path
 *
 *   returns: nothing
 */
void fixDecompressExtension(char pathFile[]);

#endif //DECOMPRESSFILE_H
