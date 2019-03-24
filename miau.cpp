#include <bits/stdc++.h>
using namespace std;

struct LoL
{
  int num;
};
bool l(const LoL &a, const LoL &b) { return(a.num < b.num); }
bool g(const LoL &a, const LoL &b) { return(a.num > b.num); }

int main()
{
  int n; scanf("%d", &n);
  LoL array[n];
  for (int i = 0; i < n; i ++) scanf("%d", &array[i].num);
  sort(array, array+n, l);
  return(0);
}