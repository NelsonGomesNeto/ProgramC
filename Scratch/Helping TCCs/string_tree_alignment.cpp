#include <bits/stdc++.h>
#define PRINT_TREE if(0)
using namespace std;

// 3, 2
const int matchPenalty = 2, misMatchPenalty = -1, gapPenalty = -1, maxStringSize = 1e4;
char stringA[maxStringSize + 1], stringB[maxStringSize + 1], finalA[2*maxStringSize + 1], finalB[2*maxStringSize + 1];
int stringASize, stringBSize, finalASize, finalBSize;
int dp[2*maxStringSize + 1][2*maxStringSize + 1];
bool visited[2*maxStringSize + 1][2*maxStringSize + 1];

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
  // for (int i = 0; i <= vectorA.size() + vectorB.size(); i ++) dp[i][0] = dp[0][i] = i * gapPenalty;
  // for (int i = 1; i <= vectorA.size(); i ++)
  //   for (int j = 1; j <= vectorB.size(); j ++)
  //     if (vectorA[i - 1] == vectorB[j - 1])
  //       dp[i][j] = dp[i - 1][j - 1];
  //     else
  //       dp[i][j] = min({dp[i - 1][j - 1] + misMatchPenalty,
  //                       dp[i - 1][j] + gapPenalty,
  //                       dp[i][j - 1] + gapPenalty});
  for (int i = 0; i <= vectorA.size() + vectorB.size(); i ++) dp[i][0] = dp[0][i] = i * gapPenalty;

  for (int i = 1; i <= vectorA.size(); i ++)
    for (int j = 1; j <= vectorB.size(); j ++)
      if (vectorA[i - 1] == vectorB[j - 1])
        dp[i][j] = dp[i - 1][j - 1] + matchPenalty;
      else
        dp[i][j] = max({dp[i - 1][j - 1] + misMatchPenalty,
                        dp[i - 1][j] + gapPenalty,
                        dp[i][j - 1] + gapPenalty});
}

void buildSolution()
{
  int i = vectorA.size(), j = vectorB.size(), finalSize = vectorA.size() + vectorB.size();
  while (i && j)
  {
    visited[i][j] = true;
    if (vectorA[i - 1] == vectorB[j - 1] || dp[i - 1][j - 1] + misMatchPenalty == dp[i][j])
      finalVectorA.push_back(vectorA[-- i]), finalVectorB.push_back(vectorB[-- j]);
    else if (dp[i - 1][j] + gapPenalty == dp[i][j])
      finalVectorA.push_back(vectorA[-- i]), finalVectorB.push_back(-1);
    else
      finalVectorA.push_back(-1), finalVectorB.push_back(vectorB[-- j]);
  }
  visited[i][j] = true;
  while (finalVectorA.size() < finalSize) { finalVectorA.push_back(-1); }
  while (finalVectorB.size() < finalSize) { finalVectorB.push_back(-1); }
  reverse(finalVectorA.begin(), finalVectorA.end()), reverse(finalVectorB.begin(), finalVectorB.end());
}

void printNChar(int n, char c)
{
  while (n --) printf("%c", c);
}

int main()
{
  scanf("%[^\n]\n%[^\n]", stringA, stringB);

  buildMaps();
  printf("Mapeamento das strings:\n");
  printf("\tstring A: %s\n", stringA);
  printf("\tvector A: "); for (int i = 0; i < vectorA.size(); i ++) printf("%d%c", vectorA[i], i < vectorA.size() - 1 ? ' ' : '\n');
  printf("\tstring B: %s\n", stringB);
  printf("\tvector B: "); for (int i = 0; i < vectorB.size(); i ++) printf("%d%c", vectorB[i], i < vectorB.size() - 1 ? ' ' : '\n');
  printNChar(150, '#'); printf("\n");

  printf("Inteiro para string:\n");
  for (auto i: revMapForAll)
    printf("\t%d: %s\n", i.first, i.second.c_str());
  printNChar(150, '#'); printf("\n");

  getMinimumPenalty();
  buildSolution();
  printf("Matriz de alinhamento:\n");
  int maxNumber = 0; for (int i = 0; i <= vectorA.size(); i ++) for (int j = 0; j <= vectorB.size(); j ++) maxNumber = max(maxNumber, dp[i][j]);
  int maxSize = 1 + (maxNumber == 0); while (maxNumber) maxNumber /= 10, maxSize ++;
  for (auto i: mapForAll) maxSize = max(maxSize, (int) i.first.size());
  printNChar(maxSize + 1, ' ');
  for (int j = 0; j < vectorB.size(); j ++) printf("%*s%c", maxSize, revMapForAll[vectorB[j]].c_str(), j < vectorB.size() - 1 ? ' ' : '\n');
  for (int i = 1; i <= vectorA.size(); i ++)
  {
    printf("%*s ", maxSize, revMapForAll[vectorA[i-1]].c_str());
    for (int j = 1; j <= vectorB.size(); j ++)
      printf("%*d%c", maxSize, dp[i][j], j < vectorB.size() - 0 ? ' ' : '\n');
  }
  printNChar(150, '#'); printf("\n");

  printf("Caminho na matriz:\n");
  printNChar(maxSize + 1, ' ');
  for (int j = 0; j < vectorB.size(); j ++) printf("%*s%c", maxSize, revMapForAll[vectorB[j]].c_str(), j < vectorB.size() - 1 ? ' ' : '\n');
  for (int i = 0; i < vectorA.size(); i ++)
  {
    printf("%*s ", maxSize, revMapForAll[vectorA[i]].c_str());
    for (int j = 0; j < vectorB.size(); j ++)
      printf("%*d%c", maxSize, visited[i][j] ? visited[i + 1][j + 1] + 2*visited[i + 1][j] + 3*visited[i][j + 1] : 0, j < vectorB.size() - 1 ? ' ' : '\n');
  }
  printNChar(150, '#'); printf("\n");

  printf("Penalidade mínima de alinhamento: %d\n", dp[(int) vectorA.size()][(int) vectorB.size()]);
  printf("Alinhamento:\n");
  printf("\t"); for (int i: finalVectorA) if (i == -1) printf("_____"); else printf("%5d", i); printf("\n");
  printf("\t"); for (int i: finalVectorB) if (i == -1) printf("_____"); else printf("%5d", i); printf("\n");
  printf("\t"); for (int i: finalVectorA) if (i == -1) printf("____________________"); else printf("%s ", revMapForAll[i].c_str()); printf("\n");
  printf("\t"); for (int i: finalVectorB) if (i == -1) printf("____________________"); else printf("%s ", revMapForAll[i].c_str()); printf("\n");
  printNChar(150, '#'); printf("\n");

  printf("Operações:\n");
  vector<pair<int, pair<int, int>>> modifications;
  for (int i = 0; i < finalVectorB.size(); i ++)
    if (finalVectorB[i] != -1 && (i >= finalVectorA.size() || finalVectorA[i] == -1))
      modifications.push_back({0, {finalVectorB[i], 0}}); // insertion
    else if (finalVectorB[i] == -1 && (i < finalVectorA.size() && finalVectorA[i] != -1))
      modifications.push_back({1, {finalVectorA[i], 0}}); // deletion
    else if (finalVectorB[i] != -1 && (i < finalVectorA.size() && finalVectorA[i] != -1) && finalVectorB[i] != finalVectorA[i])
      modifications.push_back({2, {finalVectorA[i], finalVectorB[i]}}); // substitution
    else if (finalVectorB[i] != -1 && i < finalVectorA.size() && finalVectorA[i] == finalVectorB[i])
      modifications.push_back({3, {finalVectorB[i], 0}}); // match
  for (auto i: modifications)
    if (i.first == 0)
      printf("\tInserir %s\n", revMapForAll[i.second.first].c_str());
    else if (i.first == 1)
      printf("\tDeletar %s\n", revMapForAll[i.second.first].c_str());
    else if (i.first == 2)
      printf("\tSubstituir %s por %s\n", revMapForAll[i.second.first].c_str(), revMapForAll[i.second.second].c_str());
    else if (i.first == 3)
      printf("\tManter %s\n", revMapForAll[i.second.first].c_str());

  return(0);
}