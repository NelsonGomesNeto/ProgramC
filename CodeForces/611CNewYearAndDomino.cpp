#include <bits/stdc++.h>
int y, x;
char board[501][501];
int left[501][501], right[501][501];

int main()
{
  scanf("%d %d", &y, &x);
  for (int i = 0; i < y; i ++)
  {
    getchar();
    scanf("%s", board[i]);
  }

  int l, r;
  for (int i = 0; i < y; i ++)
  {
    l = board[i][0] == '.'; r = board[i][y - 1] == '.';
    for (int j = 1; j < x; j ++)
    {
      if (board[i][y - 1 - j] == '.') r ++;
      else r = 0;
      if (board[i][j] == '.') l ++;
      else l = 0;
      left[i][j] = (l > 1) + left[i][j - 1];
      right[i][y - 1 - j] = (r > 1) + right[i][y - j];
    }
  }
  for (int i = 0; i < x; i ++)
  {
    l = board[0][i] == '.'; r = board[y - 1][i] == '.';
    for (int j = 1; j < y; j ++)
    {
      if (board[y - 1 - j][i] == '.') r ++;
      else r = 0;
      if (board[j][i] == '.') l ++;
      else l = 0;
      left[j][i] = (l > 1) + left[j - 1][i];
      right[y - 1 - j][i] = (r > 1) + right[y - j][i];
    }
  }

  for (int i = 0; i < y; i ++)
    for (int j = 0; j < x; j ++)
      printf("%d%c", left[i][j], j < x - 1 ? ' ' : '\n');
  printf("\n");
  for (int i = 0; i < y; i ++)
    for (int j = 0; j < x; j ++)
      printf("%d%c", right[i][j], j < x - 1 ? ' ' : '\n');

  int queries, q; scanf("%d", &queries);
  while (queries -- > 0)
  {
    scanf("%d", &q);
    int li, lf, hi, hf; scanf("%d %d %d %d", &li, &lf, &hi, &hf);
    li --; lf --; hi --; hf --;
    printf("%d\n", (right[lf][hf] - right[li][hi]) - (left[lf][hf] - left[li][hi]));
  }


  return(0);
}