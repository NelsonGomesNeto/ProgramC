#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int tam, ans;

struct DP
{
  int nao, sim;
};

int bt(int a[], int i, int fim, int sum, int target, struct DP d[])
{
  if (d[sum].sim == -1 || i < d[sum].sim)
  {
    d[sum].sim = i;
  }
  if (ans == 1)
  {
    return(1);
  }
  if (sum == target)
  {
    ans = 1;
    return(1);
  }
  if (i == fim)
  {
    return(1);
  }
  if (a[i] + sum <= target && a[i] != 0)
  {
    bt(a, i + 1, fim, sum + a[i], target, d);
  }
  bt(a, i + 1, fim, sum, target, d);
}

int main()
{
  int testes, perguntas, run = 1;
  scanf("%d", &testes);
  while (run <= testes)
  {
    scanf("%d %d", &tam, &perguntas);
    int array[tam], q, max = 0;
    struct DP *dp = malloc(100001 * sizeof(struct DP));
    memset(dp, -1, 100001);
    for (q = 0; q < tam; q ++)
    {
      scanf("%d", &array[q]);
      max += array[q];
    }
    int ate, soma;
    printf("caso %d:", run);
    for (q = 0; q < perguntas; q ++)
    {
      scanf("%d %d", &ate, &soma);
      ans = 0;
      if (soma > max) { printf(" 0"); continue; }
      if (dp[soma].sim == -1 && dp[soma].nao == -1)
      {
        bt(array, 0, ate, 0, soma, dp);
        if (ans == 1)
        {
          dp[soma].sim = ate;
        }
        else
        {
          dp[soma].nao = ate;
        }
      }
      else
      {
        if (ate >= dp[soma].sim && dp[soma].sim != -1)
        {
          ans = 1;
        }
        else
        {
          if (dp[soma].nao == -1 || ate > dp[soma].nao)
          {
            bt(array, 0, ate, 0, soma, dp);
            if (ans == 0)
            {
              dp[soma].nao = ate;
            }
            else
            {
              dp[soma].sim = ate;
            }
          }
        }
      }
      printf(" %d", ans);
    } printf("\n");
    run ++;
    free(dp);
  }
  return(0);
}
