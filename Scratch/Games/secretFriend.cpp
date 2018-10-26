#include <bits/stdc++.h>
using namespace std;

int main()
{
  srand(time(NULL));

  int friends;
  printf("How many friends are there: "); scanf("%d", &friends);
  string name[friends];
  for (int i = 0; i < friends; i ++)
  {
    getchar();
    printf("%d friend: ", i + 1);
    cin >> name[i];
  }

  char end;
  while (scanf("%c", &end) != EOF)
  {
    printf("Shuffling...\n");
    random_shuffle(name, name + friends);

    printf("Merry Xmas\n\n");
    for (int i = (int) rand() % friends, all = 0; all < friends; all ++, i ++)
    {
      i %= friends;
      cout << name[i] << " got: " << name[(i + 1) % friends] << endl;
    }
  }
  return(0);
}