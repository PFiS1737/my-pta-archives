// 第一行给出正整数 n (≤30)，是树中结点的个数。
// 随后两行，每行给出 n 个整数，分别对应后序遍历和中序遍历结果，数字间以空格分隔。
// 题目保证输入正确对应一棵二叉树。
// 在一行中输出Preorder: 以及该树的前序遍历结果。数字间有1个空格，行末不得有多余空格。

// Sample Input
// 7
// 2 3 1 5 7 6 4
// 1 2 3 4 5 6 7

// Sample Output
// Preorder: 4 1 3 2 6 5 7

#include <iostream>

using namespace std;

typedef struct BiTreeNode {
  int data;
  BiTreeNode *left, *right;
} *BiTree;

BiTree createBiTree(int *post, int *in, int postL, int postR, int inL, int inR) {
  if (postL > postR || inL > inR) {
    return nullptr;
  }

  BiTree node = new BiTreeNode;
  node->data = post[postR];

  int k = inL;
  while (k <= inR && in[k] != post[postR]) {
    k++;
  }

  int numLeft = k - inL;

  node->left = createBiTree(post, in, postL, postL + numLeft - 1, inL, k - 1);
  node->right = createBiTree(post, in, postL + numLeft, postR - 1, k + 1, inR);

  return node;
}

void preOrder(BiTree node) {
  if (node == nullptr) {
    return;
  }

  cout << " " << node->data;
  preOrder(node->left);
  preOrder(node->right);
}

int main() {
  int n;
  cin >> n;

  int post[n], in[n];
  for (int i = 0; i < n; i++) {
    cin >> post[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> in[i];
  }

  BiTree root = createBiTree(post, in, 0, n - 1, 0, n - 1);

  cout << "Preorder:";
  preOrder(root);
  cout << endl;

  return 0;
}
