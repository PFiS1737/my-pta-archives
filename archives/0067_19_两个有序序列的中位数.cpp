// 已知有两个等长的非降序序列S1, S2, 设计函数求S1与S2并集的中位数。
// 有序序列A_0 ,A_1 ,⋯,A_N−1 的中位数指A_(N−1)/2 的值,
// 即第⌊(N+1)/2⌋个数（A_0 为第1个数）。
//
// 输入格式:
// 输入分三行。第一行给出序列的公共长度N（0<N≤100000），
// 随后每行输入一个序列的信息，即N个非降序排列的整数。
// 数字用空格间隔。
//
// 输出格式:
// 在一行中输出两个输入序列的并集序列的中位数。

// Sample Input
// 5
// 1 3 5 7 9
// 2 3 4 5 6

// Sample Output
// 4

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> a(2 * n);
  for (int i = 0; i < 2 * n; i++) {
    cin >> a[i];
  }

  sort(a.begin(), a.end());

  cout << a[n - 1] << endl;

  return 0;
}
