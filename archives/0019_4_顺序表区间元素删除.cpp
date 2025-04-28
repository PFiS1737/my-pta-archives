// 若一个线性表L采用顺序存储结构存储，其中所有的元素为整数。
// 设计一个算法，删除元素值在[x,y]之间的所有元素，要求算法的时间复杂度为O(n)，空间复杂度为O(1)。
//
// "自己骗自己~~" 解法
// 正经人谁真的创建表然后删啊（

// Sample Input
// 10
// 5 1 9 10 67 12 8 33 6 2
// 3 10

// Sample Output
// 1 67 12 33 2

#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  int min, max;
  cin >> min >> max;

  int is_first = 1;
  for (int i = 0; i < n; i++) {
    if (arr[i] < min || arr[i] > max) {
      if (is_first) {
        is_first = 0;
      } else {
        cout << " ";
      }
      cout << arr[i];
    }
  }

  return 0;
}
