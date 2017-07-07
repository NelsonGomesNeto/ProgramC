#include <stdio.h>

int main()
{
  FILE *original = fopen("textoIn.txt", "rb");
  FILE *huffed = fopen("decompressed.txt", "rb");
  unsigned char originalByte;
  while (fscanf(original, "%c", &originalByte) != EOF)
  {
    unsigned char decompressedByte;
    if (fscanf(huffed, "%c", &decompressedByte) == EOF || decompressedByte != originalByte)
    {
      printf("ETA POARR T-T\n");
      return(1);
    }
  }
  printf("FOI POARR!!!!!\n");
  fclose(original);
  fclose(huffed);
  return(0);
}
