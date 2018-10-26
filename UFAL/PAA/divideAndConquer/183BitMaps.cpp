#include <bits/stdc++.h>
using namespace std;
#define DEBUG if(0)
int bitmap[200][200 + 1], at, compressed[(int) 1e6]; char bit;

void compress(int loi, int hii, int loj, int hij)
{
  DEBUG printf("%d %d %d %d\n", loi, hii, loj, hij);
  if (loi > hii || loj > hij) return;
  int num = bitmap[loi][loj], only = 1;
  for (int i = loi; i <= hii; i ++)
    for (int j = loj; j <= hij; j ++)
      if (num != bitmap[i][j]) only = 0;
  if (only) compressed[at ++] = num + '0';
  else
  {
    compressed[at ++] = 'D';
    int midi = (loi + hii) / 2, midj = (loj + hij) / 2;
    compress(loi, midi, loj, midj);
    compress(loi, midi, midj + 1, hij);
    compress(midi + 1, hii, loj, midj);
    compress(midi + 1, hii, midj + 1, hij);
  }
}

void decompress(int loi, int hii, int loj, int hij)
{
  if (loi > hii || loj > hij) return;
  DEBUG printf("%d %d %d %d\n", loi, hii, loj, hij);
  scanf("%c", &bit);
  if (bit == 'D')
  {
    int midi = (loi + hii) / 2, midj = (loj + hij) / 2;
    decompress(loi, midi, loj, midj);
    decompress(loi, midi, midj + 1, hij);
    decompress(midi + 1, hii, loj, midj);
    decompress(midi + 1, hii, midj + 1, hij);
  }
  else
  {
    for (int i = loi; i <= hii; i ++)
      for (int j = loj; j <= hij; j ++)
        bitmap[i][j] = bit - '0';
  }
}

int main()
{
  char kind;
  while (scanf("%c", &kind) && kind != '#')
  {
    int y, x; scanf("%d %d\n", &y, &x);
    printf("%c %s%d %s%d\n", kind == 'B' ? 'D' : 'B', y > 99 ? "\0" : y > 9 ? " " : "  ", y, x > 99 ? "\0" : x > 9 ? " " : "  ", x);
    if (kind == 'B')
    {
      for (int i = 0; i < y; i ++)
        for (int j = 0; j < x; j ++)
          scanf("%01d", &bitmap[i][j]);
      at = 0;
      compress(0, y - 1, 0, x - 1);
      for (int i = 0; i < at; i ++)
        printf("%c%s", compressed[i], !((i + 1) % 50) ? "\n" : "\0");
      if ((at) % 50) printf("\n");
    }
    if (kind == 'D')
    {
      decompress(0, y - 1, 0, x - 1); at = 1;
      for (int i = 0; i < y; i ++)
        for (int j = 0; j < x; j ++, at ++)
          printf("%01d%s", bitmap[i][j], (at && !(at % 50)) ? "\n" : "\0");
      if ((at - 1) % 50) printf("\n");
    }
    getchar();
  }
  return(0);
}