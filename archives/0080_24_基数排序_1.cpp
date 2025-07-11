// INFO: 逃课写法，
//       用自己的桶，
//       而不是使用题目想要你练习的链式写法
//
// 实现基数排序。

// Sample Input
// 10 3
// 278 109 063 930 589 184 505 269 008 083

// Sample Output
// 008 063 083 109 184 269 278 505 589 930

// Prepend Code Start
#include <iostream>
#define MAXNUM_KEY 8  //关键字项数的最大值 
#define RADIX 10      //关键字基数，此时是十进制整数的基数 
#define MAX_SPACE 10000 
using namespace std;

typedef struct
{ 
  char keys[MAXNUM_KEY];   //关键字 
  int next; 
}SLCell;              //静态链表的结点类型 
typedef struct
{ 
  SLCell r[MAX_SPACE];  //静态链表的可利用空间，r[0]为头结点 
  int keynum;           //记录的当前关键字个数 
  int recnum;          //静态链表的当前长度 
}SLList;              //静态链表类型 

void InitList(SLList *L)
{ 
  int i,n,keynum;     
  cin>>n>>keynum;
  (*L).keynum=keynum;
  (*L).recnum=n;
  for(i=1;i<=n;i++)
    cin>>(*L).r[i].keys;
}

void Distribute(SLCell *r,int i,int *f,int *e); 
void Collect (SLCell *r,int i,int *f,int *e);

void RadixSort(SLList &L)
{ 
   int i;
   int f[RADIX],e[RADIX];
   for(i=0;i<L.recnum;++i)  L.r[i].next=i+1; 
   L.r[L.recnum].next = 0; //将L改造为静态链表
   for(i=L.keynum-1;i>=0;i--) 
   {           
     Distribute(L.r,i,f,e); //第i趟分配
     Collect(L.r,i,f,e);    //第i趟收集
   }
}
 
void print(SLList L)
{  
  int p,flag=1;
  for(p=L.r[0].next;p;p=L.r[p].next)
  {if(flag)
   {cout<<L.r[p].keys;flag=0;}
   else
    cout<<" "<<L.r[p].keys;
   }
}

int main()
{
  SLList l;
  InitList(&l);
  RadixSort(l);
  print(l);
  return 0;
}
// Prepend Code End

#include <cstring>
#include <queue>

queue<SLCell> buckets[RADIX];

void Distribute(SLCell *r, int i, int *, int *) {
  for (int j = 1; j; j = r[j].next) {
    int k = r[j].keys[i] - '0';
    buckets[k].push(r[j]);
  }
}

void Collect(SLCell *r, int, int *, int *) {
  SLCell rr[MAX_SPACE];
  int idx = 0;

  rr[idx++].next = 1;

  for (int j = 0; j < RADIX; ++j) {
    while (!buckets[j].empty()) {
      SLCell p = buckets[j].front();
      buckets[j].pop();
      rr[idx] = p;
      rr[idx - 1].next = idx;
      idx++;
    }
  }

  rr[idx - 1].next = 0;

  memcpy(r, rr, sizeof(SLCell) * MAX_SPACE);
}
