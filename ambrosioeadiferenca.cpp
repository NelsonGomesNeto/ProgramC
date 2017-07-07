#include <stdio.h>
#include <iostream>
using namespace std;

void contadif(unsigned long long int num, unsigned long long int *conta)
{
  if (num > 0)
  {
    contadif(num >> 1, &*conta);
    (*conta) += num & 1;
  }
}

int main()
{
  int tests; scanf("%d", &tests);
  while (tests > 0)
  {
    unsigned long long int a, b, bin;
    cin >> a;
    cin >> b;
    unsigned long long int dif = 0;
    contadif(a ^ b, &dif);
    printf("%Ld\n", dif);
    tests --;
  }
  return(0);
}
