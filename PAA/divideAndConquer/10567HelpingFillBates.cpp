#include <bits/stdc++.h>
#define DEBUG if(0)
using namespace std;
int letters[256][(int) 1e6 + 1];

int binSearch(int array[], int lo, int hi, int target, int minus)
{
  int mid = (lo + hi) / 2;
  printf("%d %d %d\n", lo, hi, array[lo]);
  if (lo >= hi) return(array[lo] - minus >= target ? lo : -1);
  if (target <= array[mid] - minus) return(binSearch(array, lo, mid, target, minus));
  else return(binSearch(array, mid + 1, hi, target, minus));
}

int main()
{
  string s;
  cin >> s;
  DEBUG for (int i = 0; s[i]; i ++)
    printf("(%c, %d) ", s[i], i);
  DEBUG printf("\n");

  memset(letters, 0, sizeof(letters));
  for (int i = 'a'; i <= 'z'; i ++)
    for (int j = 0, q = 0; s[j]; j ++)
    {
      q += s[j] == i;
      letters[i][j] = q;
    }
  for (int i = 'A'; i <= 'Z'; i ++)
    for (int j = 0, q = 0; s[j]; j ++)
    {
      q += s[j] == i;
      letters[i][j] = q;
    }

  int queries; scanf("%d", &queries);
  while (queries -- > 0)
  {
    string ss;
    getchar(); cin >> ss;
    int at = 0, first = -1, last = -1;
    for (int i = 0; ss[i];)
    {
      char prev = ss[i]; int quantity = 0;
      while (ss[i ++] && ss[i - 1] == prev) quantity ++;
      int pos = binSearch(letters[prev], at, s.size() - 1, quantity, !at ? 0 : letters[prev][at]);
      DEBUG printf("Searching (%c, %d) %d\n", prev, quantity, pos);
      last = pos;
      if (pos == -1) break;
      else at = pos;
      if (first == -1) first = pos;
    }
    if (last != -1)
      printf("Matched %d %d\n", first, last);
    else
      printf("Not Matched\n");
  }

  return(0);
}