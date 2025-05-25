// 本题要求实现对于给定的二叉树，打印后序序列中指定序号的结点。
// T是二叉树树根指针，PrintNode函数输出给定二叉树的后序序列中第n个结点，n为结点在后序序列中的序号，从1开始编号。

// Sample Input
// AB#DF##G##C##
// 2

// Sample Output
// The 2-th node in postorder is: G

// Prepend Code Start
#include <stdio.h>
#include <stdlib.h>

typedef char ElemType;
typedef struct BiTNode
{
    ElemType data;
    struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

BiTree Create();/* 细节在此不表 */
void PrintNode(BiTree T);
int n;//要打印的结点的在后序序列中的序号
int main()
{
    BiTree T = Create();
    scanf("%d", &n);
    printf("The %d-th node in postorder is: ", n);
    PrintNode(T);
    printf("\n");
    return 0;
}
// Prepend Code End

void PrintNode(BiTree T) {
  if (T) {
    PrintNode(T->lchild);
    PrintNode(T->rchild);
    n--;
    if (n == 0) {
      printf("%c", T->data);
    }
  }
}
