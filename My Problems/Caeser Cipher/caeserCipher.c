#include <stdio.h>


void encode(char destination[], char origin[])
{
  int a = 0, b = 1, i;
  for (i = 0; origin[i]; i ++)
  {
    if (origin[i] < 'a' || origin[i] > 'z') continue;
    destination[i] = 256 + (origin[i] - a) % 256;
    int aux = a;
    a = b; b = (aux + b) % mod;
  }
  destination[i] = '\0';
}

void decode(char destination[], char origin[])
{
  int a = 0, b = 1, i;
  for (i = 0; origin[i]; i ++)
  {
    if (origin[i] < 'a' || origin[i] > 'z') continue;
    destination[i] = (origin[i] + a) % 256;
    if (destination[i] == '\n') i --;
    int aux = a;
    a = b; b = (aux + b) % mod;
  }
  destination[i] = '\0';
}

int main()
{
  int commands; scanf("%d", &commands);
  while (commands --)
  {
    char kind; scanf("\n%c", &kind);
    char string[100000]; scanf("\n%[^\n]", string);
    char final[100000];
    if (kind == 'E')
      encode(final, string);
    else // D
      decode(final, string);
    printf("%s\n", final);
  }
  return(0);
}
