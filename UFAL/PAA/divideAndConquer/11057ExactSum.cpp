#include <bits/stdc++.h>
using namespace std;

int binSearch(int array[], int lo, int hi, int target)
{
  int mid = (lo + hi) / 2;
  if (lo >= hi) return(array[lo] == target ? lo : -1);
  if (target <= array[mid]) return(binSearch(array, lo, mid, target));
  else return(binSearch(array, mid + 1, hi, target));
}

int main()
{
  int books, run = 0;
  while (scanf("%d", &books) != EOF)
  {
    int price[books];
    for (int i = 0; i < books; i ++)
    scanf("%d", &price[i]);
    sort(price, price + books);
    int wanted; scanf("%d", &wanted);

    int diff = 1e9, b[2];
    for (int i = 0; i < books && price[i] <= wanted; i ++)
    {
      int pos = binSearch(price, 0, books - 1, wanted - price[i]);
      if (pos != -1 && abs(price[i] - price[pos]) < diff)
      {
        diff = abs(price[i] - price[pos]);
        b[0] = price[i]; b[1] = price[pos];
      }
    }

    sort(b, b+2);
    printf("Peter should buy books whose prices are %d and %d.\n\n", b[0], b[1]);
  }

  return(0);
}