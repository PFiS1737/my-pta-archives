// Input
// 输入分为两部分：第一部分是第一行，有N+1个整数，第一个正整数为N（N<=10000），表示后跟一个有N个元素的整数序列。
//
// 第二部分从第二行开始直到EOF结束，每行为一对整数i,j。
//
// Output
// 输出为多行，与输入的第2部分顺序对应，每行输出为：
//
// 若输入的区间范围i～j（也可能是j～i）与下标范围（1～N）有重叠的部分，则按下标顺序输出其中的整数。若无重叠，则输出“OUT OF RANGE”。

// Sample Input
// 10 1 2 3 2 3 4 3 3 5 0
// 1 10
// -2 5
// 3 12
// 1 -5
// 10 1
// 100 99

// Sample Output
// 1 2 3 2 3 4 3 3 5 0
// 1 2 3 2 3
// 3 2 3 4 3 3 5 0
// 1
// 1 2 3 2 3 4 3 3 5 0
// OUT OF RANGE

#include <stdio.h>

int main() {
  int n, arr[10000];
  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  int i, j;
  while (scanf("%d %d", &i, &j) != EOF) {

    if (i > j) {
      int temp = i;
      i = j;
      j = temp;
    }

    if (i > n || j < 1) {
      printf("OUT OF RANGE\n");
      continue;
    }

    i = i < 1 ? 1 : i;
    j = j > n ? n : j;

    int is_first = 1;
    for (int k = i - 1; k < j; k++) {
      if (is_first) {
        printf("%d", arr[k]);
        is_first = 0;
      } else {
        printf(" %d", arr[k]);
      }
    }

    printf("\n");
  }

  return 0;
}
