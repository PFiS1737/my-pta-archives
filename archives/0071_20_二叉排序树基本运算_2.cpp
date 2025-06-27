// NOTE: 删除使用递归实现
//
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

#include <algorithm>
using namespace std;

BSTNode *CreatBST(KeyType A[], int n) {
  BSTNode *root = new BSTNode{A[0], nullptr, nullptr};

  for (int i = 1; i < n; i++) {
    BSTNode *node = new BSTNode{A[i], nullptr, nullptr};

    BSTNode *p = root, *pp = nullptr;
    while (p) {
      pp = p;
      p = A[i] < p->key ? p->lchild : p->rchild;
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
    p = k < p->key ? p->lchild : p->rchild;
    printf("%d ", p->key);
  }

  return !!p;
}

int DeleteBST(BSTNode *&bt, KeyType k) {
  if (!bt) {
    return 0;
  }

  if (k < bt->key) {
    return DeleteBST(bt->lchild, k);
  }
  if (k > bt->key) {
    return DeleteBST(bt->rchild, k);
  }

  if (!bt->lchild && !bt->rchild) {
    bt = nullptr;
    return 1;
  }

  if (!bt->rchild) {
    bt = bt->lchild;
    return 1;
  }
  if (!bt->lchild) {
    bt = bt->rchild;
    return 1;
  }

  BSTNode *p = bt->rchild;
  while (p->lchild) {
    p = p->lchild;
  }
  swap(bt->key, p->key);
  DeleteBST(bt->rchild, k);

  return 1;
}
