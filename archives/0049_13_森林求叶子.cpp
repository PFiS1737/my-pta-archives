// 输出森林有几个叶子节点，且格式为‘该森林叶子结点数为n!’
//
// 分别使用先序和层序完成

// Sample Input
// 1
// 1
// 1
// 0
// 0
// 1
// 0
// 0
// 1
// 1
// 1
// 0
// 0
// 1
// 0
// 0
// 0

// Sample Output
// 该森林叶子结点数为4!
// 
// 该森林叶子结点数为4!

#include <iostream>
#include <queue>
using namespace std;

typedef struct ForestNode {
  ForestNode *child;
  ForestNode *sibling;
} *Forest;

void inputForest(Forest &forest) {
  int n;
  cin >> n;
  if (!n) {
    forest = nullptr;
  } else {
    forest = new ForestNode;
    inputForest(forest->child);
    inputForest(forest->sibling);
  }
}

int leavesPreOrder(Forest forest) {
  if (!forest)
    return 0;
  if (!forest->child)
    return leavesPreOrder(forest->sibling) + 1;
  return leavesPreOrder(forest->sibling) + leavesPreOrder(forest->child);
}

int leavesLevelOrder(Forest forest) {
  if (!forest)
    return 0;

  int count = 0;
  queue<Forest> q;
  q.push(forest);

  while (!q.empty()) {
    ForestNode *node = q.front();
    q.pop();

    if (!node)
      continue;

    if (!node->child)
      count++;

    if (node->child)
      q.push(node->child);

    if (node->sibling)
      q.push(node->sibling);
  }

  return count;
}

int main() {
  Forest forest;
  inputForest(forest);
  cout << "该森林叶子结点数为" << leavesPreOrder(forest) << "!" << endl << endl;
  cout << "该森林叶子结点数为" << leavesLevelOrder(forest) << "!" << endl;
}
