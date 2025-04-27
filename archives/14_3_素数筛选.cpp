// 给定一个int类型的正整数n，设计时间性能尽量好的算法输出2到n之间的全部素数。
// 注意：1不是素数，2是素数。

// Sample Input
// 10

// Sample Output
//      2     3     5     7

#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<bool> p(n + 1, true);
  p[0] = p[1] = false;

  for (int i = 2; i * i <= n; ++i) {
    if (p[i]) {
      for (int j = i * i; j <= n; j += i) {
        p[j] = false;
      }
    }
  }

  for (int i = 2; i <= n; ++i) {
    if (p[i]) {
      printf("%6d", i);
    }
  }

  cout << endl;
}
