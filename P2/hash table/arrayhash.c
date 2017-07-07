#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>

int hashFunction(char string[], int key)
{
  int valor = 0, i, tam = strlen(string);
  for (i = 0; i < tam; i ++)
    valor += ((string[i] - 65) + key + i);

  return(valor);
}

int main()
{
  int tests, run; scanf("%d", &tests);
  for (run = 0; run < tests; run ++)
  {
    int linhas;
    scanf("%d", &linhas);
    int hashes = 0, element;
    for (element = 0; element < linhas; element ++)
    {
      char string[51];
      scanf("%s", string);
      hashes += hashFunction(string, element);
    }
    printf("%d\n", hashes);
  }
  return(0);
}
