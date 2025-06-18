// 在n×n的国际棋盘上放置n个皇后，使得每个皇后都不受到攻击，即任意二个皇后不能位于同行或同列或同一条斜线上。
// 解题思路：将棋盘从左至右,从上到下编号为0,...,n-1,皇后编号为0,...,n-1。设解为(x0,..., xn-1) , 皇后i放在棋盘的第i行的第xi列上。
// 约束条件为：
// 1. xi≠xj（不在一列上）
// 2. xi-i≠xj-j（不在一条斜线上）
// 3. xi+i≠xj+j（不在一条斜线上）
// 4. 2）和3）等价于：|i-j|≠|xi-xj|
// 采用回溯算法思想，解决n个皇后问题的代码如下所示，请补充函数place()的代码，要求输出n-皇后的所有可行解,输出列号(0~n-1)

// Sample Input
// 4

// Sample Output
// 1 3 0 2 
// 2 0 3 1 

// Prepend Code Start
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>
using std::cin;
using std::cout;
using std::endl;    
int n;                   //皇后个数 
bool place(int k, int i, int *x);
void nQueens(int k, int n, int *x);

int main()
{
    
    cin>>n;
       int *x = new int [n + 1];
       if(n == 2 || n==3)
       cout << "0" <<endl; 
       nQueens(0, n, x); 
     
    return 0;
}

void nQueens(int k, int n, int *x)
{
    for(int i = 0; i < n; i++)
    {
        if(place(k, i, x))
        {
           x[k] = i;
           if(k == n - 1)
           {
                 for(i = 0; i < n; i++)  cout << x[i] << " ";
                 cout << endl;
           }    
           else
              nQueens(k+1, n, x);
        } 
    } 
}

// Prepend Code End

bool place(int k, int i, int *x) {
  int xk = i;
  for (int j = 0; j < k; j++) {
    if (xk == x[j] || abs(k - j) == abs(xk - x[j]))
      return false;
  }
  return true;
}
