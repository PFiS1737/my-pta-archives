// Description
// 任何一个自然数m的立方均可写成m个连续奇数之和。编写函数，输入一较小的自然数m，输出组成m^3的m个连续奇数。
//
// Input
// 输入一较小的自然数m
//
// Output
// 组成m^3的m个连续奇数

// Sample Input
// 4

// Sample Output
// 4^3 = 13 + 15 + 17 + 19

// Append Code
// int main() {
//   int m;
//   scanf("%d", &m);
//   printf("%d^3 = ", m);
//   fun(m);
//   return 0;
// }

#include <stdio.h>

void fun(int m) {
  // case: m^3 = a + (a+2) + (a+4) + ... + (a+2*(m-1))
  //           = m*a + 2*(0+1+2+3+...+m-1)
  //           = m*a + m*(m-1)
  //
  // we get: a = m*m - m + 1

  int start = m * m - m + 1;

  for (int i = 0; i < m; i++) {
    printf("%d", start + 2 * i);
    if (i < m - 1) {
      printf(" + ");
    }
  }
  printf("\n");
}
