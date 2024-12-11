// 函数原型：int strToInt(char str[]);
//
// 被禁用的库函数：sscanf()、atoi()、atof()、atol()、strtod()、strtold()、strtof()、strtol()、strtoul()等。
//
// Input
// 输入是多行，每行一个字符串s，至EOF结束。每个串s不超过10个字符，并且s转换后的整数不会超出int类型的表示范围。
//
// s的转换规则是：从第一个字符开始的前若干个连续数字字符（"0"～"9"）转换为一个无符号的十进制整数，直到第一个非数字字符为止。从第一个非数字字符开始，都是非法字符。因此，如果一个串全部都是非法字符，那么它只能是0。
//
// s为空，返回-1
//
// Output
// 输出为多行，与输入对应。每行输出是串s转换后的一个整数。

// Sample Input
// 123c
// 0123dd
//
// -45ed
// e1321

// Sample Output
// 123
// 123
// -1
// 0
// 0

// Append Code
// int main() {
//   char s[MAX_STR_LEN];
//   while (gets(s) != NULL)
//     printf("%d\n", strToInt(s));
//   return 0;
// }

#include <stdio.h>
#include <string.h>

#define MAX_STR_LEN 11

int strToInt(char str[]) {
  int i, n = 0;
  if (strlen(str) == 0) {
    return -1;
  }
  for (i = 0; str[i] != '\0'; i++) {
    if (str[i] < '0' || str[i] > '9') {
      break;
    }
    n = n * 10 + str[i] - '0';
  }
  return n;
}
