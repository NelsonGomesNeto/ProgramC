#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>

typedef struct _AVLTree AVLTree_t;

AVLTree_t* createEmptyAVLTree();
AVLTree_t* createAVLTree(int item, AVLTree_t *left, AVLTree_t *right);

AVLTree_t* searchInAVLTree(AVLTree_t *avl, int item);

bool isAVLTreeEmpty(AVLTree_t *avl);
bool isBalanced(AVLTree_t *avl);
int balanceFactor(AVLTree_t *avl);
int height(AVLTree_t *avl);
AVLTree_t* rotateLeft(AVLTree_t *avl);
AVLTree_t* rotateRight(AVLTree_t *avl);

void addInAVLTree(AVLTree_t **avl, int item);
void addScanInAVLTree(AVLTree_t **avl);

void printPreOrder(AVLTree_t *avl);
void printInOrder(AVLTree_t *avl);
void printPostOrder(AVLTree_t *avl);

void deleteInAVLTree(AVLTree_t **avl, int item);
void destroyAVLTree(AVLTree_t *avl);

void printStuff(AVLTree_t *avl)
{
  printf("PreOrder: "); printPreOrder(avl); printf("\n");
  printf("InOrder: "); printInOrder(avl); printf("\n");
  printf("PosOrder: "); printPostOrder(avl); printf("\n");
}

int main()
{
  AVLTree_t *avl = createEmptyAVLTree();

  addInAVLTree(&avl, 1);
  addInAVLTree(&avl, 2);
  addInAVLTree(&avl, 3);
  addInAVLTree(&avl, 4);
  addInAVLTree(&avl, 5);
  addInAVLTree(&avl, 6);
  addInAVLTree(&avl, 7);
  addInAVLTree(&avl, 15);
  addInAVLTree(&avl, 30);
  addInAVLTree(&avl, 8);

  printf("PreOrder: "); printPreOrder(avl); printf("\n");
  printf("InOrder: "); printInOrder(avl); printf("\n");
  printf("PosOrder: "); printPostOrder(avl); printf("\n\n");

  //deleteInAVLTree(&avl, 11); printf("Success!\n"); printStuff(avl); printf("\n");
  deleteInAVLTree(&avl, 2); printf("Success!\n"); printStuff(avl); printf("\n");
  deleteInAVLTree(&avl, 1); printf("Success!\n"); printStuff(avl); printf("\n");
  //deleteInAVLTree(&avl, 13); printf("Success!\n"); printStuff(avl); printf("\n");
  //deleteInAVLTree(&avl, 12); printf("Success!\n"); printStuff(avl); printf("\n");
  deleteInAVLTree(&avl, 4); printf("Success!\n"); printStuff(avl); printf("\n");
  deleteInAVLTree(&avl, 3); printf("Success!\n"); printStuff(avl); printf("\n");
  deleteInAVLTree(&avl, 5); printf("Success!\n"); printStuff(avl); printf("\n");
  deleteInAVLTree(&avl, 6); printf("Success!\n"); printStuff(avl); printf("\n");
  deleteInAVLTree(&avl, 15); printf("Success!\n"); printStuff(avl); printf("\n");
  deleteInAVLTree(&avl, 30); printf("Success!\n"); printStuff(avl); printf("\n");

  destroyAVLTree(avl);

  return(0);
}

struct _AVLTree
{
  int item;
  int height;
  AVLTree_t *left;
  AVLTree_t *right;
};

AVLTree_t* createEmptyAVLTree()
{
  return(NULL);
}

AVLTree_t* createAVLTree(int item, AVLTree_t *left, AVLTree_t *right)
{
  AVLTree_t *temp = (AVLTree_t*) malloc(1 * sizeof(AVLTree_t));
  temp->item = item;
  temp->left = left;
  temp->right = right;
  temp->height = 0;
  return(temp);
}

AVLTree_t* searchInAVLTree(AVLTree_t *avl, int item)
{
  if ((isAVLTreeEmpty(avl)) || avl->item == item)
  {
    return(avl);
  }
  else if (avl->item > item)
  {
    return(searchInAVLTree(avl->left, item));
  }
  else
  {
    return(searchInAVLTree(avl->right, item));
  }
}

bool isAVLTreeEmpty(AVLTree_t *avl)
{
  return(avl == NULL);
}

bool isBalanced(AVLTree_t *avl)
{
  int bf = height(avl->left) - height(avl->right);
  return((-1 <= bf) && (bf <= 1));
}

int balanceFactor(AVLTree_t *avl)
{
  if (isAVLTreeEmpty(avl))
    return(0);
  else if (!isAVLTreeEmpty(avl->left) && !isAVLTreeEmpty(avl->right))
    return(avl->left->height - avl->right->height);
  else if (!isAVLTreeEmpty(avl->left) && isAVLTreeEmpty(avl->right))
    return(1 + avl->left->height);
  else //if (isAVLTreeEmpty(avl->left) && !isAVLTreeEmpty(avl->right))
    return(- avl->right->height - 1);
}

int max(int a, int b)
{
  return(a > b ? a : b);
}

int height(AVLTree_t *avl)
{
  if (isAVLTreeEmpty(avl)) return(-1);

  return(1 + max(height(avl->left), height(avl->right)));
}

AVLTree_t* rotateLeft(AVLTree_t *avl)
{
  printf("Performing rotation\n");
  AVLTree_t *subTreeRoot = createEmptyAVLTree();

  if (!isAVLTreeEmpty(avl) && !isAVLTreeEmpty(avl->right))
  {
    subTreeRoot = avl->right;
    avl->right = subTreeRoot->left;
    subTreeRoot->left = avl;
  }

  subTreeRoot->height = height(subTreeRoot);
  avl->height = height(avl);
  return(subTreeRoot);
}

AVLTree_t* rotateRight(AVLTree_t *avl)
{
  printf("Performing rotation\n");
  AVLTree_t *subTreeRoot = createEmptyAVLTree();

  if (!isAVLTreeEmpty(avl) && !isAVLTreeEmpty(avl->left))
  {
    subTreeRoot = avl->left;
    avl->left = subTreeRoot->right;
    subTreeRoot->right = avl;
  }

  subTreeRoot->height = height(subTreeRoot);
  avl->height = height(avl);
  return(subTreeRoot);
}

void rebalanceAVLTree(AVLTree_t *avl)
{
  while (!isAVLTreeEmpty(avl) && !isBalanced(avl))
  {
    avl->height = height(avl);
    AVLTree_t *child;

    if (balanceFactor(avl) == 2 || balanceFactor(avl) == -2)
    {
      if (balanceFactor(avl) == 2)
      {
        child = avl->left;
        if (balanceFactor(child) == -1)
          avl->left = rotateLeft(child);

        avl = rotateRight(avl);
      }
      else if (balanceFactor(avl) == -2)
      {
        child = avl->right;
        if (balanceFactor(child) == 1)
          avl->right = rotateRight(child);

        avl = rotateLeft(avl);
      }
    }
  }
}

void addInAVLTree(AVLTree_t **avl, int item)
{
  if (isAVLTreeEmpty(*avl))
  {
    (*avl) = createAVLTree(item, NULL, NULL);
    return;
  }
  else if ((*avl)->item > item)
    addInAVLTree(&(*avl)->left, item);
  else
    addInAVLTree(&(*avl)->right, item);

  (*avl)->height = height((*avl));
  AVLTree_t *child;

  if (balanceFactor((*avl)) == 2 || balanceFactor((*avl)) == -2)
  {
    if (balanceFactor((*avl)) == 2)
    {
      child = (*avl)->left;
      if (balanceFactor(child) == -1)
        (*avl)->left = rotateLeft(child);

      (*avl) = rotateRight((*avl));
    }
    else if (balanceFactor((*avl)) == -2)
    {
      child = (*avl)->right;
      if (balanceFactor(child) == 1)
        (*avl)->right = rotateRight(child);

      (*avl) = rotateLeft((*avl));
    }
  }
}

void addScanInAVLTree(AVLTree_t **avl)
{
  char where;
  if (scanf("%c[^0-9]", &where) != EOF && where != '\n')
  {
    int num = INT_MIN;
    scanf("%d", &num);
    //printf("##%c%d\n", where, num);
    if (where == ')' && num == INT_MIN)
      return;

    if (isAVLTreeEmpty(*avl))
    {
      if (num != INT_MIN)
      {
        (*avl) = createAVLTree(num, NULL, NULL);
        addScanInAVLTree(&(*avl)->left);
        addScanInAVLTree(&(*avl)->right);
        getchar(); //Limpar para pegar o próximo nó
      }
      else
      {
        addScanInAVLTree(&(*avl));
      }
    }
  }
}

void printPreOrder(AVLTree_t *avl)
{
  if (!isAVLTreeEmpty(avl))
  {
    printf("%d ", avl->item);
    printPreOrder(avl->left);
    printPreOrder(avl->right);
  }
}

void printInOrder(AVLTree_t *avl)
{
  if (!isAVLTreeEmpty(avl))
  {
    printInOrder(avl->left);
    printf("%d ", avl->item);
    printInOrder(avl->right);
  }
}

void printPostOrder(AVLTree_t *avl)
{
  if (!isAVLTreeEmpty(avl))
  {
    printPostOrder(avl->left);
    printPostOrder(avl->right);
    printf("%d ", avl->item);
  }
}

AVLTree_t* minimumNode(AVLTree_t *avl, AVLTree_t **parent)
{
  AVLTree_t *curr = avl;
  while (!isAVLTreeEmpty(curr->left))
  {
    *parent = curr;
    curr = curr->left;
  }
  return(curr);
}

AVLTree_t* findParent(AVLTree_t *avl, AVLTree_t **parent, int item)
{
  if ((isAVLTreeEmpty(avl)) || avl->item == item)
  {
    return(avl);
  }
  else if (avl->item > item)
  {
    *parent = avl;
    return(findParent(avl->left, parent, item));
  }
  else
  {
    *parent = avl;
    return(findParent(avl->right, parent, item));
  }
}

void deleteInAVLTreeSubwork(AVLTree_t **avl, int item)
{
  printf("Removing node: %d...", item); fflush(stdout);
  AVLTree_t *atual = (*avl), *toRemove, *parent = NULL, *successor;
  if (isAVLTreeEmpty(atual)) return;

  toRemove = findParent(atual, &parent, item);

  if (isAVLTreeEmpty(toRemove)) return;

  if (!isAVLTreeEmpty(toRemove->left) && !isAVLTreeEmpty(toRemove->right))
  {
    parent = toRemove;
    successor = toRemove->right;

    successor = minimumNode(successor, &parent);

    toRemove->item = successor->item;
    toRemove = successor;

    parent->height = height(parent);
      successor->height = height(successor);
  }

  if (isAVLTreeEmpty(toRemove->left) && isAVLTreeEmpty(toRemove->right))
  {
    if (parent != NULL)
    {
      if (parent->right == toRemove)
        parent->right = NULL;
      else
        parent->left = NULL;
    }

    if (toRemove == (*avl))
      (*avl) = NULL;
    else
      free(toRemove);
    return;
  }

  if (!isAVLTreeEmpty(toRemove->left) && isAVLTreeEmpty(toRemove->right))
  {
    if (parent == NULL)
    {
      parent = (*avl);
      (*avl) = (*avl)->left;
      free(parent);
      return;
    }
    if (parent->left == toRemove)
      parent->left = toRemove->left;
    else
      parent->right = toRemove->left;

    free(toRemove);
    return;
  }

  if (isAVLTreeEmpty(toRemove->left) && !isAVLTreeEmpty(toRemove->right))
  {
    if (parent == NULL)
    {
      parent = (*avl);
      (*avl) = (*avl)->right;
      free(parent);
      return;
    }
    if (parent->left == toRemove)
      parent->left = toRemove->right;
    else
      parent->right = toRemove->right;

    free(toRemove);
    return;
  }
}

void deleteInAVLTree(AVLTree_t **avl, int item)
{
  deleteInAVLTreeSubwork(&*avl, item);
  rebalanceAVLTree((*avl));
}

void destroyAVLTree(AVLTree_t *avl)
{
  if (!isAVLTreeEmpty(avl))
  {
    destroyAVLTree(avl->left);
    destroyAVLTree(avl->right);
    free(avl);
  }
}
