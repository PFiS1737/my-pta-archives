// Description
// 求给定的正整数范围内，能够同时被4 和6 整除的数值之和。
//
// Input
// 输入2个正整数m和n，均小于1000。
//
// Output
// 由m和n形成的闭区间内，所有能够同时被4和6整除的正整数的和。

// Sample Input
// 1 12

// Sample Output
// 12

// HINT
// 注意：输入时，不保证第一个数小于第二个数。

#include <stdio.h>

int main() {
  int n, m;
  scanf("%d %d", &n, &m);

  if (n > m) {
    int temp = n;
    n = m;
    m = temp;
  }

  int sum = 0;

  int i;
  for (i = n; i <= m; i++) {
    if (i % 4 == 0 && i % 6 == 0) {
      sum += i;
    }
  }

  printf("%d\n", sum);

  return 0;
}
