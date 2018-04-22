#include <bits/stdc++.h>
using namespace std;

void read(int a[], int size)
{
	for (int i = 0; i < size; i ++)
		scanf("%d", &a[i]);
  sort(a, a+size);
}

int main()
{
	int na, nb; scanf("%d %d", &na, &nb);
	int k, m; scanf("%d %d", &k, &m);
	int a[na], b[nb];
  read(a, na);
  read(b, nb);

	printf("%s\n", a[k - 1] < b[nb - m] ? "YES" : "NO");

	return(0);
}