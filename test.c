#include <stdio.h>

int main()
{
	int h, m, h2, m2;
	h=m=h2=m2=1;

	while(h!=0 || m!=0 || h2!=0 || m2!=0)
	{
		int cont = 0;
		scanf("%d%d%d%d", &h, &m, &h2, &m2);

		while(h!=h2 && m!=m2)
		{
			printf("%d %d %d %d\n", h, m, h2, m2);
			m+=1;
			cont++;
			if(m==60)
			{
				m=0;
				h+=1;
				h=h%24;
			}
		}
		printf("%d\n", cont);
	}

	return 0;
}
