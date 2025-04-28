// 给定一系列正整数，请设计一个尽可能高效的算法，查找倒数第K个位置上的数字。
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
