#include <algorithm>
#include <utility>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <cstring>

using namespace std;


int energy[100];
vector<int> adjList[100];
int dist[100];
bool been[100];
int n;

bool dfs(int v)
{
    been[v] = true;
    for(int i = 0; i < (int)adjList[v].size(); i++)
    {
        int o = adjList[v][i];
        if(o == n-1)
        {
            return true;
        }
        if(!been[o] && dfs(o))
        {
            return true;
        }
    }
    return false;
}

int main()
{
    while(scanf("%d", &n) != EOF && n != -1)
    {
        for(int i = 0; i < n; i++)
        {
            int adj;
            adjList[i].clear();
            scanf("%d %d", &energy[i], &adj);
            energy[i] /= -1;
            int a;
            while(adj--)
            {
                scanf("%d", &a);
                a--;
                adjList[i].push_back(a);
            }
            dist[i] = 1000000;
        }
        dist[0] = -100;
        for(int i = 0; i < n-1; i++)
        {
            for(int r = 0; r < n; r++)
            {
                for(int a = 0; a < (int)adjList[r].size(); a++)
                {
                    int o = adjList[r][a];
                    if(dist[r] + energy[o] < 0)
                    {
                        dist[o] = min(dist[o], dist[r] + energy[o]);
                    }

                }
            }
        }

        if(dist[n-1] <= 0)
        {
            goto win;
        }
        else
        {
            // detect negative cycle
            for(int i = 0; i < n; i++)
            {
                for(int a = 0; a < (int)adjList[i].size(); a++)
                {
                    int o = adjList[i][a];
                    if(dist[i] + energy[o] < 0 && dist[i] + energy[o] < dist[o])
                    {
                        memset(been, 0, sizeof(been));
                        if(dfs(i))
                        {
                            goto win;
                        }
                    }
                }
            }
            goto lose;
        }
win:
        printf("winnable\n");
        continue;
lose:
        printf("hopeless\n");
        continue;
    }

    return 0;
}