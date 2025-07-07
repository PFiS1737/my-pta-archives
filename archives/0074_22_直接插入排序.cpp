// 本题要求实现直接插入排序函数，待排序列的长度1<=n<=1000。

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
void  InsertSort(SqList L);
int main()
{
  SqList L;
  int i;
  CreatSqList(&L);
  InsertSort(L);
  for(i=1;i<=L.Length;i++)
   {        
      printf("%d ",L.elem[i]);
    }
  return 0;
}
// Prepend Code End

void InsertSort(SqList L) {
  for (int i = 2; i <= L.Length; i++) {
    L.elem[0] = L.elem[i];
    int j = i - 1;
    while (L.elem[j] > L.elem[0]) {
      L.elem[j + 1] = L.elem[j];
      j--;
    }
    L.elem[j + 1] = L.elem[0];
  }
}
