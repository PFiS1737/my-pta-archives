// 本题要求实现顺序表元素的增、删、查找以及顺序表输出共4个基本操作函数。
// L是一个顺序表，函数Status ListInsert_Sq(SqList &L, int pos, ElemType e)是在顺序表的pos位置插入一个元素e（pos应该从1开始），
// 函数Status ListDelete_Sq(SqList &L, int pos, ElemType &e)是删除顺序表的pos位置的元素并用引用型参数e带回（pos应该从1开始），
// 函数int ListLocate_Sq(SqList L, ElemType e)是查询元素e在顺序表的位次并返回（如有多个取第一个位置，返回的是位次，从1开始，不存在则返回0），
// 函数void ListPrint_Sq(SqList L)是输出顺序表元素(尾元素后没有空格)。实现时需考虑表满扩容的问题。

// Sample Input
// 4
// 1 1 11
// 2 2
// 3 3
// 4

// Sample Output
// 1
// 3
// 11 2 3 4 5 6 7 8 9 10

// Append Code Start
//库函数头文件包含
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>


//函数状态码定义
#define TRUE        1
#define FALSE       0
#define OK          1
#define ERROR       0
#define INFEASIBLE -1
#define OVERFLOW   -2

typedef int  Status;

//顺序表的存储结构定义
#define LIST_INIT_SIZE  100
typedef int ElemType;  //假设线性表中的元素均为整型
typedef struct{
    ElemType* base;   //存储空间基地址
    int size;       //表中元素的个数
    int capacity;     //表容量大小
}SqList;    //顺序表类型定义
Status ListInsert_Sq(SqList &L, int pos, ElemType e);
Status ListDelete_Sq(SqList &L, int pos, ElemType &e);
int ListLocate_Sq(SqList L, ElemType e);
void ListPrint_Sq(SqList L);

//结构初始化与销毁操作
Status InitList_Sq(SqList &L){
  //初始化L为一个空的有序顺序表
    L.base=(ElemType *)malloc(LIST_INIT_SIZE*sizeof(ElemType));
    if(!L.base)exit(OVERFLOW);
    L.capacity=LIST_INIT_SIZE;
    L.size=0;
    return OK;
}


int main() {
    SqList L;

    if(InitList_Sq(L)!= OK) {
        printf("InitList_Sq: 初始化失败！！！\n");
        return -1;
    }

    for(int i = 1; i <= 10; ++ i)
        ListInsert_Sq(L, i, i);

    int operationNumber;  //操作次数
    scanf("%d", &operationNumber);

    while(operationNumber != 0) {
        int operationType;  //操作种类
        scanf("%d", & operationType);

        if(operationType == 1) {  //增加操作
            int pos; ElemType elem;
            scanf("%d%d", &pos, &elem);
            ListInsert_Sq(L, pos, elem);
        } else if(operationType == 2) {  //删除操作
             int pos; ElemType elem;
             scanf("%d", &pos);
             ListDelete_Sq(L, pos, elem);
             printf("%d\n", elem);
        } else if(operationType == 3) {  //查找定位操作
            ElemType elem;
            scanf("%d", &elem);
            int pos = ListLocate_Sq(L, elem);
            if(pos >= 1 && pos <= L.size)
                printf("%d\n", pos);
            else
                printf("NOT FIND!\n");
        } else if(operationType == 4) {  //输出操作
            ListPrint_Sq(L);
        }
       operationNumber--;
    }
    return 0;
}
// Append Code End

Status ListInsert_Sq(SqList &L, int pos, ElemType e) {
  if (L.size == L.capacity) {
    L.base = (ElemType *)realloc(L.base, L.capacity * 2 * sizeof(ElemType));
    if (!L.base)
      exit(OVERFLOW);
    L.capacity *= 2;
  }

  for (int i = L.size; i >= pos; --i) {
    L.base[i] = L.base[i - 1];
  }

  L.base[pos - 1] = e;
  L.size++;

  return OK;
}

Status ListDelete_Sq(SqList &L, int pos, ElemType &e) {
  e = L.base[pos - 1];

  for (int i = pos; i < L.size; ++i) {
    L.base[i - 1] = L.base[i];
  }

  L.size--;

  return OK;
}

int ListLocate_Sq(SqList L, ElemType e) {
  for (int i = 0; i < L.size; ++i) {
    if (L.base[i] == e) {
      return i + 1;
    }
  }

  return 0;
}

void ListPrint_Sq(SqList L) {
  printf("%d", L.base[0]);
  for (int i = 1; i < L.size; ++i) {
    printf(" %d", L.base[i]);
  }
}
