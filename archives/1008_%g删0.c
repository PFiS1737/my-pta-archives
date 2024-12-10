// Description
// 求整型数据和浮点型数据的绝对值。
//
// Input
// 输入两个数，第一个是整数，第二个是浮点数。
//
// Output
// 输出为两行，第一行为整数的绝对值，第二行为浮点数的绝对值，注意浮点数的绝对值不输出无意义的0。

// Sample Input
// -1
// 1

// Sample Output
// 1
// 1

#include <math.h>
#include <stdio.h>

int main() {
  double a, b;
  scanf("%lf", &a);
  scanf("%lf", &b);

  printf("%lg\n%lg", fabs(a), fabs(b));

  return 0;
}
