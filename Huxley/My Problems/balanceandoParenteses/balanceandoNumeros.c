#include <stdio.h>

int main()
{
  int open, close, size; scanf("%d %d %d", &open, &close, &size);

  int stack = 0, digit, valid = 1;
  while (scanf("%d", &digit) != EOF)
  {
    if (open == digit)
      stack ++;
    if (close == digit)
      stack --;
    if (stack < 0)
      valid = 0;
  }
  if (valid == 0 || stack != 0)
    printf("Desbalanceada!");
  else
    printf("Balanceada!");

  return(0);
}