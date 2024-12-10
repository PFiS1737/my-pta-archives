// Description
// 向标准输出上打印一些用字符组成的菱形。
//
// 请根据“Append Code”完成程序。append.c中调用了一个函数print()。
// 用C语言编写自定义类型和函数实现，函数的原型为：
//
// void print(int n,char ch);
//
// 功能：输出一个用字符ch组成的n行菱形。
//
// 函数的调用格式见“Append Code”。
//
// Input
// ﻿输入一个整数n(1=<n<=20,且n为奇数)和一个字符ch。
//
// Output
// 输出一个用字符ch组成的n行菱形

// Sample Input
// 5 *

// Sample Output
//   *
//  ***
// *****
//  ***
//   *

#include <stdio.h>
#include <stdlib.h>

void print(int n, char ch) {
  int x, y;
  n /= 2;
  for (x = -n; x <= n; x++) {
    int has_non_space = 0;
    for (y = -n; y <= n; y++) {
      if (abs(x) + abs(y) <= n) {
        printf("%c", ch);
        has_non_space = 1;
      } else {
        if (!has_non_space) {
          printf(" ");
        }
      }
    }
    printf("\n");
  }
}

int main() {
  int n;
  char ch;
  scanf("%d %c", &n, &ch);
  print(n, ch);
  return 0;
}
