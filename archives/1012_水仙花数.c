// Description
// 如果一个三位十进制数等于其各位数字的立方和，则称这个数为水仙花数。如：13+53+33=153。
//
// Input
// 一个整数x，100<=x<=999。
//
// Output
// x是水仙花数，则输出“YES”，否则为“NO”。

// Sample Input
// 153

// Sample Output
// YES

#include <stdio.h>

int main() {
  int n;
  scanf("%d", &n);

  int a = n / 100;
  int b = n / 10 % 10;
  int c = n % 10;

  if (a * a * a + b * b * b + c * c * c == n) {
    puts("YES");
  } else {
    puts("NO");
  }

  return 0;
}
