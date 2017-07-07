#include <stdio.h>
#include <string.h>

int main()
{
  char num[99]; scanf("%s", num);
  int check, pares = 0;
  for (check = 0; check < strlen(num); check ++)
  {
    //printf("%d\n", (int) num[check] - 48);
    if ((int) (num[check] - 48) % 2 == 0)
    {
      pares ++;
    }
  }
  printf("%d\n", pares);
  return(0);
}
