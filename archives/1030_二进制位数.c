// Description
// 求一个十进制整数的二进制位数。
//
// Input
// 输入一个整数n，0<=n<2^31。
//
// Output
// 输出n的二进制位数

// Sample Input
// 7

// Sample Output
// 3

#include <stdio.h>

int main() {
  unsigned int n;
  int bit = 0;

  scanf("%u", &n);

  if (n == 0) {
    printf("1\n");
    return 0;
  }

  while (n > 0) {
    bit++;
    n >>= 1;
  }

  printf("%d\n", bit);

  return 0;
}
