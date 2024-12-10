// Description
// 利用sin的泰勒展开式求sin值。
//
//
//
// 不得使用math.h头文件及其中的库函数。
//
// Input
// 输入有多行，每行包括一个实数x和一个正整数n。
//
// Output
// 求sin(x)的泰勒展开式的前n项结果。
//
// 每行输入对应一行输出。

// Sample Input
// 1.570796326795 1
// 1.570796326795 2
// 1.570796326795 3
// 1.570796326795 4
// 1.570796326795 5
// 1.570796326795 6
// 1.570796326795 7
// 1.570796326795 8

// Sample Output
// 1.570796
// 0.924832
// 1.004525
// 0.999843
// 1.000004
// 1.000000
// 1.000000
// 1.000000

// HINT
// 注意：阶乘的结果增长非常快，很容易溢出。所以要考虑n很大时怎么办？

#include <stdio.h>

int main() {
  double x;
  int n;

  while (scanf("%lf %d", &x, &n) != EOF) {
    // 不是，哥们，为啥我不能用 sin_x 作为变量名，
    // 咋就 Invalid World 了？！！！！！！
    double result = 0.0;
    double term = x;

    for (int i = 1; i <= n; i++) {
      result += term;
      term *= -x * x / ((2 * i) * (2 * i + 1));
    }

    printf("%.6f\n", result);
  }
  return 0;
}
