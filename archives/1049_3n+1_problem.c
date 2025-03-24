// Description
// 计算机科学中的问题往往被归纳为某一类问题（如NP问题，无法解决问题，递归等）。在这道问题中你将分析一种算法，它对所有可能的输入结果是未知的。
//
// 考虑以下算法：
//    1. 输入n
//    2. 输出n
//    3. 如果n=1然后停止
//    4. 如果n是奇数： n <-- n*3+1
//    5. 其他的情况：   n <-- n/2
//    6. 转向 2
//
// 例如：对于输入22，输出将会是22 11 34 17 52 26 13 40 20 10 5 16 8 4 2 1。据推测，该算法对于任何整数将终止于1。尽管算法很简单，目前还不清楚这一猜想是否正确。但是对于所有整数n(0<n<1,000,000)，已经过验证（事实上，符合规律的数比这还要多）。
//
// 对于给定的n，是有可能计算出该算法共输出了多少个数的，包括结尾的1，这个数叫做n的周期长度。在上面的例子中，22的周期长度是16。对于任何两个数字i和j，求出在i和j之间的数中，周期长度最大的那个数的周期长度。
// Input
// 输入将包括一系列的整数对i和j，每行一对整数。所有整数将少于1000000 且大于0。你应该处理i和j（包括i,j） 之间的所有整数。可以假设，任何操作不会溢出32位整数。
// Output
// 对于每一个对输入整数i和j，输出为i、j和最大周期长度。这三个数用空格分开，三个数在同一行，每两个数之间有一个空格。

// Sample Input
// 1 10
// 100 200
// 201 210
// 900 1000

// Sample Output
// 1 10 20
// 100 200 125
// 201 210 89
// 900 1000 174

#include <stdio.h>

#define MAXN 1000000

int cache[MAXN] = {0};

int get_t(int n) {
  if (n < MAXN && cache[n] != 0) {
    return cache[n];
  }

  long long curr = n;
  int t = 1;
  while (curr != 1) {
    if (curr < MAXN && cache[curr] != 0) {
      t += cache[curr] - 1;
      break;
    }

    if (curr % 2 == 0) {
      curr /= 2;
    } else {
      curr = 3 * curr + 1;
    }

    t++;
  }

  if (n < MAXN) {
    cache[n] = t;
  }

  return t;
}

int main() {
  int m, n;
  while (scanf("%d %d", &m, &n) != EOF) {
    int start = m < n ? m : n;
    int end = m > n ? m : n;

    int max = 0;
    for (int i = start; i <= end; i++) {
      int t = get_t(i);
      if (t > max) {
        max = t;
      }
    }

    printf("%d %d %d\n", m, n, max);
  }

  return 0;
}
