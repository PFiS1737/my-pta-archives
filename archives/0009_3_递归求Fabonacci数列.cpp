// 本题要求实现求Fabonacci数列项的函数。
// Fabonacci数列的定义如下：f(n)=f(n-2)+f(n-1) (n>=2), f(0)=0, f(1)=1.
// 函数f应返回第n个Fabonacci数。题目保证输入输出在长整型范围内。建议用递归实现。

// Sample Input
// 6

// Sample Output
// 8

// Append Code Start
#include <stdio.h>

int f( int n );

int main()
{
    int n;
    
    scanf("%d", &n);
    printf("%d\n", f(n));
    
    return 0;
}
// Append Code End

int f(int n) {
  static int cache[100] = {0, 1};

  if (n == 0)
    return 0;

  if (cache[n] > 0)
    return cache[n];

  cache[n] = f(n - 1) + f(n - 2);

  return cache[n];
}
