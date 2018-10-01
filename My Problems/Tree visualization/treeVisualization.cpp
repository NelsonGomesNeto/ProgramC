#include <bits/stdc++.h>
using namespace std;

void printMaxNodeSize(int maxNodeSize)
{
  for (int i = 0; i < maxNodeSize; i ++) printf(" ");
}

void spaces(int q, int maxNodeSize, int diff)
{
  for (int i = 0; i < q; i ++)
  {
    if (i < q - 1) printMaxNodeSize(maxNodeSize);
    printf(" ");
  }
  printMaxNodeSize(diff);
}

char printNode(int node, int level, int bs, int maxNodeSize)
{
  if (bs)
  {
    if (level) { spaces(level - 1, maxNodeSize, maxNodeSize); printf(" \\\n"); }
    spaces(level, maxNodeSize, maxNodeSize - ((int)log10(node) + 1)); printf("%d\n", node);
  }
  else
  {
    spaces(level, maxNodeSize, maxNodeSize - ((int)log10(node) + 1)); printf("%d\n", node);
    if (level) { spaces(level - 1, maxNodeSize, maxNodeSize); printf(" /\n"); }
  }
}

void printTree(int tree[][2], int root, int level, int bs, int maxNodeSize)
{
  if (root == -1) return;
  printTree(tree, tree[root][0], level + 1, 0, maxNodeSize);
  printNode(root, level, bs, maxNodeSize);
  printTree(tree, tree[root][1], level + 1, 1, maxNodeSize);
}

int findMaxNodeSize(int tree[][2], int root)
{
  if (root == -1) return(0);
  return(max((int) log10(root) + 1, max(findMaxNodeSize(tree, tree[root][0]), findMaxNodeSize(tree, tree[root][1]))));
}

int main()
{
  int nodes, dads, root; scanf("%d %d %d", &nodes, &dads, &root);
  int tree[nodes][2], u, l, r; memset(tree, -1, sizeof(tree));
  for (int i = 0; i < dads; i ++)
  {
    scanf("%d %d %d", &u, &l, &r);
    tree[u][0] = l; tree[u][1] = r;
  }
  printTree(tree, root, 0, 0, findMaxNodeSize(tree, root));
  return(0);
}
