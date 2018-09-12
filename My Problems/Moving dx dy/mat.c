#include <stdio.h>
#include <string.h>

void printMat(int i, int j, int n, int m, int mat[][m])
{
	if (i == n) return;
	printf("%4d%c", mat[i][j], j < m - 1 ? ' ' : '\n');
	printMat(j == m - 1 ? i + 1 : i, j == m - 1 ? 0 : j + 1, n, m, mat);
}

int fix(int i, int n)
{
	return(i < 0 ? (i % n) + n : i % n);
}

void go(int i, int j, int dy, int dx, int step, int n, int m, int mat[][m])
{
	if (mat[i][j]) return;
	mat[i][j] = step;
	go(fix(i + dy, n), fix(j + dx, m), dy, dx, step + 1, n, m, mat);
}

int main()
{
	int n, m, y, x, dy, dx; scanf("%d %d %d %d %d %d", &n, &m, &y, &x, &dy, &dx);
	int mat[n][m]; memset(mat, 0, sizeof(mat));
	go(y, x, dy, dx, 1, n, m, mat);
	printMat(0, 0, n, m, mat);
	return(0);
}