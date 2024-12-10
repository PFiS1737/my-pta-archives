// Description
// 找出n个数中最大的数和最小的数，并将它们的值输出出来。
//
// Input
// 输入为n+1个整数，都在int类型范围内。这些数可能用若干空格或者换行符分隔开。
//
// 输入的第1个数为n，表示后续有n个数输入。从输入的第2个数开始，求出直到第n+1个数中最大的数和最小的数。
//
// Output
// 输出为两行，格式见sample。

// Sample Input
// 3 0 1 -1

// Sample Output
// The maximum number is 1.
// The minimum number is -1.

// HINT
// 分隔符是空格还是回车都是空白符，对scanf("%d")来说没有区别；先读入n，然后用for循环就很容易控制读入n个数的过程。

#include <limits.h>
#include <stdio.h>

int main() {
  int n;
  int num;
  int max = -__INT_MAX__ - 1;
  int min = __INT_MAX__;

  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    scanf("%d", &num);

    if (num > max) {
      max = num;
    }
    if (num < min) {
      min = num;
    }
  }

  printf("The maximum number is %d.\n", max);
  printf("The minimum number is %d.\n", min);

  return 0;
}
