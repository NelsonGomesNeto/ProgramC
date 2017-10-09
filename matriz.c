#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 10000

int cont=0;
int a[MAX][MAX];

void preenche(int y, int x,int n,int m)
{
	if (x < 0 || y < 0 || x>=m || y>=n)
	{
		return ;
	}

	if (a[y][x] == 0)
	{
		++cont;
		a[y][x]= 1;
		preenche(y+1,x+1,n,m);
		preenche(y+1,x,n,m);
		preenche(y+1,x-1,n,m);
		preenche(y,x+1,n,m);
		preenche(y,x-1,n,m);
		preenche(y-1,x+1,n,m);
		preenche(y-1,x,n,m);
		preenche(y-1,x-1,n,m);
	}

}

int main ()
{
	int n,m,x,y,k,i=0,j=0;
	scanf("%d\n%d\n",&m,&n);
	scanf("%d\n%d\n",&x,&y);
	scanf("%d\n",&k);
	int kx,ky;

	for (i = 0; i < n; ++i)
	{
		for (j = 0; j < m; ++j)
		{
			a[i][j]=0;
		}
	}

	i = 0;
	while(i<k)
	{
		//if (i==k) break;
		scanf("%d\n%d\n",&kx,&ky);
		a[n - ky - 1][kx - 1] = 1;
		printf("%d %d %d %d\n", n, m, n-ky - 1, kx - 1);
		++i;
	}

	preenche(y - 1,x - 1,n, m);

	printf("%d\n",cont);

}
