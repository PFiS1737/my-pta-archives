// 本题要求实现二叉排序树的两个基本操作。
// 函数FindMin返回二叉排序树T中最小元素结点的指针；
// 函数FindMax返回二叉排序树T中最大元素结点的指针。

// Sample Input
// 4 3 5 1 2 7 6 8 -1

// Sample Output
// Inorder: 1 2 3 4 5 6 7 8
// 1 is the smallest key
// 8 is the largest key

// Prepend Code Start
#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;
typedef struct BSTNode
{
    ElemType data;
    struct BSTNode *lchild,*rchild;
}BSTNode,*BSTree;
BSTree CreateBST(); /* 二叉排序树创建，由裁判实现，细节不表 */
BSTree FindMin( BSTree T);
BSTree FindMax( BSTree T);
void Inorder(BSTree T);/* 中序遍历，由裁判实现，细节不表 */

int main()
{
    BSTree T,MinP, MaxP;
    T = CreateBST();
    printf("Inorder:");    Inorder(T);    printf("\n");
    MinP = FindMin(T);
    MaxP = FindMax(T);
    if(MinP) printf("%d is the smallest key\n",MinP->data);
    if(MaxP) printf("%d is the largest key\n",MaxP->data);
    return 0;
}
// Prepend Code End

BSTree FindMin(BSTree T) {
  return T && T->lchild ? FindMin(T->lchild) : T;
}
BSTree FindMax(BSTree T) {
  return T && T->rchild ? FindMax(T->rchild) : T;
}
