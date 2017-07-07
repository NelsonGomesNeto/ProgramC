#include <stdio.h>

void swap(int *a, int *b)
{
  int aux = *a;
  *a = *b;
  *b = aux;
}

void sort(int array[])
{
  int o, b;
  for (o = 0; o < 256; o ++)
    for (b = o + 1; b < 256;  b ++)
      if (array[o] > array[b])
        swap(&array[o], &array[b]);
}

int main()
{
  unsigned char bytes;
  FILE *pFile, *newFile;
  pFile = fopen("musicIn.mp3", "rb");
  newFile = fopen("musicOut.mp3", "w");

  int freq[255], i;
  for (i = 0; i < 256; i ++)
    freq[i] = 0;

  int soma = 0;
  while (fscanf(pFile, "%c", &bytes) != EOF)
  {
    fprintf(newFile, "%c", bytes);
    freq[bytes] ++; soma ++;
  }

  sort(freq);

  for (i = 0; i < 256; i ++)
    if (freq[i] != 0)
      printf("%c ~~ %d\n", i, freq[i]);

  printf("Total de Bytes: %d\n", soma);
  return(0);
}
