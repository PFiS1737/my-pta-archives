// Description
// 计算S=1!+2!+3!+⋯+n!。
// 其中!表示阶乘，定义为n!=n×(n−1)×(n−2)×⋯×1。
// 例如，5!=5×4×3×2×1=120。
//
// Input
// 一个正整数n<50。
// Output
// 一个正整数S。
//
// HINT
// 测试点1～5 ： 0 < n <= 10
// 测试点6～8 ：10 < n <= 20
// 测试点9～11：20 < n <= 50

// Sample Input
// 3

// Sample Output
// 9

#include <stdio.h>

#define MAX 100

typedef int BigInt[MAX];

void bigint_add_to_big(BigInt to, BigInt from) {
  int carry = 0;
  for (int i = 0; i < MAX; i++) {
    to[i] += from[i] + carry;
    carry = to[i] / 10;
    to[i] %= 10;
  }
}

void bigint_mul_int_to_big(BigInt to, int n) {
  int carry = 0;
  for (int i = 0; i < MAX; i++) {
    to[i] = to[i] * n + carry;
    carry = to[i] / 10;
    to[i] %= 10;
  }
}

void bigint_factorial(BigInt res, int n) {
  res[0] = 1;
  for (int i = 1; i <= n; i++) {
    bigint_mul_int_to_big(res, i);
  }
}

void bigint_print(BigInt n) {
  int start = 0;
  for (int i = MAX - 1; i >= 0; i--) {
    if (n[i] != 0) {
      start = 1;
    }
    if (start) {
      printf("%d", n[i]);
    }
  }
  printf("\n");
}

int main() {
  int n;
  scanf("%d", &n);

  BigInt res = {0};

  for (int i = 1; i <= n; i++) {
    BigInt tmp = {0};
    bigint_factorial(tmp, i);
    bigint_add_to_big(res, tmp);
  }

  bigint_print(res);

  return 0;
}
