#include <bits/stdc++.h>
#define lli long long int
lli mod = (lli) 1e9 + 7;
char n[101], sequence[100001];
int nSize, sequenceSize;

int comp(char a[], char b[])
{
  int endA = strlen(a), endB = strlen(b);
  if (endB > endA) return(0);
  if (endA > endB) return(1);
  for (int i = 0; i < endA; i ++)
    if (a[i] > b[i]) return(1);
    else if (a[i] < b[i]) return(0);
  return(0);
}

lli findAll(int i, int sequenceSize, int j, char now[])
{
  printf("%s %d %d %d\n", now, i, j, comp(now, n));
  if (j == 0 && sequence[i] == '0') return(0);
  if (comp(now, n)) return(0);
  if (i == sequenceSize) return(1);

  char aNew[101]; strcpy(aNew, now);
  char copy[101];
  lli ans = 0;
  if (!comp(now, n))
  {
    strcpy(copy, aNew);
    aNew[j] = sequence[i]; aNew[j + 1] = '\0';
    ans = (ans + findAll(i + 1, sequenceSize, j + 1, aNew)) % mod;
    strcpy(aNew, copy);

    if (sequence[i] == '0') return(ans);
    strcpy(copy, aNew);
    strcpy(aNew, copy);
    memset(aNew, 0, sizeof(aNew));
    ans = (ans + findAll(i + 1, sequenceSize, 0, aNew)) % mod;
  }

  // if (j != 0)
  // {
  //   strcpy(copy, aNew);
  //   memset(aNew, 0, sizeof(aNew));
  //   aNew[0] = sequence[i];
  //   ans = (ans + findAll(i + 1, sequenceSize, 1, aNew)) % mod;
  //   strcpy(aNew, copy);
  // }
  // else
  // {
  //   strcpy(copy, aNew);
  //   memset(aNew, 0, sizeof(aNew));
  //   //aNew[0] = sequence[i];
  //   ans = (ans + findAll(i + 1, sequenceSize, 0, aNew)) % mod;
  //   strcpy(aNew, copy);
  // }

  return(ans);
}

int main()
{
  scanf("%s\n%s", n, sequence);
  nSize = strlen(n); sequenceSize = strlen(sequence);

  char aux[101]; memset(aux, 0, sizeof(aux));
  lli ans = findAll(0, sequenceSize, 0, aux);

  printf("%lld\n", ans);

  return(0);
}