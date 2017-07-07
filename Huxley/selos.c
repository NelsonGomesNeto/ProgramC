#include <stdio.h>
#include <math.h>

int main()
{
  long long int selos; int check;
  scanf("%Ld\n", &selos);
  for (check = 2; check < sqrt(selos); check ++)
  {
    if (selos % check == 0)
    {
      printf("S\n");
      return(0);
    }
  }
  printf("N\n");
  return(0);
}
