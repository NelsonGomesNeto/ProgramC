#include <bits/stdc++.h>

struct lol
{
  int miau;
};

int main()
{
  struct lol *a = (struct lol*) malloc(1*sizeof(struct lol));
  (*a).miau = 1;
  printf("%d %d\n", (*a).miau, a->miau);
  return(0);
}
