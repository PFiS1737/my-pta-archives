// 本题要求实现快速排序的一趟划分函数，待排序列的长度1<=n<=1000。

// Sample Input
// 10
// 5 2 4 1 8 9 10 12 3 6

// Sample Output
// 1 2 3 4 5 6 8 9 10 12 

// Prepend Code Start
// clang-format off
#include<stdio.h>
#include<stdlib.h>
typedef  int  KeyType;
typedef  struct 
{                      
  KeyType *elem; /*elem[0]一般作哨兵或缓冲区*/                     
  int Length;      
}SqList;
void  CreatSqList(SqList *L);/*待排序列建立，由裁判实现，细节不表*/ 
int Partition ( SqList  L,int low,  int  high );
void Qsort ( SqList  L,int low,  int  high );
int main()
{
  SqList L;
  int i;
  CreatSqList(&L);
  Qsort(L,1,L.Length);
  for(i=1;i<=L.Length;i++)
      printf("%d ",L.elem[i]);
  return 0;
}
void Qsort ( SqList  L,int low,  int  high ) 
{ 
    int  pivotloc;
    if(low<high)
    {  
        pivotloc = Partition(L, low, high ) ;
        Qsort (L, low, pivotloc-1) ; 
        Qsort (L, pivotloc+1, high );
     }
}
// clang-format on
// Prepend Code End

// 补充定义
#include <iostream>
using namespace std;
void CreatSqList(SqList *L) {
  cin >> L->Length;
  L->elem = new KeyType[L->Length + 1];
  for (int i = 1; i <= L->Length; i++) {
    cin >> L->elem[i];
  }
}

int Partition(SqList L, int low, int high) {
  L.elem[0] = L.elem[low];
  while (low < high) {
    while (low < high && L.elem[high] >= L.elem[0]) {
      high--;
    }
    L.elem[low] = L.elem[high];
    while (low < high && L.elem[low] <= L.elem[0]) {
      low++;
    }
    L.elem[high] = L.elem[low];
  }
  L.elem[low] = L.elem[0];
  return low;
}
