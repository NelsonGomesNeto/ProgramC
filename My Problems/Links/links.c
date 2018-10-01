#include <stdio.h>
#include <math.h>

void printLinks(char link[], int il[], int i, int has)
{
  if (i == has)
  {
    printf("%s\n", link);
    return;
  }
  link[il[i]] = 'I';
  printLinks(link, il, i + 1, has);
  link[il[i]] = 'l';
  printLinks(link, il, i + 1, has);
}

int main()
{
  int tests, run = 0; scanf("%d", &tests);
  while (run ++ < tests)
  {
    if (run > 1) printf("\n");
    getchar();
    char link[1000]; scanf("%s", link);
    int il[1000], i, has = 0;
    for (i = 0; link[i]; i ++)
      if (link[i] == 'I' || link[i] == 'l')
        il[has ++] = i;

    printf("There are %d possible links\n", (int) pow(2, has));
    printLinks(link, il, 0, has);
  }
  return(0);
}