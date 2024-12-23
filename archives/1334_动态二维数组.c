// Description
// 把字符串按照ASCII码序的从小到大排列出来。
//
// 串的ASCII码序遵循如下递归定义：
//
// 1 两串的前n-1个字符相同，第n个字符ASCII码序小的排在前面；
// 2 只有两串的字符完全相同时，才有两串相等。
//
// 字符的ASCII码序比较可以用strcmp()函数完成。
//
// Input
// 第一行输入为一个整数N（N<=50,000），后接N行，每行一个字符串，串长不超过100,000。
//
// Output
// 输出为N行，按照字符串的ASCII码序排列，ASCII码序小的排前面。

// Sample Input
// 10
// abc
// bc
// aca
// ca
// c
// aac
// aba
// bc
// da
// ba

// Sample Output
// aac
// aba
// abc
// aca
// ba
// bc
// bc
// c
// ca
// da

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *a, const void *b) {
  return strcmp(*(char **)a, *(char **)b);
}

int main() {
  int n;
  scanf("%d", &n);
  getchar();

  char **str = (char **)malloc(n * sizeof(char *));

  for (int i = 0; i < n; i++) {
    char buffer[100001];
    if (gets(buffer)) {
      int len = strlen(buffer);
      str[i] = (char *)malloc((len + 1) * sizeof(char));
      strcpy(str[i], buffer);
    }
  }

  qsort(str, n, sizeof(char *), compare);

  for (int i = 0; i < n; i++) {
    printf("%s\n", str[i]);
    free(str[i]);
  }

  free(str);

  return 0;
}
