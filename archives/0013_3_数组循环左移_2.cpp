// 本题要求实现对数组的循环左移：一个数组中有n个int型整数（n>0），设计算法将每个整数循环左移m（m>=0）个位置。
// 要求算法的时间复杂度和空间复杂度尽量最优。
//
// 本解使用额外辅助空间 + memcpy，时间 O(1)，空间 O(n)
//
// PTA 提交过不了，报内存了

// Sample Input
// 8 3
// 1 2 -3 4 5 6 7 8

// Sample Output
// 4 5 6 7 8 1 2 -3

#include <cstring>
#include <iostream>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  int arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  m = m % n;

  int tmp[n];

  memcpy(tmp, arr + m, sizeof(int) * (n - m));
  memcpy(tmp + (n - m), arr, sizeof(int) * m);

  memcpy(arr, tmp, sizeof(int) * n);

  cout << arr[0];
  for (int i = 1; i < n; i++) {
    cout << " " << arr[i];
  }
}
