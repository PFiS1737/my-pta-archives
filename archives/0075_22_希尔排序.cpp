// 本题要求实现一趟希尔排序函数，待排序列的长度1<=n<=1000。

// Sample Input
// 10
// 5 2 4 1 8 9 10 12 3 6

// Sample Output
// 1 2 3 4 5 6 8 9 10 12 

// Prepend Code Start
#include<stdio.h>
#include<stdlib.h>
typedef  int  KeyType;
typedef  struct {                      
  KeyType *elem; /*elem[0]一般作哨兵或缓冲区*/                       
  int Length;      
}SqList;
void  CreatSqList(SqList *L);/*待排序列建立，由裁判实现，细节不表*/ 
void  ShellInsert(SqList L,int dk);
void  ShellSort(SqList L);

int main()
{
  SqList L;
  int i;
  CreatSqList(&L);
  ShellSort(L);
  for(i=1;i<=L.Length;i++)
   {        
     printf("%d ",L.elem[i]);
   }
  return 0;
}
void   ShellSort(SqList L)
{
  /*按增量序列dlta[0…t-1]对顺序表L作Shell排序,假设规定增量序列为5,3,1*/
   int k;
   int dlta[3]={5,3,1};
   int t=3;
   for(k=0;k<t;++k)
       ShellInsert(L,dlta[k]);
} 
// Prepend Code End

void ShellInsert(SqList L, int dk) {
  for (int i = dk + 1; i <= L.Length; i++) {
    L.elem[0] = L.elem[i];
    int j = i - dk;
    while (j > 0 && L.elem[j] > L.elem[0]) {
      L.elem[j + dk] = L.elem[j];
      j -= dk;
    }
    L.elem[j + dk] = L.elem[0];
  }
}
