//  函数原型：int strToInt(char str[], int base);
//
// 被禁用的库函数：sscanf()、atoi()、atof()、atol()、strtod()、strtold()、strtof()、strtol()、strtoul()等。
//
// Input
// 输入是多行，至EOF结束。每行包括两部分，用一个冒号“:”分隔开。第一部分是个整数base，表示base进制，base可以为2、8、10、16。第二部分一个字符串s。每个串s都远少于100个字符，并且s转换后的十进制整数不会超出int类型的表示范围。
//
// s的转换规则是：所有base进制的合法字符和仅能出现在s首位的符号位（"+"和"-"）转换为一个十进制整数。因此，如果一个串s不含有base进制的合法字符，那么它只能是0。
//
// 2进制合法字符："0"、"1"；
// 8进制合法字符："0"～"7"；
// 10进制合法字符："0"～"9"；
// 16进制合法字符："0"～"9"，"A"～"F"（不区分大小写，"a"～"f"也可以），"A"～"F"的十进制数值为10～15。
//
// Output
// 输出为多行，与输入对应。每行输出是串s转换后的一个整数。

// Sample Input
// 2:111ad4d
// 8:-10987ee
// 10:+9a3d
// 16:-3Appf1
// 16:-a123-4

// Sample Output
// 7
// -71
// 93
// -15089
// -660020

// Append Code
// int main() {
//   int base;
//   char s[MAX_STR_LEN];
//   while ((scanf("%d:", &base) != EOF) && (gets(s) != NULL))
//     printf("%d\n", strToInt(s, base));
//   return 0;
// }

#include <ctype.h>
#include <stdio.h>

#define MAX_STR_LEN 101

int strToInt(char str[], int base) {
  int sign = 1;
  int i = 0;

  if (str[i] == '+') {
    i++;
  } else if (str[i] == '-') {
    sign = -1;
    i++;
  }

  int result = 0;
  int is_valid = 0;

  while (str[i] != '\0') {
    char c = toupper(str[i++]);
    int digit = -1;

    if ('0' <= c && c <= '9') {
      digit = c - '0';
    } else if ('A' <= c && c <= 'F') {
      digit = c - 'A' + 10;
    }

    if (digit >= 0 && digit < base) {
      is_valid = 1;
      result = result * base + digit;
    } else {
      continue;
    }
  }

  if (!is_valid) {
    return 0;
  }

  return sign * result;
}
