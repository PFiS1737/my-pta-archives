// Description
// 输入若干个正整数n，输出n位的同构数。
//
// Input
// 输入有多行，每行是一个正整数。
//
// Output
// 输出也有多行。每行输入对应一样输出。每行输出是相应输入值作为位数的同构数。每行输出有多个数时，两两之间用一个空格隔开。

// Sample Input
// 1
// 2
// 3

// Sample Output
// 1 5 6
// 25 76
// 376 625

#include <math.h>
#include <stdio.h>

int is_isomorphism(int n) {
  int k = 1;
  while (k <= n) {
    k *= 10;
  }

  if (n * n % k == n) {
    return 1;
  }

  return 0;
}

int main() {
  int n;

  while (scanf("%d", &n) != EOF) {
    int is_first = 1;
    for (int i = pow(10, n - 1); i < pow(10, n); i++) {
      if (is_isomorphism(i)) {
        if (is_first) {
          printf("%d", i);
          is_first = 0;
        } else {
          printf(" %d", i);
        }
      }
    }
    printf("\n");
  }

  return 0;
}
