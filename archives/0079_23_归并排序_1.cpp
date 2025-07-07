// 本题要求实现二路归并排序中的归并操作，待排序列的长度1<=n<=1000。

// Sample Input
// 7
// 24 53 45 45 12 24 90

// Sample Output
// 12 24 24 45 45 53 90

// Prepend Code Start
// clang-format off
#include <iostream>
#include <stdlib.h>
#define MAXSIZE 1000
using namespace std;
typedef  int  ElemType;
typedef struct
{
 ElemType *r;
 int  length;
}SqList;
                                                                        
void Create_Sq(SqList &L);//建立待排序列，实现细节隐藏
void Merge(SqList L,int low,int m,int high); 

void MSort(SqList L,int low,int high)
{  /*用分治法进行二路归并排序*/ 
  int mid;
  if(low<high){/*区间长度大于1*/
    mid=(low+high)/2; /*分解*/
    MSort(L,low,mid); /*递归地对low到mid序列排序 */
    MSort(L,mid+1,high); /*递归地对mid+1到high序列排序 */ 
    Merge(L,low,mid,high);/*归并*/ 
 } 
} 
 
int main()
{
  SqList L;
  int i;
  L.r=new ElemType[MAXSIZE+1];
  L.length=0;
  Create_Sq(L);
  MSort(L,1,L.length);
  for(i=1;i<=L.length;i++)
    if(i==1) cout<<L.r[i];
    else  cout<<" "<<L.r[i];

  return 0;
}
// clang-format on
// Prepend Code End

// 补充定义
void Create_Sq(SqList &L) {
  cin >> L.length;
  for (int i = 1; i <= L.length; i++)
    cin >> L.r[i];
}

ElemType *tmp = new ElemType[MAXSIZE + 1];

void Merge(SqList L, int low, int m, int high) {
  int i = low, j = m + 1, k = low;

  while (i <= m && j <= high) {
    if (L.r[i] <= L.r[j]) {
      tmp[k++] = L.r[i++];
    } else {
      tmp[k++] = L.r[j++];
    }
  }

  while (i <= m) {
    tmp[k++] = L.r[i++];
  }
  while (j <= high) {
    tmp[k++] = L.r[j++];
  }

  copy(tmp + low, tmp + high + 1, L.r + low);
}
