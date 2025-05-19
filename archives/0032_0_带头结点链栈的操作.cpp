// 本题要求实现带头链表的栈，写出Push 、Pop函数。

// Sample Input

// Sample Output
//  3 2 1
//  3
//  2 1

// Prepend Code Start
#include <malloc.h>
#include <stdio.h>
#define OK 1
#define ERROR 0
typedef int Status;
typedef int ElemType;
typedef struct LNode
{
    ElemType data;
        struct LNode * next;
}LNode,*LinkList;

Status InitList(LinkList *L);
Status List(LinkList L);
Status Push(LinkList L,ElemType e);
Status Pop(LinkList L,ElemType *e);
int main()
{

  LinkList L;
  int x;
  InitList(&L);
  Push(L,1);Push(L,2);Push(L,3);
  List(L);
  Pop(L,&x);
  printf(" %d\n",x);
  List(L);
  return 0;
}
// Prepend Code End

// 补充定义
Status InitList(LinkList *L) {
  *L = (LinkList)malloc(sizeof(LinkList));
  return OK;
}
Status List(LinkList L) {
  LNode *p = L;
  while (L->next) {
    L = L->next;
    printf(" %d", L->data);
  }
  putchar(10);
  return OK;
}

Status Push(LinkList L, ElemType e) {
  LNode *node = (LNode *)malloc(sizeof(LNode));
  node->next = L->next;
  node->data = e;
  L->next = node;
  return OK;
}

Status Pop(LinkList L, ElemType *e) {
  *e = L->next->data;
  L->next = L->next->next;
  return OK;
}
