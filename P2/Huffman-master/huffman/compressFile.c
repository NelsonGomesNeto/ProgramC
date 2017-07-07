#include "compressFile.h"

unsigned char* createHeader(int trashSize, int treeSize)
{
  unsigned char *bytes = (unsigned char*) malloc(3 * sizeof(unsigned char));
  bytes[0] = trashSize << 5 | treeSize >> 8;
  bytes[1] = treeSize;

  return(bytes);
}

long long int countFutureFileSize(int bitsQuantity[], long long int frequency[])
{
  int i; long long int fileSize = 0;
	for(i = 0; i < 256; i ++)
		if(frequency[i] != -1)
			fileSize += (bitsQuantity[i] * frequency[i]);

  return(fileSize / 8 == (double) fileSize / 8 ? fileSize / 8 : (fileSize / 8) + 1);
}

long long int getFileSize(char pathFile[])
{
  FILE *pFile = fopen(pathFile, "rb");
  if (pFile == NULL)
    return(false);

  fseek(pFile, 0, SEEK_END);
  long long int fileSize = ftell(pFile);
  rewind(pFile);
  fclose(pFile);

  return(fileSize);
}

bool compress(char pathFile[], bool preventLoss)
{
  long long int fileSizeBefore = getFileSize(pathFile);

  printf("Creating Tree.........");
    HuffTree_t *compressedTree = createTreeFromFile(pathFile);
    if (isHuffTreeEmpty(compressedTree))
      return(false);
  printf("Creating Tree......... Done\n");

  printf("Creating Dictionary...");
    bool dictionary[256][256]; int bitsQuantity[256];
    long long int frequency[256]; int i;
    for(i = 0; i < 256; i ++)
      frequency[i] = -1;

    bool bits[256];
    createDictionary(compressedTree, dictionary, bitsQuantity, frequency, bits, 0);
  printf(" Done\n");

  printf("Creating Header.......");
    int trashSize = countTrashSize(bitsQuantity, frequency);
    int treeSize = countTreeSize(compressedTree);

    long long int fileSizeAfter = 2 + treeSize + countFutureFileSize(bitsQuantity, frequency);
    unsigned char *header = createHeader(trashSize, treeSize);
  printf(" Done\n");

  if (preventLoss)
  {
    printf("Calculating Size......");
      if (fileSizeBefore < fileSizeAfter)
      {
        free(header);
        destroyHuffTree(compressedTree);
        printf(" It's not worth it!\n");
        return(false);
      }
    printf(" Done\n");
  }

  printf("Compressing File......");
    compressFile(pathFile, header, dictionary, bitsQuantity, compressedTree);
  printf("Compressing File...... Done\n");
  printf("Compressed from %Ld to %Ld: %g%%\n", fileSizeBefore, fileSizeAfter, 100 - (100 * ((double) fileSizeAfter / fileSizeBefore)));

  free(header);
  destroyHuffTree(compressedTree);
  return(true);
}

void multipleCompress(char quantityString[], char pathFile[])
{
  long long int fileSizeBefore = getFileSize(pathFile);
  int quantity = atoi(quantityString);

  if (quantity <= 1)
    printf("Invalid quantity\n");
  else
  {
    compress(pathFile, false);
    updateProgress("Compressed once.......", ((double) 1 / quantity) * 100, false);
    strcat(pathFile, ".huff"); // Para comprimir a primeira compressão

    int i;
    for (i = 0; i < quantity - 1; i ++)
    {
      compress(pathFile, false);
      if (i == 0)
        updateProgress("Compressed twice.......", ((double) 2 / quantity) * 100, false);
      else
      {
        char progressString[100];
        sprintf(progressString, "Compressed %d times....", i + 2);
        updateProgress(progressString, ((double) (i + 2) / quantity) * 100, false);
      }
    }

    long long int fileSizeAfter = getFileSize(pathFile);
    printf("Compressed from %Ld to %Ld: %g%%\n", fileSizeBefore, fileSizeAfter, 100 - (100 * ((double) fileSizeAfter / fileSizeBefore)));
    printf("You've compressed %d times\n", quantity);
  }
}

void maxCompress(char pathFile[])
{
  long long int fileSizeBefore = getFileSize(pathFile);

  int compressions = 0;
  if (compress(pathFile, true))
  {
    compressions ++;
    strcat(pathFile, ".huff");
    printf("\n");

    while (compress(pathFile, true))
    {
      compressions ++;
      printf("\n");
    }
  }
  printf("Maximum compression reached, we needed %d compressions\n", compressions);

  if (compressions > 0)
  {
    long long int fileSizeAfter = getFileSize(pathFile);
    printf("Compressed from %Ld to %Ld: %g%%\n", fileSizeBefore, fileSizeAfter, 100 - (100 * ((double) fileSizeAfter / fileSizeBefore)));
  }
}

void compressFile(char pathFile[], unsigned char *header, bool dictionary[][256], int bitsQuantity[], HuffTree_t *tree)
{
  FILE *pFile = fopen(pathFile, "rb");
  long long int *progressBar = createProgressBar(pFile);

  char *compressedFileName = createCompressedFileName(pathFile);

  FILE *newFile = fopen(compressedFileName, "wb");
  fprintf(newFile, "%c%c", header[0], header[1]);
  printTreeInFile(newFile, tree);

  long long int progress = 0; int currentProgress = 0;
  unsigned char byte = 0, newByte = 0; int pos = 0;
  while (fscanf(pFile, "%c", &byte) != EOF)
  {
    int i;
    for (i = 0; i < bitsQuantity[byte]; i ++, pos ++)
    {
      pos %= 8;
      if (dictionary[byte][i])
        newByte = setBit(newByte, 7 - pos);

      if ((pos + 1) % 8 == 0)
      {
        fprintf(newFile, "%c", newByte);
        newByte = 0;
      }
    }
    if (progressBar[currentProgress] == progress)
      updateProgress("Compressing File......\0", currentProgress ++, true);

    progress ++;
  }

  if (header[0] >> 5 != 0) // Se o trashSize for diferente de zero
    fprintf(newFile, "%c", newByte);

  free(progressBar);
  fclose(newFile);
  fclose(pFile);
  fixCompressExtension(compressedFileName);
  free(compressedFileName);
}

void createDictionary(HuffTree_t *tree, bool dictionary[][256], int bitsQuantity[], long long int frequency[], bool bits[], int depth)
{
	if(!isHuffTreeEmpty(tree))
	{
		if (isHuffTreeEmpty(getLeft(tree)) && isHuffTreeEmpty(getRight(tree)))
		{
      int i;
      for (i = 0; i < depth; i ++)
        dictionary[getByte(tree)][i] = bits[i];

      bitsQuantity[getByte(tree)] = depth;
      frequency[getByte(tree)] = getFrequency(tree);
		}
		else
		{
			bits[depth] = 0;
			createDictionary(getLeft(tree), dictionary, bitsQuantity, frequency, bits, depth + 1);
			bits[depth] = 1;
			createDictionary(getRight(tree), dictionary, bitsQuantity, frequency, bits, depth + 1);
		}
	}
}

char* createCompressedFileName(char pathFile[])
{
  int endOfName = strlen(pathFile);
  int i, j;
  for (i = endOfName; i >= 0 && pathFile[i] != '\\';)
    i --;

  i ++;
  char *newFileName = (char*) malloc(100 * sizeof(char));
  for (j = 0; i < endOfName; j ++, i ++)
    newFileName[j] = pathFile[i];

  newFileName[j] = '\0';
  strcat(newFileName, ".huff");

  return(newFileName);
}

void fixCompressExtension(char pathFile[])
{
  char *originalName = (char*) malloc(100 * sizeof(char));
  strcpy(originalName, pathFile);

  int endOfName = strlen(pathFile);
  int i = endOfName, j;
  j = 5; char dotHuff[6] = {'.', 'h', 'u', 'f', 'f', '\0'};
  while (i >= 0 && pathFile[i] == dotHuff[j])
  {
    i --; j --;
    if (j == -1)
      j = 4;
  }

  pathFile[i + (5 - j)] = '\0';
  strcat(pathFile, ".huff");

  if (strcmp(originalName, pathFile) != 0)
    remove(pathFile);

  rename(originalName, pathFile);

  free(originalName);
}
