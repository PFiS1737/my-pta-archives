// 根据带虚结点的先序序列建立二叉树，再统计输出二叉树中具有度为1的结点数目。
// 测试数据有多组，处理到文件尾。
// 每组测试数据在一行中输入一个字符串（不含空格且长度不超过80），表示二叉树的先序遍历序列，其中字符*表示虚结点（对应的子树为空）。
// 对于每组测试，对所建立的二叉树，输出该二叉树中具有度为1的结点数目。
// 输出格式为：“num: d”,其中d为二叉树中具有度为1的结点数目。

// Sample Input
// HDA**C*B**GF*E***
// A*B*C*D*E*F**

// Sample Output
// num: 3
// num: 5

#include <iostream>

using namespace std;

struct BiTNode {
  char data;
  BiTNode *lchild, *rchild;
};

BiTNode *createBiTree(string &s) {
  if (s[0] == '*') {
    s = s.substr(1);
    return nullptr;
  }
  BiTNode *p = new BiTNode;
  p->data = s[0];
  s = s.substr(1);
  p->lchild = createBiTree(s);
  p->rchild = createBiTree(s);
  return p;
}

int count1(BiTNode *T) {
  if (!T)
    return 0;

  if (T->lchild && !T->rchild)
    return 1 + count1(T->lchild);
  else if (!T->lchild && T->rchild)
    return 1 + count1(T->rchild);
  else
    return count1(T->lchild) + count1(T->rchild);

  // NOTE: 或这样
  // return ((!!T->lchild ^ !!T->rchild) ? 1 : 0) + count1(T->lchild) + count1(T->rchild);
}

int main() {
  string s;
  while (cin >> s) {
    cout << "num: " << count1(createBiTree(s)) << endl;
  }
  return 0;
}
