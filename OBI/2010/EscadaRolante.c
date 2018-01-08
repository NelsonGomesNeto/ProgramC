#include <stdio.h>

int main()
{
  int people, at, on = 0, now = -1;
  scanf("%d", &people);

  while (people -- > 0)
  {
    scanf("%d", &at);
    if (at < now + 10 && now != -1)
      on += at - now;
    else
      on += 10;
    now = at;
  }

  printf("%d\n", on);

  return(0);
}