#include <bits/stdc++.h>
#define lli long long int
#define DEBUG if(0)

int createSegmentTree(char letter, int segmentTree[], char array[], int i, int lo, int hi)
{
  if (lo == hi)
  {
    segmentTree[i] = (letter == array[lo]);
    return(segmentTree[i]);
  }
  else if (lo > hi) return(0);

  int mid = (lo + hi) / 2;
  segmentTree[i] = createSegmentTree(letter, segmentTree, array, 2*i + 1, lo, mid) + createSegmentTree(letter, segmentTree, array, 2*i + 2, mid + 1, hi);
  return(segmentTree[i]);
}

int gs(int segmentTree[], int i, int lo, int hi, int qlo, int qhi)
{
  if (lo >= qlo && hi <= qhi) return(segmentTree[i]);
  else if (hi < qlo || lo > qhi) return(0);
  int mid = (lo + hi) / 2;
  return(gs(segmentTree, 2*i + 1, lo, mid, qlo, qhi) + gs(segmentTree, 2*i + 2, mid + 1, hi, qlo, qhi));
}

int getSum(int segmentTree[], int size, int lo, int hi)
{
  if (lo < 0 || hi > size - 1 || lo > hi) return(-1);
  return(gs(segmentTree, 0, 0, size - 1, lo, hi));
}

void uv(int segmentTree[], int i, int diff, int lo, int hi, int pos)
{
  if (lo > pos || hi < pos) return;
  segmentTree[i] += diff;
  if (lo != hi)
  {
    int mid = (lo + hi) / 2;
    uv(segmentTree, 2*i + 1, diff, lo, mid, pos);
    uv(segmentTree, 2*i + 2, diff, mid + 1, hi, pos);
  }
}

int main()
{
  int size, queries; scanf("%d %d", &size, &queries);
  char string[size]; scanf("%s", string);

  int **segmentTree = (int**) malloc(26 * sizeof(int*)), i, j;
  for (i = 0; i < 26; i ++)
  {
    segmentTree[i] = (int*) malloc((2 * (lli) pow(2, (lli) log2(size) + 1) - 1) * sizeof(int));
    createSegmentTree('a' + i, segmentTree[i], string, 0, 0, size - 1);
    DEBUG {
      printf("#%c#", 'a' + i);
      for (j = 0; j < 2 * (lli) pow(2, (lli) log2(size) + 1) - 1; j ++)
        printf("%d ", segmentTree[i][j]);
      printf("\n");
    }
  }

  int command, lo, hi; char letter;
  for (i = 0; i < queries; i ++)
  {
    scanf("%d", &command);
    if (command == 1) // update
    {
      scanf("%d %c", &lo, &letter);
      if (string[lo - 1] != letter)
      {
        uv(segmentTree[string[lo - 1] - 'a'], 0, 1, 0, size - 1, lo - 1);
        uv(segmentTree[letter - 'a'], 0, 1, 0, size - 1, lo - 1);
        string[lo - 1] = letter;
      }
    }
    else
    {
      scanf("%d %d", &lo, &hi);
      int odds = 0;
      for (j = 0; j < 26; j ++)
      {
        DEBUG printf("%c %d\n", 'a' + j, getSum(segmentTree[j], size, lo - 1, hi - 1));
        odds += getSum(segmentTree[j], size, lo - 1, hi - 1) & 1;
        if (odds > 1) break;
      }
      printf("%s\n", odds < 2 ? "yes" : "no");
    }
  }

  return(0);
}