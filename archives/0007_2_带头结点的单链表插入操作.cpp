// 本题要求实现带头结点的单链表插入操作，插入成功返回1，否则返回0。

// Sample Input
// 1 2 3 4 5 6 -1
// 2
// 100

// Sample Output
// 1 100 2 3 4 5 6 

// Append Code Start
#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct LNode
{
    ElemType data;
    struct LNode *next;
}LNode,*LinkList;

LinkList Create();/* 细节在此不表 */
void print( LinkList L);
int insert_link ( LinkList L,int i,ElemType e);
 
int main()
{
    int position,insert_data;int flag;
    LinkList L = Create();
    scanf("%d",&position);
    scanf("%d",&insert_data);    
    flag=insert_link(L,position,insert_data);
    if(flag) 
    {
        print(L);
    }
    else 
    { 
        printf("Wrong Position for Insertion");
    }
    return 0;
}
void print(LinkList L)
{ 
    LinkList p;
    p=L->next;
    while (p)
    {
         printf("%d ", p->data);
         p =p->next;
    }
}
// Append Code End

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

int insert_link(LinkList L, int i, ElemType e) {
  LNode *p = L;
  while (--i && p->next) {
    p = p->next;
  }

  if (i) {
    return 0; // out of range
  }

  LNode *next = p->next;
  p->next = (LNode *)malloc(sizeof(LNode));
  if (!p->next) {
    return 0;
  }

  p->next->data = e;
  p->next->next = next;

  return 1;
}
