// 本题要求实现一个函数，求带头结点的单链表的表长。

// Sample Input
// 2 1 4 5 3 -1

// Sample Output
// 5

// Prepend Code Start
#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct LNode
{
    ElemType data;
    struct LNode *next;
}LNode,*LinkList;

LinkList Create();/* 细节在此不表 */

int Length ( LinkList L );

int main()
{
    LinkList L = Create();
    printf("%d\n", Length(L));
    return 0;
}
// Prepend Code End

// 补充定义
LinkList Create() {
  LinkList head = (LNode *)malloc(sizeof(LNode));
  head->next = NULL;

  LNode *p = head, *q;
  int n;
  while (scanf("%d", &n) && n != -1) {
    q = (LNode *)malloc(sizeof(LNode));
    q->data = n;
    q->next = NULL;
    p->next = q;
    p = q;
  }

  return head;
}

int Length(LinkList L) {
  int length = 0;

  while (L) {
    length++;
    L = L->next;
  }

  return length - 1;
}
