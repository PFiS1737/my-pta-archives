// 给定一系列正整数，请设计一个尽可能高效的算法，查找倒数第K个位置上的数字。
// 输入首先给出一个正整数K，随后是若干非负整数，最后以一个**负整数**表示结尾（该负数不算在序列内，不要处理）。
// 输出倒数第K个位置上的数据。如果这个位置不存在，输出错误信息`NULL`。
//
// 使用了一个不带头，但带尾的双向链表来实现。

// Sample Input
// 4 1 2 3 4 5 6 7 8 9 0 -1

// Sample Output
// 7

#include <iostream>

using namespace std;

typedef struct LNode {
  int data;
  LNode *next;
  LNode *prev;
} *LinkedList;

LinkedList inputList() {
  LNode *p = new LNode;
  cin >> p->data;

  int data;
  while (cin >> data && data >= 0) {
    LNode *node = new LNode;
    node->data = data;
    node->prev = p;

    p->next = node;
    p = node;
  }

  LNode *ret = new LNode;
  ret->prev = p;

  return ret;
}

int main() {
  int k;
  cin >> k;

  LinkedList list = inputList();
  while (list->prev && k--) {
    list = list->prev;
  }

  if (k > 0) {
    cout << "NULL" << endl;
  } else {
    cout << list->data << endl;
  }

  return 0;
}
