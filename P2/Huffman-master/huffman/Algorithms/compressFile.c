#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>
#include "huffTree.h"
#include "list.h"
#include "binaryOperations.h"

unsigned char* createHeader(int trashSize, int treeSize, huffTree_t *tree)
{
  unsigned char *bytes = (unsigned char*) malloc(3 * sizeof(unsigned char));
  bytes[0] = trashSize << 5 | treeSize >> 8;
  bytes[1] = treeSize;

  printf("Header: %c%c", bytes[0], bytes[1]);
  printTreePreOrder(tree); printf("\n");
  //printByte(bytes[0]);
  //printByte(bytes[1]);
  return(bytes);
}

void compress()
{
  huffTree_t *compressedTree = createTreeFromFile();
  if (isHuffTreeEmpty(compressedTree))
    continue;

  printf("Compressed Tree:\n");
  printf("PreOrder: "); printTreePreOrder(compressedTree); printf("\n");
  printf("InOrder: "); printTreeInOrder(compressedTree); printf("\n");
  printf("PosOrder: "); printTreePosOrder(compressedTree); printf("\n");

  bool dictionary[256][256]; int bitsQuantity[256];
  long long int frequency[256]; int i;
  for(i = 0; i < 256; i ++)
    frequency[i] = -1;

  bool bits[256];
  createDictionary(compressedTree, dictionary, bitsQuantity, frequency, bits, 0);

  for(i = 0; i < 256; i ++)
  {
    if(frequency[i] != -1)
    {
      //printf("%d", dictionary[i][0]);
      //printByte(dictionary[i][0], 13);
      printf(" tam = %d freq = %lld char = %c\n", bitsQuantity[i], frequency[i], i);
    }
  }

  int trashSize = countTrashSize(bitsQuantity, frequency);
  int treeSize = countTreeSize(compressedTree);
  printf("Trash Size: %d || Tree Size: %d\n", trashSize, treeSize);

  unsigned char *header = createHeader(trashSize, treeSize, compressedTree);

  FILE *pFile = fopen("textoIn.txt", "rb");
  compressFile(pFile, header, dictionary, bitsQuantity, compressedTree);
  fclose(pFile);
}

void compressFile(FILE *pFile, unsigned char *header, bool dictionary[][256], int bitsQuantity[], huffTree_t *tree)
{
  FILE *newFile = fopen("textoOut.txt", "wb");
  fprintf(newFile, "%c%c", header[0], header[1]);
  printTreeInFile(newFile, tree);

  unsigned char byte = 0, newByte = 0; int pos = 0;
  while (fscanf(pFile, "%c", &byte) != EOF)
  {
    int i;
    for (i = 0; i < bitsQuantity[byte]; i ++, pos ++)
    {
      //printf("%d", dictionary[byte][i]);
      pos %= 8;
      if (dictionary[byte][i])
        newByte = setBit(newByte, 7 - pos);

      if ((pos + 1) % 8 == 0)
      {
        fprintf(newFile, "%c", newByte);
        //printByte(newByte, 8); printf(" ");
        newByte = 0;
      }
    } //printf(" ");
  }

  if (header[0] >> 5 != 0) // Se o trashSize for diferente de zero
  {
    fprintf(newFile, "%c", newByte);
    //printByte(newByte, 8);
  }
  printf("\n");
  fclose(newFile);
}
