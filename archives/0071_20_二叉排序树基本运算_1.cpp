// 要求实现二叉排序的基本运算，包括创建二叉排序树、查找、删除结点等运算。

// Sample Input
// 10
// 4 9 0 1 8 6 3 5 2 7
// 6
// 4

// Sample Output
// Preorder: 4 0 1 3 2 9 8 6 5 7
// 4 9 8 6
// Inorder: 0 1 2 3 5 6 7 8 9

// Prepend Code Start
// clang-format off
#include <stdio.h>

typedef int KeyType;            //定义关键字类型
typedef struct node                   //记录类型
{    
    KeyType key;                      //关键字项
    struct node *lchild,*rchild;    //左右孩子指针
} BSTNode;

int ReadData(int a[]);   //键盘输入若干个整数，顺序保存在数组a中，并返回输入整数的数量。由裁判程序实现，细节不表。
BSTNode *CreatBST(KeyType A[],int n);    //顺序读入数组A中的关键字, 依序建立一棵二叉排序树并返回根结点指针. 
int DeleteBST(BSTNode *&bt,KeyType k);   //在bt中删除关键字为k的节点. 找到关键字k并删除返回1，否则返回0。
int SearchBST(BSTNode *bt,KeyType k);    //输出从根节点到查找到的节点的路径 ,如果找到k,返回1，否则返回0。提示：输出语句格式如：printf("%d ",bt->key);
void InorderTraversal(BSTNode *bt);      //中序遍历并输出该二叉排序树。由裁判程序实现，输出语句格式如：printf("%d ",bt->key);
void PreorderTraversal(BSTNode *bt);     //先序遍历并输出该二叉排序树。由裁判程序实现，输出语句格式如：printf("%d ",bt->key);

int main()
{
    BSTNode *bt=NULL;
    KeyType k;
    int a[100],N;
    N=ReadData(a);  //键盘读入N个整数，顺序保存在数组a中. 裁判程序实现，细节不表。
    bt=CreatBST(a,N); //根据数组a,创建一棵BST树
    printf("Preorder: "); PreorderTraversal(bt); printf("\n"); //先序遍历并输出该二叉排序树。
    scanf("%d", &k);  //输入待查找的关键字k
    SearchBST(bt,k);printf("\n");  //查找k，并输出从根节点到查找到的节点的路径 ,如果找到k,返回1，否则返回0 
    scanf("%d", &k);  //输入待删除的关键字k
    DeleteBST(bt,k);  //在二叉排序树中删除关键字为k的结点。
    printf("Inorder: "); InorderTraversal(bt); printf("\n");   //中序遍历并输出该二叉排序树。
    return 0;
}
// clang-format on
// Prepend Code End

BSTNode *CreatBST(KeyType A[], int n) {
  BSTNode *root = new BSTNode;
  root->key = A[0];
  root->lchild = root->rchild = NULL;
  for (int i = 1; i < n; i++) {
    BSTNode *node = new BSTNode;
    node->key = A[i];
    node->lchild = node->rchild = NULL;

    BSTNode *p = root, *pp = NULL;
    while (p) {
      pp = p;
      if (A[i] < p->key) {
        p = p->lchild;
      } else {
        p = p->rchild;
      }
    }
    if (A[i] < pp->key) {
      pp->lchild = node;
    } else {
      pp->rchild = node;
    }
  }
  return root;
}

int SearchBST(BSTNode *bt, KeyType k) {
  BSTNode *p = bt;
  printf("%d ", p->key);
  while (p && p->key != k) {
    if (k < p->key) {
      p = p->lchild;
    } else {
      p = p->rchild;
    }
    printf("%d ", p->key);
  }

  if (p)
    return 1;
  else
    return 0;
}

int DeleteBST(BSTNode *&bt, KeyType k) {
  BSTNode *p = bt, *pp = NULL;
  while (p && p->key != k) {
    pp = p;
    if (k < p->key) {
      p = p->lchild;
    } else {
      p = p->rchild;
    }
  }

  if (!p)
    return 0;

  if (p->lchild && p->rchild) {
    BSTNode *min = p->rchild;
    while (min->lchild) {
      min = min->lchild;
    }
    int minKey = min->key;
    DeleteBST(bt, minKey);
    p->key = minKey;
  } else {
    BSTNode *child = p->lchild ? p->lchild : p->rchild;
    if (pp) {
      if (pp->lchild == p) {
        pp->lchild = child;
      } else {
        pp->rchild = child;
      }
    } else {
      bt = child;
    }
    delete p;
  }

  return 1;
}
