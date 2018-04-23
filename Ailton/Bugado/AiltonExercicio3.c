#include <stdio.h>

int main()
{
  int n, repeat; unsigned long long int seq, pot; char continua;
  do
  {
    seq = 0; pot = 1;
    scanf("%d", &n);
    for (repeat = 0; repeat < n; repeat ++)
    {
      seq += pot;
      if (seq == -1)
      {
        printf("Limite estourado!\n");
        break;
      }
      else
      {
        printf("%Ld\n", seq);
      }
      pot *= 2;
    }
    printf("Desejas continuar? (S/N): ");
  } while (getchar() && scanf("%c", &continua) && !(continua == 'N' || continua == 'n'));
  return(0);
}
