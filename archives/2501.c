// Description
// 输入多个字符串，对其进行加密。加密规则为：
// A→Z  a→z
// B→Y  b→y
// C→X  c→x
// .....................
// 即将字符串中的第i个大写或小写英文字母变成相应的第（26-i+1）个大写或小写字母，其他字符不变。
// Input
// 先输入一个正整数n,表示后面有n个字符串（最大长度不超过100）。然后依次输入n个字符串。
// Output
// 依次输出n个加密后的字符串。

// Sample Input
// 2
// abcABC
// ABCabc

// Sample Output
// zyxZYX
// ZYXzyx

#include <stdio.h>

int main() {
  int n;
  scanf("%d", &n);

  while (n--) {
    char str[101];
    scanf("%s", str);

    for (int i = 0; str[i] != '\0'; i++) {
      if (str[i] >= 'A' && str[i] <= 'Z') {
        printf("%c", 'Z' - str[i] + 'A');
      } else if (str[i] >= 'a' && str[i] <= 'z') {
        printf("%c", 'z' - str[i] + 'a');
      }
    }

    printf("\n");
  }

  return 0;
}
