// 输入分两行，分别在每行给出由若干个正整数构成的非降序序列，用−1表示序列的结尾（−1不属于这个序列）。数字用空格间隔。
// 在一行中输出合并后新的非降序链表，数字间用空格分开，结尾不能有多余空格；若新链表为空，输出`NULL`。

// Sample Input
// 1 3 5 -1
// 2 4 6 8 10 -1

// Sample Output
// 1 2 3 4 5 6 8 10

#include <iostream>

using namespace std;

typedef struct LNode {
  int data;
  LNode *next;
} *LinkedList;

LinkedList inputList() {
  LinkedList list = new LNode;
  LNode *p = list;

  int data;
  while (cin >> data && data >= 0) {
    LNode *node = new LNode;
    node->data = data;
    node->next = nullptr;

    p->next = node;
    p = node;
  }

  return list;
}

LinkedList mergeList(LinkedList l1, LinkedList l2) {
  LinkedList list = new LNode;

  LNode *i = l1->next, *j = l2->next, *p = list;

  while (i && j) {
    if (i->data < j->data) {
      p->next = i;
      i = i->next;
    } else {
      p->next = j;
      j = j->next;
    }
    p = p->next;
  }

  if (i) {
    p->next = i;
  } else if (j) {
    p->next = j;
  }

  return list;
}

void printList(LinkedList list) {
  LinkedList node = list->next;
  if (!node) {
    cout << "NULL" << endl;
    return;
  }

  cout << node->data;
  while (node->next) {
    node = node->next;
    cout << " " << node->data;
  }

  cout << endl;
}

int main() {
  LinkedList list1 = inputList();
  LinkedList list2 = inputList();

  LinkedList mergedList = mergeList(list1, list2);

  printList(mergedList);

  return 0;
}
