// Description
// 分别输入一个正整数的每一位数字，将它们拼接为一个正整数。
// 输入时，会输入一些非数字字符。
// 不得使用unsigned、long、double、float等关键字。
//
// Input
// 输入分两行。
// 第一行是一个正整数n，表示第二行要输入n个字符。
// 第二行有n个字符，两两之间用一个空格隔开。
//
// Output
// 将输入的n个字符中的正整数拼接成一个int类型的正整数并输出。
// 如果拼接出的数超过int类型的范围，则输出“Overflow”，否则输出这个正整数。

// Sample Input
// 5
// 1 2 a b 3

// Sample Output
// 123

// HINT
// 注意：读取字符时，scanf 或者getchar，是否会读取所有字符（如回车、空格）？如果是，那么如何处理第一行之后的换行符和第二行用于分隔的空格？

#include <ctype.h>
#include <limits.h>
#include <stdio.h>

int main() {
  int n;
  scanf("%d", &n);

  scanf("%*c"); // 跳过换行符

  char ch;
  int result = 0;

  n += n - 1; // 补充空格的数量
  while (n--) {
    scanf("%c", &ch);

    if (isdigit(ch)) { // ==>> (ch >= '0' && ch <= '9')
      int k = ch - '0';

      if (result > (INT_MAX - k) / 10) { // INT_MAX == __INT_MAX__ == 2147483647
        //         ^^^^^^^^^^^^^^^^^^^^^^
        //         |-- 计算哪个数加上 k 作为最后一位正好可能到最大值
        //             这个数在 0 <= k <= 7 时是 214748364
        //             在 k = 8, 9 时是 214748363
        printf("Overflow\n");

        return 0;
      }

      result = result * 10 + k; // 注意看上面的计算方法其实是这里的逆过程
    }
  }

  printf("%d\n", result);

  return 0;
}
