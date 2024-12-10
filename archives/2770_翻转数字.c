// Description
// 从标准输入上读入正整数 n，使用递归函数逆序输出 n 的各位数字。逆序后不输出前导 0。
//
// 禁用关键字：for、while。
//
// Input
// 一行，一个正整数 n。保证在 int 范围内。
//
// Output
// 一行，一个整数，表示翻转之后的 n。

// Sample Input
// 1020300

// Sample Output
// 30201

#include <stdio.h>

void inverse(int n) {
  static int after_zero = 0;

  if (after_zero || n % 10 != 0) {
    printf("%d", n % 10);
    after_zero = 1;
  }

  if (n / 10 != 0)
    inverse(n / 10);
}

int main() {
  int n;
  scanf("%d", &n);
  inverse(n);
  return 0;
}
