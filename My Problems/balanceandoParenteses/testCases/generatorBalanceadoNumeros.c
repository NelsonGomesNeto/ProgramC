#include <stdio.h>
#include <string.h>

int main()
{
  int open, close, file = 1;
  while (scanf("%d %d\n", &open, &close) != EOF)
  {
    char name[10];
    sprintf(name, "%d.in", file);
    FILE *pFile = fopen(name, "wb");

    char seq[1000]; scanf("%s", seq);
    fprintf(pFile, "%d %d %d\n", open, close, (int)strlen(seq));

    int i;
    for (i = 0; seq[i] != '\0'; i ++)
    {
      if (seq[i] == '(')
        fprintf(pFile, "%d ", open);
      else
        fprintf(pFile, "%d ", close);
    }

    fclose(pFile);
    file ++;
  }
  return(0);
}