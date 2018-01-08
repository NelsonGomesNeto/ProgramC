#include <bits/stdc++.h>
using namespace std;
int p1, p2, cycles, maximumSteps, at, rule, deadLine, perLine, showAllStates; vector<int> maxState;
map<vector<int>, vector<int> > state;

int limit(int fingers)
{
  if (rule == 1) return(fingers);
  if (rule == 2) return(fingers % deadLine);
}

int loseRule(int fingers)
{
  if (rule == 1) return(fingers >= deadLine);
  if (rule == 2) return(!(fingers % deadLine));
}

void play(int l1, int r1, int l2, int r2, int turn, int steps)
{
  if (steps > maximumSteps)
  {
    maximumSteps = steps; maxState = {limit(l1), limit(r1), limit(l2), limit(r2)};
  }

  if (loseRule(l1) || loseRule(r1))
  {
    p2 ++; return;
  }
  if (loseRule(l2) || loseRule(r2))
  {
    p1 ++; return;
  }

  l1 = limit(l1); r1 = limit(r1); l2 = limit(l2); r2 = limit(r2);

  if (!state.count({l1, r1, l2, r2}))
    state[{l1, r1, l2, r2}] = {1, 0};
  else
  {
    state[{l1, r1, l2, r2}] = {state[{l1, r1, l2, r2}][0] + 1, state[{l1, r1, l2, r2}][1]};
    return;
  }

  if (turn)
  {
    play(l1, r1, l2 + l1, r2, 1 - turn, steps + 1);
    play(l1, r1, l2 + r1, r2, 1 - turn, steps + 1);
    play(l1, r1, l2, r2 + l1, 1 - turn, steps + 1);
    play(l1, r1, l2, r2 + r1, 1 - turn, steps + 1);
    if (!(l1 & 1))
      play(l1 / 2, r1 + (l1 / 2), l2, r2, 1 - turn, steps + 1);
    if (!(r1 & 1))
      play(l1 + (r1 / 2), r1 / 2, l2, r2, 1 - turn, steps + 1);
  }
  else
  {
    play(l1 + l2, r1, l2, r2, 1 - turn, steps + 1);
    play(l1 + r2, r1, l2, r2, 1 - turn, steps + 1);
    play(l1, r1 + l2, l2, r2, 1 - turn, steps + 1);
    play(l1, r1 + r2, l2, r2, 1 - turn, steps + 1);
    if (!(l2 & 1))
      play(l1, r1, l2 / 2, r2 + (l2 / 2), 1 - turn, steps + 1);
    if (!(r2 & 1))
      play(l1, r1, l2 + (r2 / 2), r2 / 2, 1 - turn, steps + 1);
  }
}

int readMode()
{
  printf("Rule, DeadLine, Show all states (quantity per line): ");
  if (scanf("%d %d %d", &rule, &deadLine, &showAllStates) == EOF) return(0);
  if (showAllStates) if (scanf("%d", &perLine) == EOF) return(0);
  return(1);
}

int main()
{
  while (readMode())
  {
    state.clear();
    p1 = p2 = cycles = maximumSteps = 0;
    play(1, 1, 1, 1, 1, 0);
    printf("First player: %d; Second player: %d\n", p1, p2);
    printf("%d possible states\n", (int) state.size());
    if (showAllStates)
    {
      at = 0;
      for (auto k: state)
      {
        at ++;
        vector<int> v = k.first;
        for (int i = 0; i < 4; i ++)
          printf("%d ", v[i]);
        printf("-> %d times%s", state[v][0], at == perLine ? "\n" : "; ");
        at %= perLine;
      }
      if (at) printf("\n");
    }
    printf("Maximum steps: %d (%d, %d, %d, %d)\n", maximumSteps, maxState[0], maxState[1], maxState[2], maxState[3]);
  }
  return(0);
}