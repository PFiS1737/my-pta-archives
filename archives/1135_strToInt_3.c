// 函数原型：int strToInt(char str[]);
//
// 被禁用的库函数：sscanf()、atoi()、atof()、atol()、strtod()、strtold()、strtof()、strtol()、strtoul()等。
//
// Input
// 输入是多行，每行一个字符串s，至EOF结束。每个串s不超过10个字符，并且s转换后的整数不会超出int类型的表示范围。
//
// s的转换规则是：所有数字字符（"0"～"9"）和仅能出现在s首位的符号位（"+"和"-"）转换为一个十进制整数。因此，如果一个串中不含有数字字符，那么它只能是0。
//
// Output
// 输出为多行，与输入对应。每行输出是串s转换后的一个整数。

// Sample Input
// 123c34d
// 0123d34d
//
// -45e3d
// e1321

// Sample Output
// 12334
// 12334
// 0
// -453
// 1321

// Append Code
// int main() {
//   char s[MAX_STR_LEN];
//   while (gets(s) != NULL)
//     printf("%d\n", strToInt(s));
//   return 0;
// }

#include <stdio.h>

#define MAX_STR_LEN 12

int strToInt(char str[]) {
  int i, n = 0;
  int is_negative = 0;
  for (i = 0; str[i] != '\0'; i++) {
    if (str[i] < '0' || str[i] > '9') {
      if (i == 0 && (str[i] == '+' || str[i] == '-')) {
        if (str[i] == '-')
          is_negative = 1;
      }
      continue;
    }
    n = n * 10 + str[i] - '0';
  }
  return is_negative ? -n : n;
}
