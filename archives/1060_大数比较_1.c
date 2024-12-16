// 字符串法
//
// Description
// 求出一些整数中的最大值和最小值。
//
// Input
// 输入为多行，以EOF结束。每行为一个十进制的数字，全部由0～9组成，每行最长不超过1000个字符。有些数字会以0开头（不影响数值大小的前导0）。
//
// Output
// 输出为输入中的最大值和最小值，格式见sample。

// Sample Input
// 02
// 010
// 0012
// 012
// 23

// Sample Output
// The maximum value is : 23
// The minimum value is : 2

#include <stdio.h>
#include <string.h>

#define MAX 1000

void print_numstr(char *str) {
  int flag = 0;

  for (int i = 0; i < MAX; i++) {
    if (str[i] != '0' || flag) {
      printf("%c", str[i]);
      flag = 1;
    }
  }

  if (!flag) {
    printf("0");
  }
}

int main() {
  char str_ori[MAX + 1];
  char max[MAX + 1];
  char min[MAX + 1];

  for (int i = 0; i < MAX; i++) {
    max[i] = '0';
    min[i] = '9';
  }
  max[MAX] = '\0';
  min[MAX] = '\0';

  while (scanf("%s", str_ori) != EOF) {
    int len = strlen(str_ori);

    char str[MAX + 1];
    for (int i = 0; i < MAX - len; i++) {
      str[i] = '0';
    }
    for (int i = 0; i < len; i++) {
      str[MAX - len + i] = str_ori[i];
    }
    str[MAX] = '\0';

    if (strcmp(str, max) > 0) {
      strcpy(max, str);
    }
    if (strcmp(str, min) < 0) {
      strcpy(min, str);
    }
  }

  printf("The maximum value is : ");
  print_numstr(max);
  printf("\n");
  printf("The minimum value is : ");
  print_numstr(min);
  printf("\n");

  return 0;
}
