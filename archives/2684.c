// Description
//          输入若干整数，求其中所有奇数之和与所有偶数之和。
//
// Input
//          输入只包含若干整数，至EOF结束。所有运算不会超过int存储范围。
//
// Output
//          输出两个整数，分别是输入的所有奇数之和与所有偶数之和。

// Sample Input
// 1 2 3 4 5

// Sample Output
// 9 6

#include <stdio.h>

int main() {
  int num;

  int odd_sum = 0, even_sum = 0;

  while (scanf("%d", &num) != EOF) {
    if (num % 2 == 0) {
      even_sum += num;
    } else {
      odd_sum += num;
    }
  }

  printf("%d %d\n", odd_sum, even_sum);

  return 0;
}
