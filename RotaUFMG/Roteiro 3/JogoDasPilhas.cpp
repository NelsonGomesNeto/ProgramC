#include <bits/stdc++.h>
int n;

int choose(int pile[][3], int i, int j, int k);

int canWin(int pile[][3], int i, int j, int k)
{
  if (i == n && j == n && k == n) return(1);

  if (choose(pile, i, j, k)) return(1);
}

int main()
{
  while (scanf("%d", &n) && n)
  {
    int pile[n][3];
    for (int i = 0; i < n; i ++)
      for (int j = 0; j < 3; j ++)
        scanf("%d", &pile[i][j]);

    int can = canWin(pile, 0, 0, 0);
    printf("%d\n", can);
  }
  return(0);
}

int choose(int pile[][3], int i, int j, int k)
{
  
}