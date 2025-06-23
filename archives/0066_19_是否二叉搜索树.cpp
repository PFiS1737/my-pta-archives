// 本题要求实现函数，判断给定二叉树是否二叉搜索树。
//
// 函数IsBST须判断给定的T是否二叉搜索树，即满足如下定义的二叉树：
//
// 定义：一个二叉搜索树是一棵二叉树，它可以为空。如果不为空，它将满足以下性质：
//
// 非空左子树的所有键值小于其根结点的键值。
// 非空右子树的所有键值大于其根结点的键值。
// 左、右子树都是二叉搜索树。
//
// 如果T是二叉搜索树，则函数返回true，否则返回false。

// Sample Input
// 如图

// Sample Output
// Yes

// Prepend Code Start
#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode{
    ElementType Data;
    BinTree Left;
    BinTree Right;
};

BinTree BuildTree(); /* 由裁判实现，细节不表 */
bool IsBST ( BinTree T );

int main()
{
    BinTree T;

    T = BuildTree();
    if ( IsBST(T) ) printf("Yes\n");
    else printf("No\n");

    return 0;
}
// Prepend Code End

bool IsBST(BinTree T) {
  if (!T || (!T->Left && !T->Right))
    return true;

  if (!IsBST(T->Left) || !IsBST(T->Right))
    return false;

  BinTree left = T->Left;
  while (left) {
    if (left->Data >= T->Data)
      return false;
    left = left->Right;
  }
  BinTree right = T->Right;
  while (right) {
    if (right->Data <= T->Data)
      return false;
    right = right->Left;
  }

  return true;
}
