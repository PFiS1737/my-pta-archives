// Description
// 求1!+2!+…+k!=?，并判断是否溢出。
//
// Input
// 输入为一个正整数k。
//
// Output
// 若1!+2!+…+k!的值溢出unsigned（无符号整型）的范围输出“overflow”，否则输出1!+2!+…+k!的结果。

// Sample Input
// 5

// Sample Output
// 153

// HINT
// 如果一个值溢出某个变量的数据类型存储范围，但仍然存入该变量，那么存入该变量中的值实际上是什么？

#include <stdio.h>

int main() {
  int k;
  long long factorial = 1, sum = 0;

  scanf("%u", &k);

  for (unsigned i = 1; i <= k; i++) {
    factorial *= i;
    sum += factorial;

    if (sum > ~0u) {
      printf("overflow\n");
      return 1;
    }
  }

  printf("%lld\n", sum);

  return 0;
}
