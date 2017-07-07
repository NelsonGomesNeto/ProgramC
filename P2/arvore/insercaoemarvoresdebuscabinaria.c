#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>

typedef struct _binaryTree binaryTree_t;

binaryTree_t* createEmptyBinaryTree();
binaryTree_t* createBinaryTree(int item, binaryTree_t *left, binaryTree_t *right);

binaryTree_t* search(binaryTree_t *bt, int item);

bool isBinaryTreeEmpty(binaryTree_t *bt);

void addInBinaryTree(binaryTree_t **bt, int item);

void printPreOrder(binaryTree_t *bt);
void printInOrder(binaryTree_t *bt);
void printPostOrder(binaryTree_t *bt);

void destroyBinaryTree(binaryTree_t *bt);

int main()
{
  binaryTree_t *bt = createEmptyBinaryTree();

  int valorDoNo;
  while (scanf("%d", &valorDoNo) != EOF)
  {
    printf("----\n");
    printf("Adicionando %d\n   ", valorDoNo);
    addInBinaryTree(&bt, valorDoNo);
    printPreOrder(bt); printf("\n");
  } printf("----\n");

  destroyBinaryTree(bt);

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

binaryTree_t* search(binaryTree_t *bt, int item)
{
  if ((isBinaryTreeEmpty(bt)) || bt->item == item)
  {
    return(bt);
  }
  else if (bt->item > item)
  {
    return(search(bt->left, item));
  }
  else
  {
    return(search(bt->right, item));
  }
}

bool isBinaryTreeEmpty(binaryTree_t *bt)
{
  return(bt == NULL);
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

void printPreOrder(binaryTree_t *bt)
{
  printf("(");
  if (!isBinaryTreeEmpty(bt))
  {
    printf(" %d  ", bt->item);
    printPreOrder(bt->left);
    printf(" ");
    printPreOrder(bt->right);
  }
  printf(") ");
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
