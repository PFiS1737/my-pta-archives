// 编号为 1,2,3,⋯,n 的 n 个人按照顺时针方向围坐一圈。
// 从第一个人开始按照顺时针方向从 1 开始报数，当报到指定的数 m 时，报 m 的人出列。
// 再从他顺时针方向的下一位人开始重新从 1 开始报数，报到 m 的人出列，如此下去，直到所有人都出列。
// 请设计算法用单向循环链表模拟约瑟夫问题的出列过程，输出出列的顺序。

// Sample Input
// 10 3

// Sample Output
// 3 6 9 2 7 1 8 5 10 4 

// Prepend Code Start
#include <stdio.h>
#include <stdlib.h>

typedef int ElemSet;
typedef struct ListNode *Position; /* 指针即结点位置 */
struct ListNode {
    ElemSet data;  /* 存储数据 */
    Position next; /* 线性表中下一个元素的位置 */
};
typedef struct HeadNode *List;
struct HeadNode {
    Position head; /* 单链表头指针 */
    int length;    /* 表长 */
};

List JosephusProblem( int n, int m );

void PrintList( List list )
{ /* 顺序输出链表结点数据 */
    Position p;
    
    p = list->head->next; /* p指向第1个结点 */
    while (p) {
        printf("%d ", p->data);
        p = p->next;
    }
}
int main(void)
{
    List list;
    int n, m;
    scanf("%d %d", &n, &m);
    list = JosephusProblem(n, m);
    PrintList( list );
    return 0;
}
/* 你的代码将被嵌在这里 */
// Prepend Code End


#define NEW(ty) ((ty *)malloc(sizeof(ty)))

typedef struct ListNode Node;
typedef struct HeadNode Head;

List JosephusProblem(int n, int m) {
  Node *L = NEW(Node);
  L->data = 1;
  Node *p = L;
  for (int i = 2; i <= n; i++) {
    Node *node = NEW(Node);
    node->data = i;
    p->next = node;
    p = p->next;
  }
  p->next = L;

  Node *ret = NEW(Node);
  Node *q = ret;
  while (L->next != L) {
    for (int _ = 0; _ < m - 2; _++) {
      L = L->next;
    }

    Node *next = L->next;

    Node *node = NEW(Node);
    node->data = next->data;
    q->next = node;
    q = q->next;

    L->next = next->next;
    L = L->next;

    free(next);
  }
  q->next = NEW(Node);
  q->next->data = L->data;

  List list = NEW(Head);
  list->head = ret;
  return list;
}
