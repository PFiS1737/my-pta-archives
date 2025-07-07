// 本题要求实现堆排序中的筛选函数，待排序列的长度1<=n<=1000。

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
typedef SqList HeapType; 
void  CreatSqList(HeapType *L);/*待排序列建立，由裁判实现，细节不表*/ 
void HeapAdjust( HeapType  H, int s, int m);
void HeapSort( HeapType  H);
int main()
{
  HeapType L;
  int i;
  CreatSqList(&L);
  HeapSort(L);
  for(i=1;i<=L.Length;i++)
   {        
     printf("%d ",L.elem[i]);
   }
  return 0;
}
void HeapSort( HeapType  H)
{ /*堆顺序表H进行堆排序*/
  int i; KeyType rc;
  /*建立初始堆*/
  for( i=H.Length/2;i>0; i--)
   {
      HeapAdjust(H, i, H.Length);
   }
  for(i=H.Length;i>1;i--)
   {
      rc=H.elem[1];
      H.elem[1]=H.elem[i]; 
      H.elem[i]=rc;
      HeapAdjust(H, 1, i-1); 
   }
 }
// Prepend Code End

void HeapAdjust(HeapType H, int s, int m) {
  int p = s;
  while (2 * p <= m) {
    int j = 2 * p;
    if (j < m && H.elem[j] < H.elem[j + 1]) {
      j++;
    }
    if (H.elem[p] >= H.elem[j]) {
      break;
    }
    KeyType tmp = H.elem[p];
    H.elem[p] = H.elem[j];
    H.elem[j] = tmp;
    p = j;
  }
}
