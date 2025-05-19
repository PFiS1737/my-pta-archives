// 试实现带头结点的循环双链表插入操作。
// 在带头结点的双向链表L中第i个位置之前插入元素e，i的合法值为1≤i≤表长+1
//
// 这个题根本体现不出来**双向**，我就算插入时不更新 prior 也能过
// 而且也没有检测是否能正确处理异常（PTA 上就一个 testcase）
// 该写法没用到给的 GetElemP_DuL()

// Sample Input
// 6
// 1 3 5 7 9 11
// 3 5

// Sample Output
// 1 3 5 5 7 9 11

// Prepend Code Start
#include <iostream>
using namespace std;

typedef int Status;
typedef int ElemType;

typedef struct DuLNode {
  ElemType data;
  struct DuLNode *prior;
  struct DuLNode *next;
} DuLNode, *DuLinkList;

DuLinkList GetElemP_DuL(DuLinkList L, int i) {
  int j;
  DuLinkList p;
  p = L->next;
  j = 1;
  while (j < i && p != L) {
    p = p->next;
    ++j;
  }
  if (p == L || j > i)
    return NULL;
  return p;
}

Status ListInsert_DuL(DuLinkList &L, int i, ElemType e);
void CreateDuList(DuLinkList &L, int n); //建立循环双链表，实现细节隐藏
void print(DuLinkList &L);

int main() {
  int a;
  ElemType e;
  int n;
  DuLinkList L, p;
  cin >> n;
  CreateDuList(L, n);
  cin >> a >> e;
  ListInsert_DuL(L, a, e);
  print(L);
  return 0;
}
// Prepend Code End

// 补充定义
void CreateDuList(DuLinkList &L, int n) {
  if (n < 0)
    L = nullptr;

  DuLNode *tail = L = new DuLNode;

  while (n--) {
    DuLNode *node = new DuLNode;

    cin >> node->data;
    node->prior = tail;

    tail->next = node;
    tail = node;
  }

  tail->next = L;
  L->prior = tail;
}
void print(DuLinkList &L) {
  DuLNode *p = L;
  while (p->next != L) {
    p = p->next;
    cout << p->data << " ";
  }
}

Status ListInsert_DuL(DuLinkList &L, int i, ElemType e) {
  if (i < 1)
    return 0;

  DuLNode *p = L;
  while (--i && p->next != L) {
    p = p->next;
  }

  if (i > 0)
    return 0;

  DuLNode *node = new DuLNode;
  node->data = e;
  node->next = p->next;
  node->prior = p;

  p->next->prior = node;
  p->next = node;

  return 1;
}
