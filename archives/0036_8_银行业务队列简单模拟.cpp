// 设某银行有A、B两个业务窗口，且处理业务的速度不一样，其中A窗口处理速度是B窗口的2倍，
// 给定到达银行的顾客序列，请按业务完成的顺序输出顾客序列。
// 假定不考虑顾客先后到达的时间间隔，并且当不同窗口同时处理完2个顾客时，A窗口顾客优先输出。
// 输入为一行正整数，其中第1个数字N(≤1000)为顾客总数，后面跟着N位顾客的编号。
// 编号为奇数的顾客需要到A窗口办理业务，为偶数的顾客则去B窗口。数字间以空格分隔。
// 按业务处理完成的顺序输出顾客的编号。数字间以空格分隔，但最后一个编号后不能有多余的空格。

// Sample Input
// 8 2 1 3 9 4 11 13 15

// Sample Output
// 1 3 2 9 11 4 13 15

#include <iostream>
#include <queue>

using namespace std;

int main() {
  int n;
  cin >> n;

  if (n <= 0) {
    return 0;
  }

  queue<int> a;
  queue<int> b;
  while (n--) {
    int x;
    cin >> x;
    if (x % 2 == 0) {
      b.push(x);
    } else {
      a.push(x);
    }
  }

  int out[1000], i = 0;
  while (!a.empty() || !b.empty()) {
    if (!a.empty()) {
      out[i++] = a.front();
      a.pop();
      out[i++] = a.front();
      a.pop();
    }
    if (!b.empty()) {
      out[i++] = b.front();
      b.pop();
    }
  }

  cout << out[0];
  for (int j = 1; j < i; j++) {
    cout << " " << out[j];
  }

  return 0;
}
