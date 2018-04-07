#include <bits/stdc++.h>
using namespace std;

void giveChange(int kind[], int money)
{
  printf("Change: $%d\n", money);
  for (int i = 3; i >= 0; i --)
  {
    printf("%d of $%d\n", money / kind[i], kind[i]);
    money %= kind[i];
  }
  printf("Tip: $%d\n", money);
}

int main()
{
  int t = 0, tests; scanf("%d", &tests);
  while (t < tests)
  {
    if (t ++) printf("\n");

    int kind[4];
    for (int i = 0; i < 4; i ++) scanf("%d", &kind[i]);
    sort(kind, kind+4);

    int money; scanf("%d", &money);

    printf("Costumer %d:\n", t);
    giveChange(kind, money);
  }

  return(0);
}
