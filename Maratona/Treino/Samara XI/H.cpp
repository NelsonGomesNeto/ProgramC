#include <bits/stdc++.h>
using namespace std;
int si, sj, fi, fj;
int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
int n, m, d; vector<pair<int, int> > monsters;

int invalid(int i, int j)
{
  for (int di = 0; di < monsters.size(); di ++)
    if (abs(i - monsters[di].first) + abs(j - monsters[di].second) <= d)
      return(1);
  return(0);
}

int bfs(vector<char> maze[], vector<int> visited[])
{
  deque<pair<pair<int, int>, int> > queue;
  queue.push_back({{si, sj}, 0});
  while (!queue.empty())
  {
    int i = queue.front().first.first, j = queue.front().first.second, steps = queue.front().second;
    if (i == fi && j == fj) return(steps);
    queue.pop_front();
    if (i < 0 || j < 0 || i >= n || j >= m || visited[i][j] || invalid(i, j)) continue;
    // visited[i][j] = 1;
    for (int k = 0; k < 4; k ++)
      queue.push_back({{i + dy[k], j + dx[k]}, steps + 1});
  }
  return(-1);
}

int main()
{
  scanf("%d %d %d", &n, &m, &d);
  vector<char> maze[n]; vector<int> visited[n]; char b;
  for (int i = 0; i < n; i ++)
  {
    getchar();
    for (int j = 0; j < m; j ++)
    {
      scanf("%c", &b);
      maze[i].push_back(b);
      if (maze[i][j] == 'S') si = i, sj = j;
      if (maze[i][j] == 'F') fi = i, fj = j;
      if (maze[i][j] == 'M') monsters.push_back({i, j});
      visited[i].push_back(0);
    }
  }

  int ans = bfs(maze, visited);
  printf("%d\n", ans == -1 ? -1 : ans);

  return(0);
}