// 请你用分治法实现两个查找函数，可快速找出最好成绩和最差成绩。

// Sample Input
// 5
// 2 1 9 5 7

// Sample Output
// max=9,min=1

// Append Code Start
#include <stdio.h>
#define N 100

int max(int *a,int m,int n);
int min(int *a,int m,int n);
//注意采用分治法，不使用循环语句

int main()
{
    int i, n,a[N],max_val,min_val; 
    scanf ("%d", &n); 
    for(i=0;i<n;i++)
        scanf ("%d", &a[i]); 
    max_val=max(a,0,n-1);
    min_val=min(a,0,n-1);
    printf("max=%d,min=%d", max_val,min_val);
    return 0;
}
// Append Code End


int max(int *a, int m, int n) {
  if (m >= n)
    return a[n];
  int x = max(a, m, (m + n) / 2), y = max(a, (m + n) / 2 + 1, n);
  return x > y ? x : y;
}
int min(int *a, int m, int n) {
  if (m >= n)
    return a[n];
  int x = min(a, m, (m + n) / 2), y = min(a, (m + n) / 2 + 1, n);
  return x < y ? x : y;
}
