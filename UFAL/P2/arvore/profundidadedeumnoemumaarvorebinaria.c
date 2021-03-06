#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>

typedef struct _binaryTree binaryTree_t;

binaryTree_t* createEmptyBinaryTree();
binaryTree_t* createBinaryTree(int item, binaryTree_t *left, binaryTree_t *right);

binaryTree_t* searchInBinaryTree(binaryTree_t *bt, int item, int *depth);

bool isBinaryTreeEmpty(binaryTree_t *bt);
bool isValidBinaryTree(binaryTree_t *bt);

void addInBinaryTree(binaryTree_t **bt, int item);
void addScanInBinaryTree(binaryTree_t **bt);

void printPreOrder(binaryTree_t *bt);
void printInOrder(binaryTree_t *bt);
void printPostOrder(binaryTree_t *bt);

void destroyBinaryTree(binaryTree_t *bt);

int main()
{
  binaryTree_t *bt = createEmptyBinaryTree();
  addScanInBinaryTree(&bt);

  int wantedItem; scanf("%d", &wantedItem);
  int itemDepth = 0;
  binaryTree_t *temp = searchInBinaryTree(bt, wantedItem, &itemDepth);
  if (!isBinaryTreeEmpty(temp))
  {
    printf("ESTA NA ARVORE\n%d\n", itemDepth);
  }
  else
  {
    printf("NAO ESTA NA ARVORE\n%d\n", -1);
  }

  destroyBinaryTree(bt);
  if (!isBinaryTreeEmpty(temp))
    destroyBinaryTree(temp);

  return(0);
}

struct _binaryTree
{
  int item;
  binaryTree_t *left;
  binaryTree_t *right;
};

binaryTree_t* createEmptyBinaryTree()
{
  return(NULL);
}

binaryTree_t* createBinaryTree(int item, binaryTree_t *left, binaryTree_t *right)
{
  binaryTree_t *temp = (binaryTree_t*) malloc(1 * sizeof(binaryTree_t));
  temp->item = item;
  temp->left = left;
  temp->right = right;
  return(temp);
}

binaryTree_t* searchInBinaryTree(binaryTree_t *bt, int item, int *depth)
{
  binaryTree_t *curr = bt;
  while (!isBinaryTreeEmpty(curr))
  {
    if (curr->item == item)
    {
      return(curr);
    }
    else if (curr->item > item)
    {
      (*depth) += 1;
      curr = curr->left;
    }
    else if (curr->item < item)
    {
      (*depth) += 1;
      curr = curr->right;
    }
  }
  return(curr);
  /*if ((isBinaryTreeEmpty(bt)) || bt->item == item)
  {
    return(bt);
  }
  else if (bt->item > item)
  {
    (*depth) += 1;
    return(searchInBinaryTree(bt->left, item, &(*depth)));
  }
  else
  {
    (*depth) += 1;
    return(searchInBinaryTree(bt->right, item, &(*depth)));
  }*/
}

bool isBinaryTreeEmpty(binaryTree_t *bt)
{
  return(bt == NULL);
}

bool isValidBinaryTree(binaryTree_t *bt)
{
  if (!isBinaryTreeEmpty(bt) && !isBinaryTreeEmpty(bt->left) && !isBinaryTreeEmpty(bt->right))
  {
    if (bt->item < bt->left->item || bt->item > bt->right->item)
      return(false);

    return(isValidBinaryTree(bt->left) && isValidBinaryTree(bt->right));
  }
  return(true);
}

void addInBinaryTree(binaryTree_t **bt, int item)
{
  if (isBinaryTreeEmpty(*bt))
  {
    *bt = createBinaryTree(item, NULL, NULL);
  }
  else if ((*bt)->item > item)
  {
    addInBinaryTree(&(*bt)->left, item);
  }
  else
  {
    addInBinaryTree(&(*bt)->right, item);
  }
}

void addScanInBinaryTree(binaryTree_t **bt)
{
  char where;
  if (scanf("%c[^0-9]", &where) != EOF && where != '\n')
  {
    int num = INT_MIN;
    scanf("%d", &num);
    //printf("##%c%d\n", where, num);
    if (where == ')' && num == INT_MIN)
      return;

    if (isBinaryTreeEmpty(*bt))
    {
      if (num != INT_MIN)
      {
        (*bt) = createBinaryTree(num, NULL, NULL);
        addScanInBinaryTree(&(*bt)->left);
        addScanInBinaryTree(&(*bt)->right);
        getchar(); //Limpar para pegar o próximo nó
      }
      else
      {
        addScanInBinaryTree(&(*bt));
      }
    }
  }
}

void printPreOrder(binaryTree_t *bt)
{
  if (!isBinaryTreeEmpty(bt))
  {
    printf("%d ", bt->item);
    printPreOrder(bt->left);
    printPreOrder(bt->right);
  }
}

void printInOrder(binaryTree_t *bt)
{
  if (!isBinaryTreeEmpty(bt))
  {
    printInOrder(bt->left);
    printf("%d ", bt->item);
    printInOrder(bt->right);
  }
}

void printPostOrder(binaryTree_t *bt)
{
  if (!isBinaryTreeEmpty(bt))
  {
    printPostOrder(bt->left);
    printPostOrder(bt->right);
    printf("%d ", bt->item);
  }
}

void destroyBinaryTree(binaryTree_t *bt)
{
  if (!isBinaryTreeEmpty(bt))
  {
    destroyBinaryTree(bt->left);
    destroyBinaryTree(bt->right);
    free(bt);
  }
}
