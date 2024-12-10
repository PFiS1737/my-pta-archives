// Description
// 从一组数字中去掉给定的数字，输出剩下的数字。
//
// Input
// 输入为两部分，第一部分是一个给定的数字，第二部分是若干较小的数字，以0结尾。从第二部分中去掉给定的数字按输入顺序输出。
//
// Output
// 输出若干整数，每6个一行，行内每两个数字间用一个空格分隔，行尾无空格。

// Sample Input
// 6 5 6 5 6 7 8 9 8 7 6 5 4 3 2 1 2 3 4 5 6 0

// Sample Output
// 5 5 7 8 9 8
// 7 5 4 3 2 1
// 2 3 4 5 0

#include <stdio.h>

int main() {
  int n, m, i = 0;
  scanf("%d", &n);

  while (1) {
    scanf("%d", &m);
    if (m == 0) {
      printf("0");
      break;
    }

    if (m == n)
      continue;

    printf("%d", m);
    i++;

    if (i < 6) {
      printf(" ");
    } else {
      printf("\n");
      i = 0;
    }
  }

  return 0;
}
