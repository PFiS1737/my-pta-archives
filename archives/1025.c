// Description
// 把百分制的考试成绩转换成五级制的成绩：
//
// 90～100：Excellent
//
// 80～89：Good
//
// 70～79：Average
//
// 60～69：Pass
//
// 0～59：Failing
//
// 不在0～100之间的输入是非法数据，输出“Error”。
//
// Input
// 输入多行，每行一个整数。
//
// Output
// 输入所对应的成绩等级。

// Sample Input
// -1
// 81
// 92
// 35
// 68
// 72
// 100

// Sample Output
// Error
// Good
// Excellent
// Failing
// Pass
// Average
// Excellent

// HINT
// 用switch语句解决这个问题比较方便。

#include <stdio.h>

int main() {
  int s;

  while (scanf("%d", &s) != EOF) {
    if (s < 0 || s > 100) {
      printf("Error\n");
    } else {
      switch (s / 10) {
      case 10:
      case 9:
        printf("Excellent\n");
        break;
      case 8:
        printf("Good\n");
        break;
      case 7:
        printf("Average\n");
        break;
      case 6:
        printf("Pass\n");
        break;
      default:
        printf("Failing\n");
        break;
      }
    }
  }

  return 0;
}
