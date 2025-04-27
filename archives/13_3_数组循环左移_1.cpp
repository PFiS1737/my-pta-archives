// 本题要求实现对数组的循环左移：一个数组中有n个int型整数（n>0），设计算法将每个整数循环左移m（m>=0）个位置。
// 要求算法的时间复杂度和空间复杂度尽量最优。
//
// 本解使用经典就地顺序位移方法，时间 O(n)，空间 O(1)

// Sample Input
// 8 3
// 1 2 -3 4 5 6 7 8

// Sample Output
// 4 5 6 7 8 1 2 -3

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

  int tmp;

  //  1  2 -3  4  5  6  7  8
  //  ^     ^
  //  |_____|
  //
  // -3  2  1  4  5  6  7  8
  for (int i = 0; i < m / 2; i++) {
    tmp = arr[i];
    arr[i] = arr[m - i - 1];
    arr[m - i - 1] = tmp;
  }

  // -3  2  1  4  5  6  7  8
  //           ^  ^     ^  ^
  //           |  |_____|  |
  //           |___________|
  //
  // -3  2  1  8  7  6  5  4
  for (int i = m; i < (n + m) / 2; i++) {
    tmp = arr[i];
    arr[i] = arr[n - i + m - 1];
    arr[n - i + m - 1] = tmp;
  }

  // -3  2  1  8  7  6  5  4
  //  ^  ^  ^  ^  ^  ^  ^  ^
  //  |  |  |  |__|  |  |  |
  //  |  |  |________|  |  |
  //  |  |______________|  |
  //  |____________________|
  //
  //  4  5  6  7  8  1  2 -3
  for (int i = 0; i < n / 2; i++) {
    tmp = arr[i];
    arr[i] = arr[n - i - 1];
    arr[n - i - 1] = tmp;
  }

  cout << arr[0];
  for (int i = 1; i < n; i++) {
    cout << " " << arr[i];
  }
}
