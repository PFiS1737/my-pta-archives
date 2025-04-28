// 给定两个非空集合A和B，集合的元素为30000以内的正整数，编写程序求A-B。
// 输出为一行整数，表示A-B，每个整数后一个空格，各元素按递增顺序输出。
// 若A-B为空集，则输出0，0后无空格。

// Sample Input
// 5 5
// 1 2 3 4 5
// 3 4 5 6 7

// Sample Output
// 1 2 

#include <iostream>

using namespace std;

int main() {
  int m, n;
  cin >> m >> n;
  int arr1[m], arr2[n];
  for (int i = 0; i < m; i++) {
    cin >> arr1[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> arr2[i];
  }

  int arr3[m + n];

  int i = 0, j = 0, k = 0;

  while (i < m && j < n) {
    if (arr1[i] < arr2[j]) {
      arr3[k++] = arr1[i++];
    } else if (arr1[i] == arr2[j]) {
      i++;
      j++;
    } else {
      j++;
    }
  }

  while (i < m) {
    arr3[k++] = arr1[i++];
  }

  if (k == 0) {
    cout << 0;
    return 0;
  }

  for (int i = 0; i < k; i++) {
    cout << arr3[i] << " ";
  }

  return 0;
}
