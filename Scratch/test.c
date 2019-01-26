#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* func()
{
  char *string = (char*) malloc(10 * sizeof(char));
  strcat(string, "miau\0");
  return(string);
}

int main()
{
  char *string = func();
  printf("%s\n", string);
  return(0);
}