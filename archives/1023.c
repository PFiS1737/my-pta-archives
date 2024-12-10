// Description
// 计算a+b，0<=a,b<1000。
//
// Input
// 输入有多对整数a和b组成，每对a和b占一行，a,b用空格分开。
//
// Output
// 每行输出一个a+b的值，顺序与输入对应。每个格式样例之间用一个空行分隔开。

// Sample Input
// 1 2
// 10 20
// 15 35

// Sample Output
// 3
//
// 30
//
// 50

// HINT
// 由于输出的和比空行多一个，所以全部计算放在一个循环里是不行的，必须要特殊处理开头或者结尾。

#include <stdio.h>

int main() {
  int a, b;
  int first_output = 1;

  while (scanf("%d %d", &a, &b) != EOF) {
    if (!first_output) {
      printf("\n");
    }
    printf("%d\n", a + b);
    first_output = 0;
  }

  return 0;
}
