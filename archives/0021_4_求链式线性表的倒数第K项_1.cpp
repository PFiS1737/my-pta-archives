// 给定一系列正整数，请设计一个尽可能高效的算法，查找倒数第K个位置上的数字。
// 输入首先给出一个正整数K，随后是若干非负整数，最后以一个**负整数**表示结尾（该负数不算在序列内，不要处理）。
// 输出倒数第K个位置上的数据。如果这个位置不存在，输出错误信息`NULL`。
//
// "自己骗自己~~" 解法
// 正经人谁用链表啊（

// Sample Input
// 4 1 2 3 4 5 6 7 8 9 0 -1

// Sample Output
// 7

#include <iostream>
#include <vector>

using namespace std;

int main() {
  int k;
  cin >> k;

  vector<int> arr;
  int x;
  while (cin >> x && x >= 0) {
    arr.push_back(x);
  }

  int len = arr.size();

  if (k <= 0 || k > len) {
    cout << "NULL";
  } else {
    cout << arr[len - k];
  }

  return 0;
}
