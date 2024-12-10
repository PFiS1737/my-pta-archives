// Input
// 输入分为两部分：第一部分是第一行，有N+1个整数，第一个正整数为N（N<=10000），表示后跟一个有N个元素的整数序列。
//
// 第二部分从第二行开始直到EOF结束，每行为一个整数K。
//
// Output
// 输出为多行，与输入的第2部分顺序对应，每行输出为：找到整数序列中所有值为k的整数并按从小到大输出它们的下标（范围是1～N），若找不到则输出“NOT
// FOUND”。

// Sample Input
// 10 1 2 3 2 3 4 3 3 5 0
// 1
// 2
// 3
// 5
// 10
// 100

// Sample Output
// 1
// 2 4
// 3 5 7 8
// 9
// NOT FOUND
// NOT FOUND

#include <stdio.h>

int main() {
  int n, arr[10000];
  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  int k;
  while (scanf("%d", &k) != EOF) {
    int index[10000], i = 0;

    for (int j = 0; j < n; j++) {
      if (arr[j] == k) {
        index[i++] = j;
      }
    }

    if (i == 0) {
      printf("NOT FOUND\n");
      continue;
    }

    for (int j = 0; j < i; j++) {
      if (j > 0)
        printf(" ");

      printf("%d", index[j] + 1);
    }

    printf("\n");
  }

  return 0;
}
