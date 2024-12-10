// Input
// 输入分为两部分：第一部分是第一行，有N+1个整数，第一个正整数为N（N<=10000），表示后跟一个有N个元素的整数序列。
//
// 第二部分从第二行开始直到EOF结束，每行为一个整数i。
//
// Output
// 输出为多行，与输入的第2部分顺序对应，每行输出为：
//
// 若i>0，从输入的整数序列中找到第i个整数并输出它的值，若i<0，从输入的整数序列中找到倒数第i个整数并输出它的值，若i不在整数序列的下标范围（1～N和-N～-1）内则输出“OUT
// OF RANGE”。

// Sample Input
// 10 1 2 3 2 3 4 3 3 5 0
// 1
// -2
// 3
// -5
// 10
// 100

// Sample Output
// 1
// 5
// 3
// 4
// 0
// OUT OF RANGE

#include <stdio.h>

int main() {
  int n, arr[10000];
  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  int i;
  while (scanf("%d", &i) != EOF) {
    if (i > 0 && i <= n) {
      printf("%d\n", arr[i - 1]);
    } else if (i < 0 && i >= -n) {
      printf("%d\n", arr[i + n]);
    } else {
      printf("OUT OF RANGE\n");
    }
  }

  return 0;
}
