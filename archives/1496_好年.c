// Description
// 2013是1987年之后第一个Beautiful
// Year，也就是说2013由四个不同的数字构成，现在你的任务是，给你一个数字y，请你写出第一个严格大于y的第一个数字，并且它由不同的数字组成。
//
// Input
// 输入为多组数据，每组一个整数y(1000<=y<=9000)。
//
// Output
// 每组输出占一行，为大于y的第一个Beautiful Year

// Sample Input
// 2013

// Sample Output
// 2014

#include <stdio.h>

int is_beautiful_year(int n) {
  int d[10] = {0};

  while (n > 0) {
    int m = n % 10;
    if (d[m] > 0) {
      return 0;
    }
    d[m]++;
    n /= 10;
  }
  return 1;
}

int main() {
  int n;

  while (scanf("%d", &n) != EOF) {
    while (!is_beautiful_year(++n)) {
    }

    printf("%d\n", n);
  }

  return 0;
}
