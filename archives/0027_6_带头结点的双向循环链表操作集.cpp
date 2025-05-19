// 本题要求实现一个带头结点的双向循环链表操作集。

// Sample Input
// 10 20 10 10 20 30 0
// 20
// 10

// Sample Output
// 10 20 10 10 20 30 
// 30 20 10 10 20 10 
// 10 10 10 20 30 
// 30 20 10 10 10 
// 20 30 
// 30 20 

// Prepend Code Start
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int dataType;

typedef struct _node
{
    dataType data;
    struct _node *prev;//指向前驱的指针
    struct _node *next;//指向后继的指针
}node;

typedef node* List;

//创建一个空的循环链表，返回指向头节点的指针。
List create_list();
//用尾插法向链表L中插入数据域等于x的结点
void insert(List L, dataType x);
//如果链表为空，则返回true,否则返回false。
bool is_empty(List L);
//顺序遍历链表L。输出所有结点的数据域。如果链表为空则输出NULL
void traverse(List L);
//逆序遍历链表L。输出所有结点的数据域。如果链表为空则输出NULL
void traverse_back(List L);
//返回第1个指向数据域等于x的结点的指针。如果没有则返回NULL。
node* search(List L, dataType x);
//删除指针p指向的结点。调用者保证p是合法的。
//返回p指向结点后继结点的指针。
//若p指向链表最后一个结点，返回指向头结点的指针。
node* delete_node(List L, node* p);
//删除链表L中所有数据域等于x的结点
void remove_node(List L, dataType x);
//使链表L成为一个空链表
void make_empty(List L);
//销毁链表L
void destroy_list(List L);

int main()
{
    int x;
    List mylist = create_list();
    //输入一系列正整数，输入0表示输入结束
    //用尾插法插入链表
    scanf("%d", &x);
    while (x != 0)
    {
        insert(mylist, x);
        scanf("%d", &x);
    }
    //顺序遍历链表
    traverse(mylist);
    //逆序遍历链表
    traverse_back(mylist);
    //输入要删除的结点数据域
    scanf("%d", &x);
    node *p = search(mylist, x);
    if (p != NULL)
    {
        delete_node(mylist, p);
    }
    //顺序遍历链表
    traverse(mylist);
    //逆序遍历链表
    traverse_back(mylist);
    //输入要删除的结点数据域
    scanf("%d", &x);
    remove_node(mylist, x);
    //顺序遍历链表
    traverse(mylist);
    //逆序遍历链表
    traverse_back(mylist);
    //销毁链表
    destroy_list(mylist);
    return 0;
}
// Prepend Code End


#define NEW(ty) ((ty *)malloc(sizeof(ty)))

List create_list() {
  List L = NEW(node);
  make_empty(L);
  return L;
}

node *tail = NULL;
void insert(List L, dataType x) {
  tail = tail ? tail : L;

  node *p = NEW(node);
  p->data = x;
  p->next = tail->next;
  p->prev = tail;

  tail->next->prev = p;
  tail->next = p;

  tail = p;
}

bool is_empty(List L) {
  return L->next == L;
}

void traverse(List L) {
  if (is_empty(L)) {
    puts("NULL");
    return;
  }

  node *p = L;

  while (p->next != L) {
    p = p->next;
    printf("%d ", p->data);
  }

  putchar(10);
}

void traverse_back(List L) {
  if (is_empty(L)) {
    puts("NULL");
    return;
  }

  node *p = L;

  while (p->prev != L) {
    p = p->prev;
    printf("%d ", p->data);
  }

  putchar(10);
}

node *search(List L, dataType x) {
  node *p = L;

  while (p->next != L) {
    p = p->next;
    if (p->data == x) {
      return p;
    }
  }

  return NULL;
}

node *delete_node(List _, node *p) {
  node *next = p->next;

  p->prev->next = p->next;
  p->next->prev = p->prev;
  free(p);

  return next;
}

void remove_node(List L, dataType x) {
  node *p = L;

  while (p->next != L) {
    p = p->next;
    if (p->data == x) {
      delete_node(L, p);
    }
  }
}

void make_empty(List L) {
  L->next = L;
  L->prev = L;
}

void destroy_list(List L) {
  node *p = L;

  while (p->next != L) {
    p = p->next;
    delete_node(L, p);
  }
}
