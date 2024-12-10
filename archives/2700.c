// Description
// 输入n个字符串，对于这些字符串查找其中的最大字母，在该字母后面插入字符”1”。
//
// Input
// 第一行输入整数n（1<=n<=10），接下来几行每行输入一个由不重复的小写英文字母组成的字符串（字符串长度均小于20）。
//
// Output
// 对每个字符串查找其中的最大字母，在该字母后面插入字符”1”，然后输出，每个输出占一行。

// Sample Input
// 2
// march
// june

// Sample Output
// mar1ch
// ju1ne

#include <stdio.h>

int main() {
  int n;
  scanf("%d", &n);

  while (n--) {
    char str[21];
    scanf("%s", str);

    int max_idx = 0;
    for (int i = 1; str[i] != '\0'; i++) {
      if (str[i] > str[max_idx]) {
        max_idx = i;
      }
    }

    for (int i = 0; str[i] != '\0'; i++) {
      printf("%c", str[i]);
      if (i == max_idx) {
        printf("1");
      }
    }

    printf("\n");
  }

  return 0;
}
