#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n; scanf("%d", &n);
	int groups = 0, prev = -1, magnet, biggest = 0, now = 1;
	while (n --)
	{
		scanf("%d", &magnet);
		if (prev != magnet)
		{
			groups ++;
			if (prev != -1) now = 0;
		}
		else now ++;

		biggest = max(biggest, now);
		prev = magnet;
	}
	printf("groups: %d, biggest: %d\n", groups, biggest);

	return(0);
}