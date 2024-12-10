// Description
// 输入m和n，求m和n之间（包括m和n）的所有回文素数。回文素数是指该数既是素数又是回文数。
//
// Input
// 输入两个正整数m和n。
//
// Output
// 按照要求输出所有回文素数。两两之间用1个空格隔开。

// Sample Input
// 2 9

// Sample Output
// 2 3 5 7

#include <stdio.h>

int is_palindromic(int n) {
  int num = n;

  int m = 0;
  while (n > 0) {
    m = m * 10 + n % 10;
    n /= 10;
  }

  if (m == num) {
    return 1;
  } else {
    return 0;
  }
}

int is_prime(int n) {
  if (n < 2) {
    return 0;
  }

  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      return 0;
    }
  }

  return 1;
}

int main() {
  int a, b;
  scanf("%d %d", &a, &b);

  int is_first = 1;
  for (int i = a; i <= b; i++) {
    if (is_palindromic(i) && is_prime(i)) {
      if (is_first) {
        printf("%d", i);
        is_first = 0;
      } else {
        printf(" %d", i);
      }
    }
  }

  return 0;
}
