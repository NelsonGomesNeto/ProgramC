#include <bits/stdc++.h>
using namespace std;

struct Card
{
  int suit, value;
  void print() { printf("suit: %d, value: %d\n", suit, value); }
  bool operator<(const Card &c) const { return(value < c.value || (value == c.value && suit < c.suit)); }
  bool sameSuit(Card &c)
  {
    return(suit == c.suit && ((value + 1) % 13 == c.value || value == (c.value + 1) % 13));
  }
  bool sameValue(Card &c)
  {
    return(value == c.value && (suit != c.suit));
  }
};
Card cards[52], user[52]; int usersz;

bool got[52];
Card group[9], best[9]; int bestsz;

bool usefull(int i, int k)
{
  if (i % 3 == 0) return(true);
  if (i % 3 == 1)
  {
    if (group[i - 1].sameSuit(user[k])) return(true);
    if (group[i - 1].sameValue(user[k])) return(true);
  }
  if (i % 3 == 2)
  {
    if (group[i - 2].sameSuit(group[i - 1]) && group[i - 1].sameSuit(user[k]) && group[i - 2].value != user[k].value) return(true);
    if (group[i - 2].sameValue(group[i - 1]) && group[i - 1].sameValue(user[k]) && group[i - 2].sameValue(user[k])) return(true);
  }
  return(false);
}

void saveBest(int sz)
{
  bestsz = sz;
  for (int i = 0; i < sz; i ++) best[i] = group[i];
  for (int k = 0, i = sz; k < usersz; k ++)
    if (!got[k])
      best[i ++] = user[k];
}

bool solve(int i = 0)
{
  if (i > bestsz) saveBest(i);
  if (i == 9) return(true);

  for (int k = 0; k < usersz; k ++)
    if (!got[k] && usefull(i, k))
    {
      got[k] = true;
      group[i] = user[k];
      if (solve(i + 1))
        return(true);
      got[k] = false;
    }

  return(false);
}

int main()
{
  srand(time(NULL));

  for (int i = 0; i < 4; i ++)
    for (int j = 0; j < 13; j ++)
      cards[i*13 + j] = {i, j};

  // for (int i = 0; i < 52; i ++) swap(cards[i], cards[rand() % 52]);

  scanf("%d", &usersz);
  for (int i = 0, a; i < usersz; i ++)
  {
    scanf("%d", &a);
    user[i] = cards[a - 1];
  }

  sort(user, user+usersz);
  for (int i = 0; i < usersz; i ++)
    user[i].print();

  bestsz = 0;
  bool can = solve();
  printf("%s\n", can ? "YES" : "NO");
  
  printf("bestsz: %d\n", bestsz);
  for (int i = 0; i < usersz; i ++)
  {
    if (i % 3 == 0) printf("Group %d:\n", i / 3);
    printf("\t"); best[i].print();
  }

  return(0);
}