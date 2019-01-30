#include <bits/stdc++.h>
using namespace std;

struct Num
{
  int num;
  bool operator<(const Num &a) const { return(num < a.num); }
};

int main()
{
  Num one = {1}, two = {2};
  vector<Num> lol = {{1}, {2}};
  sort(lol.begin(), lol.end());
  printf("%d\n", (int) (one < two));
  printf("%d %d\n", lol[0].num, lol[1].num);
  return(0);
}
