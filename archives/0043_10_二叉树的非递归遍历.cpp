// 本题要求用非递归的方法实现对给定二叉树的 3 种遍历。
// 要求 3 个函数分别按照访问顺序打印出结点的内容，格式为一个空格跟着一个字符。
// 此外，裁判程序中给出了堆栈的全套操作，可以直接调用。

// Sample Input
// 如图

// Sample Output
// Inorder: D B E F A G H C I
// Preorder: A B D F E C G H I
// Postorder: D E F B H G I C A

// Prepend Code Start
#include <stdio.h>
#include <stdlib.h>

typedef char ElementType;
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode{
    ElementType Data;
    BinTree Left;
    BinTree Right;
    int flag;
};

/*------堆栈的定义-------*/
typedef Position SElementType;
typedef struct SNode *PtrToSNode;
struct SNode {
    SElementType Data;
    PtrToSNode Next;
};
typedef PtrToSNode Stack;

/* 裁判实现，细节不表 */
Stack CreateStack();
bool IsEmpty( Stack S );
bool Push( Stack S, SElementType X );
SElementType Pop( Stack S ); /* 删除并仅返回S的栈顶元素 */
SElementType Peek( Stack S );/* 仅返回S的栈顶元素 */
/*----堆栈的定义结束-----*/

BinTree CreateBinTree(); /* 裁判实现，细节不表 */
void InorderTraversal( BinTree BT );
void PreorderTraversal( BinTree BT );
void PostorderTraversal( BinTree BT );

int main()
{
    BinTree BT = CreateBinTree();
    printf("Inorder:");    InorderTraversal(BT);    printf("\n");
    printf("Preorder:");   PreorderTraversal(BT);   printf("\n");
    printf("Postorder:");  PostorderTraversal(BT);  printf("\n");
    return 0;
}
// Prepend Code End

void InorderTraversal(BinTree BT) {
  Stack S = CreateStack();
  BinTree T = BT;

  while (T || !IsEmpty(S)) {
    while (T) {
      Push(S, T);
      T = T->Left;
    }

    T = Pop(S);
    printf(" %c", T->Data);
    T = T->Right;
  }
}

void PreorderTraversal(BinTree BT) {
  Stack S = CreateStack();
  BinTree T = BT;

  while (T || !IsEmpty(S)) {
    while (T) {
      printf(" %c", T->Data);
      Push(S, T);
      T = T->Left;
    }

    T = Pop(S);
    T = T->Right;
  }
}

void PostorderTraversal(BinTree BT) {
  Stack S = CreateStack();
  BinTree T = BT;

  while (T || !IsEmpty(S)) {
    while (T) {
      T->flag = 0; // INFO: 0 表示左右子树尚未访问
      Push(S, T);
      T = T->Left;
    }

    T = Peek(S);

    if (T->flag == 0) {
      T->flag = 1; // INFO: 1 表示左子树访问完毕，准备访问右子树
      T = T->Right;
    } else {
      printf(" %c", T->Data);
      Pop(S);
      T = NULL;
    }
  }
}
