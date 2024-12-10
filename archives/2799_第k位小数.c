// Description
// 求a/b转换成小数后，小数点后第k位数字是多少？
// Input
// 输入三个正整数a,b,k，用一个空格分开。0<a<b<100，1<=k<=10000。
// Output
// 一个数字。

// Sample Input
// 1 2 1

// Sample Output
// 5

#include <stdio.h>

int main() {
  int a, b, k;
  scanf("%d %d %d", &a, &b, &k);

  for (int i = 0; i < k; i++) {
    a = (a % b) * 10;
  }

  printf("%d\n", a / b);
  return 0;
}
