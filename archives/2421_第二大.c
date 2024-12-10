// Description
//          输入15个整数，输出其中第二大的数。
// Input
//          输入15个整数。数据保证至少有两个不同的数字。
// Output
//          输出其中与最大值不同的第二大的数。

// Sample Input
// 1 22 31 6 15 25 6 14 1 15 97 3 20 0 97

// Sample Output
// 31

#include <stdio.h>

int main() {
  int n, count = 15;
  int biggest = -__INT_MAX__ - 1, second_biggest = -__INT_MAX__ - 1;

  while (count--) {
    scanf("%d", &n);

    if (n > biggest) {
      second_biggest = biggest;
      biggest = n;
    } else if (n == biggest) {
      // 确保与第一大的数不同
      continue;
    } else if (n > second_biggest) {
      second_biggest = n;
    }
  }

  printf("%d\n", second_biggest);

  return 0;
}
