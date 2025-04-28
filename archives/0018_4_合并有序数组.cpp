// 给定2个非降序序列，要求把他们合并成1个非降序序列。
// 假设所有元素个数为N，要求算法的时间复杂度为O(N)。

// Sample Input
// 6
// 1 3 6 6 8 9
// 4
// 2 4 5 7

// Sample Output
// 1 2 3 4 5 6 6 7 8 9

#include <iostream>

using namespace std;

int main() {
  int m;
  cin >> m;
  int arr[m];
  for (int i = 0; i < m; i++) {
    cin >> arr[i];
  }

  int n;
  cin >> n;
  int arr2[n];
  for (int i = 0; i < n; i++) {
    cin >> arr2[i];
  }

  int arr3[m + n];

  int i = 0, j = 0, k = 0;

  while (i < m && j < n) {
    if (arr[i] < arr2[j]) {
      arr3[k++] = arr[i++];
    } else {
      arr3[k++] = arr2[j++];
    }
  }

  while (i < m) {
    arr3[k++] = arr[i++];
  }
  while (j < n) {
    arr3[k++] = arr2[j++];
  }

  for (int i = 0; i < m + n; i++) {
    cout << arr3[i] << " ";
  }

  return 0;
}
