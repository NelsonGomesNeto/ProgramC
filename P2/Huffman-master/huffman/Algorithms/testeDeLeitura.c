#include <stdio.h>

int main()
{
  unsigned char bytes;
  FILE *pFile, *newFile;
  pFile = fopen("fotoIn.jpg", "rb");
  newFile = fopen("fotoOut.jpg", "w");
  while (fscanf(pFile, "%c", &bytes) != EOF)
    fprintf(newFile, "%c", bytes);

  return(0);
}
