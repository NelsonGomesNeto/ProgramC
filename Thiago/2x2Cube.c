#include <stdio.h>
#include "cube.h"

int main()
{
  printMapping();
  resetCube();
  printCube();

  char command[100];
  while (scanf("%s", command) != EOF)
  {
    getchar();
    printf("Command: %s\n\n", command);
    execCommand(command);
    printCube();
  }
  return(0);
}