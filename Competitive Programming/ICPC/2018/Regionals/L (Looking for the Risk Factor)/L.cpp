#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e5, allPrimes = 1e4;
bool notPrime[maxN + 1];
vector<int> primes;
int memoSmall[200][maxN + 1], memo[100 + 1][maxN + 1], biggestDivisor[maxN + 1];

int findPos(vector<int> &array, int target)
{
  int pos = lower_bound(array.begin(), array.end(), target) - array.begin();
  return(pos - (array[pos] > target));
}

int main()
{
  notPrime[0] = notPrime[1] = true;
  for (int i = 2; i <= maxN; i ++) for (int j = 2; i*j <= maxN; j ++) notPrime[i*j] = true;
  for (int i = 2; i <= maxN; i ++) if (!notPrime[i]) primes.push_back(i);

  for (int i = 2; i <= maxN; i ++)
  {
    if (notPrime[i])
    {
      int end = sqrt(i);
      for (int &p: primes)
      {
        if (p > end) break;
        if (i % p == 0) biggestDivisor[i] = max(biggestDivisor[i], max(p, biggestDivisor[i / p]));
      }
    }
    else
      biggestDivisor[i] = i;
  }

  for (int j = 1; j <= 100; j ++)
  {
    for (int n = 2; n <= j*1000; n ++) memo[j][n] = n - 1;
    for (int n = j*1000 + 1; n <= maxN; n ++) memo[j][n] = memo[j][n - 1] + (biggestDivisor[n] <= j*1000);
  }
  for (int p = 0; primes[p] < 1000; p ++)
  {
    for (int n = 2; n <= primes[p]; n ++) memoSmall[p][n] = n - 1;
    for (int n = primes[p] + 1; n <= maxN; n ++) memoSmall[p][n] = memoSmall[p][n - 1] + (biggestDivisor[n] <= primes[p]);
  }

  int q; scanf("%d", &q);
  while (q --)
  {
    int n, k; scanf("%d %d", &n, &k);
    if (k < 1000) printf("%d\n", memoSmall[findPos(primes, k)][n]);
    else
    {
      int m = k / 1000;
      int ans = memo[m][n];
      for (int i = findPos(primes, m*1000) + 1; i < primes.size() && primes[i] <= k; i ++)
        ans += n / primes[i];
      printf("%d\n", ans);
    }
  }
  return(0);
}