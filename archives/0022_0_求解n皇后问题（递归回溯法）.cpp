// 在n×n的方格棋盘上，放置n个皇后，要求每个皇后不同行、不同列、不同左右对角线。
// 如下图所示是6皇后问题的一个解。
// . # . . . .
// . . . # . .
// . . . . . #
// # . . . . .
// . . # . . .
// . . . . # .

// Sample Input
// 6

// Sample Output
// (1,2)(2,4)(3,6)(4,1)(5,3)(6,5)
// (1,3)(2,6)(3,2)(4,5)(5,1)(6,4)
// (1,4)(2,1)(3,5)(4,2)(5,6)(6,3)
// (1,5)(2,3)(3,1)(4,6)(5,4)(6,2)

// Prepend Code Start
#include <stdio.h>
#include <stdlib.h>
#define N 20                    //最多皇后个数
int q[N];                        //存放各皇后所在的列号,即(i,q[i])为一个皇后位置

void dispasolution(int n)        //输出n皇后问题的一个解
{
    for (int i=1;i<=n;i++)
        printf("(%d,%d)",i,q[i]);
    printf("\n");
}

bool place(int i,int j)            //测试(i,j)位置能否摆放皇后
{
    if (i==1) return true;        //第一个皇后总是可以放置
    int k=1;
    while (k<i)            //k=1～i-1是已放置了皇后的行
    {    if ((q[k]==j) || (abs(q[k]-j)==abs(i-k)))
            return false;
        k++;
    }
    return true;
}
void queen(int i,int n);

int main()
{    int n;                    //n为存放实际皇后个数
    scanf("%d",&n);
    if (n<=20)
        queen(1,n);                //放置1～i的皇后
    return 0;
}
/* 请在这里填写答案 */
// Prepend Code End


void queen(int i, int n) {
  if (i > n)
    return dispasolution(n);

  for (int j = 1; j <= n; j++) {
    if (place(i, j)) {
      q[i] = j;
      queen(i + 1, n);
    }
  }
}
