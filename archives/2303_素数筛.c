// Description
// 已知2是第一个素数，3是第二个、5是第三个……现在编程序求第k个素数是什么？所求素数均小于10000000。
//
// 根据素数定理，不超过x的素数的个数近似于x/ln(x)，根据标程测得的数据，不超过10000000的素数不到66万5千个。
//
// 建议：分配动态内存。
//
// Input
// 输入多个整数k，至EOF结束。输入不超过50个整数。
//
// -----------------------------------------------------
//
// 本题共5组测试样例，k的范围和个数满足：
//
// 第一组：k<=100，不超过10个；
//
// 第二组：k<=1000，不超过10个；
//
// 第三组：k<=10000，不超过20个；
//
// 第四组：k<=100000，不超过30个；
//
// 第五组：k<=1000000，不超过50个。
//
// Output
// 输出第k个素数。

// Sample Input
// 1
// 2
// 3
// 5
// 10
// 100
// 1000
// 10000
// 100000

// Sample Output
// 2
// 3
// 5
// 11
// 29
// 541
// 7919
// 104729
// 1299709

#include <stdio.h>
#include <stdlib.h>

#define MAX_N 10000000

int main() {
  int *primes = (int *)malloc(665000 * sizeof(int));
  int *is_prime = (int *)malloc((MAX_N + 1) * sizeof(int));

  is_prime[0] = 0;
  is_prime[1] = 0;
  for (int i = 2; i <= MAX_N; i++) {
    is_prime[i] = 1;
  }

  int n = 0;
  for (int i = 2; i <= MAX_N; i++) {
    if (is_prime[i]) {
      primes[n++] = i;
      for (long long j = (long long)i * i; j <= MAX_N; j += i) {
        is_prime[j] = 0;
      }
    }
  }

  int k;
  while (scanf("%d", &k) != EOF) {
    printf("%d\n", primes[k - 1]);
  }

  free(primes);
  free(is_prime);

  return 0;
}
