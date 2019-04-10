#include <bits/stdc++.h>
#define PRINT_TREE if(0)
using namespace std;

const int misMatchPenalty = 3, gapPenalty = 2, maxStringSize = 1e4;
char stringA[maxStringSize + 1], stringB[maxStringSize + 1], finalA[2*maxStringSize + 1], finalB[2*maxStringSize + 1];
int stringASize, stringBSize, finalASize, finalBSize;
int dp[2*maxStringSize + 1][2*maxStringSize + 1];

int p;
map<string, int> mapForAll;
map<int, string> revMapForAll;
vector<int> vectorA, vectorB, finalVectorA, finalVectorB;
void dfsRead(vector<int> &v, char s[], int depth = 0)
{
  while (s[p])
  {
    if (s[p] == '{') { PRINT_TREE printf("%*c{\n", 2*(depth + 1), ' '); p ++; dfsRead(v, s, depth + 1); }
    else if (s[p] == ' ') p ++;
    else if (s[p] == '"')
    {
      char aux[100]; int i = 0;
      aux[i ++] = s[p ++]; aux[i ++] = s[p ++];
      while (s[p] && s[p - 1] != '"') aux[i ++] = s[p ++];
      aux[i] = '\0';
      string a = aux; if (!mapForAll.count(a)) { revMapForAll[(int) mapForAll.size()] = a; mapForAll[a] = mapForAll.size(); }
      v.push_back(mapForAll[a]);
      PRINT_TREE printf("%*c%s\n", 2*(depth + 1), ' ', aux);
    }
    else if (s[p] == '<' && s[p + 1] != '}')
    {
      char aux[100]; int i = 0;
      while (s[p] && s[p - 1] != '>') aux[i ++] = s[p ++];
      aux[i] = '\0';
      string a = aux; if (!mapForAll.count(a)) { revMapForAll[(int) mapForAll.size()] = a; mapForAll[a] = mapForAll.size(); }
      v.push_back(mapForAll[a]);
      PRINT_TREE printf("%*c%s\n", 2*(depth + 1), ' ', aux);
    }
    else if (s[p])
    {
      char aux[100]; int i = 0;
      while (s[p] && s[p] != ' ' && (s[p] != '}')) aux[i ++] = s[p ++];
      aux[i] = '\0'; if (s[p] != '}') p ++;
      string a = aux; if (!mapForAll.count(a)) { revMapForAll[(int) mapForAll.size()] = a; mapForAll[a] = mapForAll.size(); }
      v.push_back(mapForAll[a]);
      PRINT_TREE printf("%*c%s\n", 2*(depth + 1), ' ', aux);
    }
    if (s[p] == '}') { PRINT_TREE printf("%*c}\n", 2*(depth), ' '); p ++; return; }
  }
}
void buildMaps()
{
  p = 0; dfsRead(vectorA, stringA);
  p = 0; dfsRead(vectorB, stringB);
}

void getMinimumPenalty()
{
  for (int i = 0; i <= vectorA.size() + vectorB.size(); i ++) dp[i][0] = dp[0][i] = i * gapPenalty;
  for (int i = 1; i <= vectorA.size(); i ++)
    for (int j = 1; j <= vectorB.size(); j ++)
      if (vectorA[i - 1] == vectorB[j - 1])
        dp[i][j] = dp[i - 1][j - 1];
      else
        dp[i][j] = min({dp[i - 1][j - 1] + misMatchPenalty,
                        dp[i - 1][j] + gapPenalty,
                        dp[i][j - 1] + gapPenalty});
}

void buildSolution()
{
  int i = vectorA.size(), j = vectorB.size(), finalSize = vectorA.size() + vectorB.size();
  while (i && j)
  {
    if (vectorA[i - 1] == vectorB[j - 1] || dp[i - 1][j - 1] + misMatchPenalty == dp[i][j])
      finalVectorA.push_back(vectorA[-- i]), finalVectorB.push_back(vectorB[-- j]);
    else if (dp[i - 1][j] + gapPenalty == dp[i][j])
      finalVectorA.push_back(vectorA[-- i]), finalVectorB.push_back(-1);
    else
      finalVectorA.push_back(-1), finalVectorB.push_back(vectorB[-- j]);
  }
  while (finalVectorA.size() < finalSize) { finalVectorA.push_back(-1); }
  while (finalVectorB.size() < finalSize) { finalVectorB.push_back(-1); }
  reverse(finalVectorA.begin(), finalVectorA.end()), reverse(finalVectorB.begin(), finalVectorB.end());
}

int main()
{
  scanf("%[^\n]\n%[^\n]", stringA, stringB);
  buildMaps();
  getMinimumPenalty();
  buildSolution();
  printf("Minimum Penalty in aligning: %d\n", dp[(int) vectorA.size()][(int) vectorB.size()]);
  for (int i: finalVectorA) if (i == -1) printf("_____"); else printf("%5d", i); printf("\n");
  for (int i: finalVectorB) if (i == -1) printf("_____"); else printf("%5d", i); printf("\n");
  for (int i: finalVectorA) if (i == -1) printf("_____"); else printf("%s ", revMapForAll[i].c_str()); printf("\n");
  for (int i: finalVectorB) if (i == -1) printf("_____"); else printf("%s ", revMapForAll[i].c_str()); printf("\n");
  return(0);
}