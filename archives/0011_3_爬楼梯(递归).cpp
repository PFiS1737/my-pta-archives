// 楼梯有 n 级台阶，每一步可以跨越 1 ~ 3 级台阶。请问一共有多少种上法。
// 说明：参数 step 为台阶数。函数值为爬楼梯的方法总数。

// Sample Input
// 15

// Sample Output
// 5768

// Append Code Start
#include <stdio.h>

double Climb(int step);

int main()
{
    int n;
    scanf("%d", &n);
    printf("%g\n", Climb(n));
    return 0;
}
// Append Code End

double Climb(int step) {
  return step < 0
    ? 0
    : step == 0
      ? 1
      : Climb(step - 1) + Climb(step - 2) + Climb(step - 3);

  // return step == 1
  //   ? 1
  //   : step == 2
  //     ? 2
  //     : step == 3
  //       ? 4 // 注意是 4 不是 3
  //       : Climb(step - 1) + Climb(step - 2) + Climb(step - 3);
}
