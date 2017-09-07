#include <stdio.h>

int getSize(int a[])
{
	int i;
	for (i = 99999; i >= 0; i --)
		if (a[i] != 0)
			return(i + 1);

	return(1);
}

void printArray(int a[])
{
	int i, size = getSize(a);
	for (i = size - 1; i >= 0; i --)
	{
		printf("%d", a[i]);
	} printf("\n");
}

void revert(int a[])
{
	int i, j, aux, size = getSize(a);
	for (i = 0, j = size - 1; i != j; i ++, j --)
	{
		aux = a[i];
		a[i] = a[j];
		a[j] = aux;
	}
}

void mult(int a[], int b[])
{
	int i, j, aux, sizeA = getSize(a), sizeB = getSize(b);
	int t[100000];
	for (i = 0; i < 100000; i ++)
		t[i] = 0;

	for (i = 0; i < sizeB; i ++)
	{
		for (j = 0; j < sizeA; j ++)
		{
			t[j + i] += a[j] * b[i];
			int k = 0;
			while (t[j + k + i] > 9)
			{
				t[j + 1 + k + i] += t[j + k + i] / 10;
				t[j + k + i] %= 10;
				k ++;
			}
		}
	}

	int sizeT = getSize(t);
	for (i = 0; i < sizeT; i ++)
		a[i] = t[i];
}

int main()
{
	int n; scanf("%d", &n);
	int a[100000], b[100000], i = 0;
	for (i = 0; i < 100000; i ++)
		a[i] = b[i] = 0;

	char num; i = 0;
	while (scanf("%c", &num) != EOF)
	{
		if (num != '\n')
			a[i] = num - '0';
		i ++;
	}

	b[0] = 1;

	revert(a);

	printf("a: "); printArray(a);
	printf("b: "); printArray(b);

	for (i = 1; i <= n; i ++)
	{
		mult(b, a);
		//printf("%d - ", i); printArray(b);
	}
	printf("%d - ", n); printArray(b);

	return(0);
}