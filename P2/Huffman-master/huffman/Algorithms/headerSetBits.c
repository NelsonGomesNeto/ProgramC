#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

unsigned int setBit(unsigned int byte, int i)
{
  unsigned int mask = 1 << i;
  return(mask | byte);
}

bool isBitiSet(unsigned int byte, int i)
{
  unsigned int mask = 1 << i;
  return(mask & byte);
}

void decimalToBinary(unsigned int num, unsigned int *byte, int pos, int end)
{
  if (pos == end) return;

  //printf("%d", isBitiSet(num, pos));
  if (isBitiSet(num, pos))
    (*byte) = setBit((*byte), pos);

  decimalToBinary(num, &(*byte), pos + 1, end);
}

void putBytes(unsigned char *byte, unsigned int num, int posByte, int posInt, int TobeSetted)
{
  int setted;
  for (setted = 0; setted < TobeSetted; setted ++, posByte ++, posInt ++)
  {
    //printf("%d", isBitiSet(num, posInt));
    if (isBitiSet(num, posInt))
      (*byte) = setBit((*byte), posByte);
  }
  //printf("\n");
}

void printByte(unsigned char byte)
{
  int i;
  for (i = 7; i >= 0; i --)
    printf("%d", isBitiSet(byte, i));

  printf("\n");
}

unsigned char* createHeader(int trashSize, int treeSize)
{
  unsigned char *bytes = (unsigned char*) malloc(3 * sizeof(unsigned char));
  // bytes[0] = bytes[1] = 0; bytes[2] = '\0';
  // putBytes(&bytes[0], trashSize, 5, 0, 3); // Trash
  // putBytes(&bytes[0], treeSize, 0, 8, 5); // Trash - Tree
  // putBytes(&bytes[1], treeSize, 0, 0, 8); // Tree
  bytes[0] = trashSize << 5 | treeSize >> 8;
  bytes[1] = treeSize;
  bytes[2] = '\0';

  printf("%c%c", bytes[0], bytes[1]);
  printByte(bytes[0]);
  printByte(bytes[1]);
  return(bytes);
}

int main()
{
  unsigned int trashSize, treeSize; scanf("%d %d", &trashSize, &treeSize);
  unsigned char trashByte, treeByte;
  trashByte = trashSize << 5 | treeSize >> 8;
  treeByte = treeSize;
  //printByte(trashByte); printByte(treeByte);
  unsigned char *header = createHeader(trashSize, treeSize);
  printf("%s\n", header);
  FILE *pFile = fopen("headOut", "rb");
  fscanf(pFile, "%c%c", &trashByte, &treeByte);
  printByte(trashByte);
  printByte(treeByte);
  return(0);
}
