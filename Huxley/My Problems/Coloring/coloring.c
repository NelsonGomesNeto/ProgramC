#include <stdio.h>
int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};

void printField(int n, int m, char field[n][m + 1])
{
  for (int i = 0; i < n; i ++)
    printf("%s\n", field[i]);
}

void floodFill(int n, int m, char field[n][m + 1], int i, int j, char color)
{
  if (i < 0 || j < 0 || i >= n || j >= m || field[i][j] == '#' || field[i][j] == color) return;

  field[i][j] = color;
  for (int k = 0; k < 4; k ++)
    floodFill(n, m, field, i + dy[k], j + dx[k], color);
}

int main()
{
  int n, m; scanf("%d %d", &n, &m);
  char field[n][m + 1]; for (int i = 0; i < n; i ++) scanf("\n%s", field[i]);
  int toColor; scanf("%d", &toColor);
  while (toColor --)
  {
    int y, x; char color; scanf("%d %d %c", &y, &x, &color);
    floodFill(n, m, field, y, x, color);
    printField(n, m, field); if (toColor) printf("\n");
  }
  return(0);
}
