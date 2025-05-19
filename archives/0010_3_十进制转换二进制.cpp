// 本题要求实现一个函数，将非负整数n转换为二进制后输出。
// 函数dectobin应在一行中打印出二进制的n。建议用递归实现。

// Sample Input
// 10

// Sample Output
// 1010

// Prepend Code Start
#include <stdio.h>

void dectobin( int n );

int main()
{
    int n;
    
    scanf("%d", &n);
    dectobin(n);
    
    return 0;
}
// Prepend Code End

void dectobin(int n) {
  if (n > 1)
    dectobin(n / 2);

  putchar("01"[n % 2]); // 使用 "01" 数组来选择字符
  // putchar('0' + (n % 2));
}
